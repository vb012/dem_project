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

Std_ReturnType Dem_SetEventStatus (Dem_EventIdType EventId,Dem_UdsStatusByteType EventStatus)
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
    Dem_GetDTCOfEvent(fm.EventId,1,&DTCOfEvent);
    fprintf(fp,"%d %d\n",fm.EventId,DTCOfEvent);
    retval = 0;
    fclose(fp);
    return retval;
    }

}

Std_ReturnType Dem_SetEventStatus (Dem_EventIdType EventId,Dem_UdsStatusByteType EventStatus);

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

Std_ReturnType Dem_ClearDTC (
uint8 ClientId
)
{
    uint8 retval =0;
    fp = fopen("Fault_Memory.txt", "w");
    fclose(fp);
    retval = 1;
}

Std_ReturnType Dem_GetEventUdsStatus (
Dem_EventIdType EventId,
Dem_UdsStatusByteType* UDSStatusByte
)
{
    uint8 Retval =0;
    char buffer[100];
    fp = fopen ("Fault_Memory.txt", "r");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);  // print each line
    }
    fclose(fp);
    Retval = 1;
}