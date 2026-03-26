#include <stdio.h> 
#include "platform_types.h"

#define Over_temperature_DTC 0x1100
#define Sensor_is_Open_DTC 0x1200

typedef uint8 Dem_DTCFormatType;
typedef enum 
{
 Over_temperature = 0,
 Sensor_is_Open   
}Dem_EventIdType;

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
    Dem_EventIdType EventId;
    Dem_EventStatusType Event_status;
}Fault_Memory;

extern Fault_Memory fm;
Std_ReturnType Dem_SetEventStatus (Dem_EventIdType EventId,Dem_EventStatusType EventStatus);

Std_ReturnType Dem_GetDTCOfEvent (
Dem_EventIdType EventId,
Dem_DTCFormatType DTCFormat,
uint32* DTCOfEvent
);