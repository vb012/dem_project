#include<stdio.h>

#include"dem.h"

#include"platform_types.h"


void temperature_read (void)
{
    int temp_value =0;
    int retval = 0;
    while(1)
    {
        printf("\nEnter temperature value : \n");
        scanf("%d",&temp_value);
        if(temp_value < 30)
        {
            printf("temperature is good\n");
            // fprintf(fp,"Passed\n");
        }
        else 
        {
            printf("temperature is too high\n");                       
            retval = Dem_SetEventStatus (fm.Failed_event_count = (fm.Failed_event_count +1),fm.Event_status = Test_failed);
            if(retval == 0)
            {
                printf("\nFault registered \n");
            }
            break;
        }
    }
}