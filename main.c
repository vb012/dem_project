#include<stdio.h>
#include"dem.h"
#include "platform_types.h"


int main()
{
    uint8 opreation;
    printf("\n Enter which operation need to execute now\n 1.Monitor temperature \n 2.Clear fault Memory\n 3.Read data from fault memory\n");
    scanf("%d",&opreation);
    Dem_UdsStatusByteType faultdata;
    dem_init();
    if(opreation == 1)
    {
    temperature_read();
    printf("\n_________________________\nFault Memory count is %d\n Status byte value %d\n", fm.EventId,fm.Event_status);
    }
    if(opreation == 2)
    {
        Dem_ClearDTC(1);
    }
    if(opreation == 3)
    {
        Dem_GetEventUdsStatus (1,&faultdata);

    }
    
    return 0;
}

