/*********************************************
 * Parisa Razaghi, UT Austin
 * Last update: July 2013 
 ********************************************/

#include "Channels/handshake_os_ch.h"
#include "OS/global_os.h"

using namespace HCSim;

handshake_os_ch::handshake_os_ch(const sc_core::sc_module_name name)
    :sc_core::sc_channel(name)
    ,forward_flag(false)
    ,wait_flag(false)
    ,blocked_task_id(OS_NO_TASK)
    ,blocking_task_id(OS_NO_TASK)
{
}

handshake_os_ch::~handshake_os_ch()
{
}

void handshake_os_ch::send(int tID)
{
    blocking_task_id = tID;
#ifdef TIMED_HANDSHAKE_CHANNEL
	os_port->timeWait(HSHK_CH_SEND_DELAY, tID);
#endif
     os_port->syncGlobalTime(tID);
    if (wait_flag) {
        os_port->preNotify(tID, blocked_task_id);
        event.notify();
        os_port->postNotify(tID, blocked_task_id);
    }
    forward_flag = true;
}

void handshake_os_ch::receive(int tID)
{
    blocked_task_id = tID;
#ifdef TIMED_HANDSHAKE_CHANNEL
	os_port->timeWait(HSHK_CH_RECEIVE_DELAY, tID);
#endif
    os_port->syncGlobalTime(tID);
    if (!forward_flag) { 
        wait_flag = true; 
        os_port->preWait(tID, blocking_task_id);
        sc_core::wait(event);
        os_port->postWait(tID);
        wait_flag = false; 
    } 
    forward_flag = false;
#ifdef TIMED_HANDSHAKE_CHANNEL    
    os_port->timeWait(HSHK_CH_RECEIVE_DELAY_2, tID);
    os_port->syncGlobalTime(tID);
#endif    
}

/*------- EOF -------*/
