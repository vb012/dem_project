#include<stdio.h>
#include<time.h>
#include"dem.h"

#include"platform_types.h"

Fault_Memory fm;
FILE *fp;

struct tm *t;
char timeStr[100];
time_t now;
void dem_init(void)
{
    
    fm.Event_status = Test_Not_Completed_This_Operation_Cycle;
    fm.EventId = 0;
}

Std_ReturnType Dem_SetEventStatus (Dem_EventIdType EventId,Dem_EventStatusType EventStatus)
{
    int retval;
    uint32 DTCOfEvent;
    fp = fopen("Fault_Memory.txt", "a");
    if (fp == NULL) {
        printf("File not created\n");
        retval = 1;
        return retval;
    }
    else{
    time(&now);
    t = localtime(&now);
    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", t);
    Dem_GetDTCOfEvent(fm.EventId,1,&DTCOfEvent);
    fprintf(fp,"[%s] Event_Id %d DTC %d\n",timeStr,fm.EventId,DTCOfEvent);
    retval = 0;
    fclose(fp);
    return retval;
    }

}

Std_ReturnType Dem_SetEventStatus (Dem_EventIdType EventId,Dem_EventStatusType EventStatus);

Std_ReturnType Dem_GetDTCOfEvent (
Dem_EventIdType EventId,
Dem_DTCFormatType DTCFormat,
uint32 *DTCOfEvent
)
{
    if(DTCFormat == 1 )
    {
        if(EventId == 0)
        {
            *DTCOfEvent = Over_temperature_DTC;
        }
        else if(EventId == 1)
        {
            *DTCOfEvent = Sensor_is_Open_DTC;
        }
    }
}