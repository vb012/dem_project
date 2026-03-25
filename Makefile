CC = gcc 
CFLAGS = -Wall
TARGET = dem_app
#Source files 
SRCS = main.c  diagnostic_code/dem.c  application_code/temperature_monitor.c

#object files
OBJS = $(SRCS:.c=.o)

#Include files 
INCLUDES = -I diagnostic_code  -I application_code  -I platform_types

#final Build 

$(TARGET) : $(OBJS) 
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c 
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS) $(OBJS:.o=.d)

-include $(OBJS:.o=.d)