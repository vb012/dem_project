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
    fm.Failed_event_count = 0;
}

Std_ReturnType Dem_SetEventStatus (Dem_EventIdType EventId,Dem_EventStatusType EventStatus)
{
    int retval;
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
    fprintf(fp,"Over temperature reported on [%s] \n",timeStr);
    retval = 0;
    fclose(fp);
    return retval;
    }

}