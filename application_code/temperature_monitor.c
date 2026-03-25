#include<stdio.h>

#include"dem.h"

#include"platform_types.h"


void temperature_read (void)
{
    int temp_value =0;
    while(1)
    {
        printf("\nEnter temperature value : \n");
        scanf("%d",&temp_value);
        if(temp_value < 30)
        {
            printf("temperature is good\n");
        }
        else 
        {
            printf("temperature is too high\n");
            fm.Event_status = Test_failed;
            fm.Failed_event_count = 1;
            return;
        }
    }
}