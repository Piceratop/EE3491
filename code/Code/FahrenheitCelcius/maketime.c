#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main (void)
{
    time_t moment;
    char *strTime;
    char strTime1[256];

    struct tm str_time;

    str_time.tm_year = 2012-1900;
	str_time.tm_mon = 6;
	str_time.tm_mday = 5;
	str_time.tm_hour = 10;
	str_time.tm_min = 3;
	str_time.tm_sec = 5;
	str_time.tm_isdst = 0;

    moment = mktime(&str_time);
    
    printf ("The current time is : %s \n", ctime(&moment));

    str_time.tm_year = 2024-1900;
	str_time.tm_mon  = 10-1;
	str_time.tm_mday = 26;
	str_time.tm_hour = 0;
	
    moment = mktime(&str_time);

    printf ("The current time is : %s \n", ctime(&moment));

    printf ("The current day of week  is %d \n", str_time.tm_wday);
    return 0;

}
