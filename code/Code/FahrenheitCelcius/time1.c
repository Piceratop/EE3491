#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main (void)
{
    time_t moment;
    char *strTime;
    char strTime1[256];

    time(&moment);

    printf(" This is the current time %d \n", moment);

    strTime = ctime(&moment);

    strcpy(strTime1, ctime(&moment));

    
    printf(" This is the current time %s \n", strTime);

    struct tm *local = localtime(&moment);

    time_t addtime = 180*24*3600;

    moment = moment + addtime;

    strTime = ctime(&moment);

    strcpy(strTime1, ctime(&moment));

    
    printf(" This is the new current time %s \n", strTime);


    int hours = local->tm_hour;      	// get hours since midnight (0-23)
    int minutes = local->tm_min;     	// get minutes passed after the hour (0-59)
    int seconds = local->tm_sec;     	// get seconds passed after minute (0-59)

    int day = local->tm_mday;        	// get day of month (1 to 31)
    int month = local->tm_mon + 1;   	// get month of year (0 to 11)
    int year = local->tm_year + 1900;	// get year since 1900

    printf( "Current time % d %d %d \n", hours, minutes, seconds);
    printf( "Current time % d %d %d \n", year, month, day);
    
    clock_t start, end;
    start = clock();
    double y;
    for (int i = 0; i < 10000000; i++) 
        y = sin(180/2/3.14);
    end = clock();


    printf(" Time to run: %f \n", (double)(end - start));

}
