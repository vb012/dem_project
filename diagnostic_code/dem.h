#include <stdio.h> 
#include "platform_types.h"

typedef uint8 Dem_EventIdType;

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

}Dem_EventStatusType;

typedef struct
{
    Dem_EventIdType Failed_event_count;
    Dem_EventStatusType Event_status;
}Fault_Memory;

extern Fault_Memory fm;
Std_ReturnType Dem_SetEventStatus (Dem_EventIdType EventId,Dem_EventStatusType EventStatus);