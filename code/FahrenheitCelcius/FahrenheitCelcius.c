#include <stdio.h>
#include <string.h>


int main(void)
{
	double fahrenheit, celsius;
	
	printf("Enter a Fahrenheit temperature: ");
	scanf("%lf", &fahrenheit);
	
	celsius = fahrenheit - 32.0;
	celsius = celsius * 5.0 / 9.0;
	
	printf("That equals %f degrees Celsius.\n", celsius);

	int x = 4, y = 3;
	double a = (double) (x/y);
	printf("Test %f.\n", a);

	char s[100] = " This is a      test for   count ";
	
	char state = 0;
	char count = 0;

	for (int i = 0; i < strlen(s) - 1; i ++)
	{
		if(s[i] != ' ' && state == 0  )
		{
			state = 1;
			count ++;	
		}

		if( s[i] == ' ')
		{
			state = 0;
		}
	}

	printf (" The number      of words is : %d \n", count);

	return (0);
}