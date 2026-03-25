#include <stdio.h> 
#include "platform_types.h"

typedef __uint8_t dem_event_type;

typedef enum 
{
    Test_failed = 0,
    Test_failed_Operation_Cycle,
    Pending_DTC,
    Conform_DTC,
    Test_Not_Completed_Since_Last_Clear,
    Test_Failed_Since_Last_Clear,
    Test_Not_Completed_This_Operation_Cycle,
    Warning_Indicator_Request

}Dem_Event_Status;

typedef struct
{
    dem_event_type Failed_event_count;
    Dem_Event_Status Event_status;
}Fault_Memory;

extern Fault_Memory fm;