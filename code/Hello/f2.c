#include <stdio.h>
void convert1(int& a, int b)
{
	a = b++;
}

int main(void)
{
	double fahrenheit, celsius;
	
	int x = 3, y = 1;
	convert1(x,y);

	printf ("%d %d", x, y);

	printf("Enter a Fahrenheit temperature: ");
	scanf("%lf", &fahrenheit);
	
	celsius = fahrenheit - 32.0;
	celsius = celsius * 5.0 / 9.0;
	
	printf("That equals %f degrees Celsius.\n", celsius);

	int x = 4, y = 3;
	double a = (double) (x/y);
	printf("Test %f.\n", a);
	
	return (0);
}