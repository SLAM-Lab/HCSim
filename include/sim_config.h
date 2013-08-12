
#define SIM_RESOLUTION sc_core::SC_NS

#define CLOCK_PERIOD 1 /*SC_NS*/
#define BUS_CLOCK_PERIOD 1 /*SC_NS*/
/********************************************
    COMMENT OUT FOR UNTIMED BUS MODEL
#define BUS_TIMED_MODEL
********************************************/
/********************************************
    Interrupt Handler macros
    >> Delays could be application-specific
    >> The following numbers are obtained from Linux kernel traces.
*/
#define IHANDLER_DELAY_1 (2650*CLOCK_PERIOD)
#define IHANDLER_DELAY_2 (450*CLOCK_PERIOD)
#define SHANDLER_DELAY (2800*CLOCK_PERIOD)

/********************************************
    COMMENT OUT FOR UNTIMED OS HANDSHAKE CHANNEL 
    >> Delays are application specific.
    >> The following numbers are for artificial task sets example.
*/    
#define TIMED_HANDSHAKE_CHANNEL
#define HSHK_CH_RECEIVE_DELAY (800*CLOCK_PERIOD)
#define HSHK_CH_RECEIVE_DELAY_2 (1290*CLOCK_PERIOD)
#define HSHK_CH_SEND_DELAY (1500*CLOCK_PERIOD)
/*
*********************************************/

/********************************************
    Generic interrupt controller trace enabled.    
#define GIC_TRACE_ON 
*********************************************/

/********************************************
    Interrupt handler trace enabled. 
#define INTR_TRACE_ON 
*********************************************/

/********************************************
    OS statistics report enabled. 
*/
#define OS_STATISTICS_ON 
/*********************************************/
