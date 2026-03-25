#include<stdio.h>

#include"dem.h"

#include"platform_types.h"

Fault_Memory fm;
void dem_init(void)
{
    
    fm.Event_status = Test_Not_Completed_This_Operation_Cycle;
    fm.Failed_event_count = 0;
}