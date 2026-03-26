#include<stdio.h>
#include"dem.h"
#include "platform_types.h"


int main()
{
    dem_init();
    temperature_read();
    printf("\n_________________________\nFault Memory count is %d\n Status byte value %d\n", fm.EventId,fm.Event_status);
    return 0;
}

