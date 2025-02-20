#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	double fahrenheit, celsius;
	/*
	
	printf("Enter a Fahrenheit temperature: ");
	scanf("%lf", &fahrenheit);
	
	celsius = fahrenheit - 32.0;
	celsius = celsius * 5.0 / 9.0;
	
	printf("That equals %f degrees Celsius.\n", celsius);

	int x = 4, y = 3;
	double a = (double) (x/y);
	printf("Test %f.\n", a);
	
	*/

	FILE *fp1;

	char* strFileName = "test1.txt";
	char strTest[100], strRead[100];

	fp1 = fopen(strFileName, "w");

	if(fp1 == NULL)
	{
		printf (" Error \n");
		exit(1);

	}
	int x = 4, y = 3;
	double a = (double) (x/y);
	sprintf(strTest, "%d  %d %f", x,y,a);
	
	fprintf(fp1,"%s", strTest);

	fclose(fp1);
	


	fp1 = fopen(strFileName, "r");
	if(fp1 == NULL)
	{
		printf (" Error \n");
		exit(1);

	}
	int t1, t2;
	double t3;

	while(fgets(strRead, 100, fp1))
	{
		printf(" Reading string is %s \n", strRead);

		sscanf(strRead,"%d  %d %f", &t1,&t2,&t3); 

		printf(" After sscanf Reading string is %d %d %f \n", t1, t2, t3);

	}

	fclose(fp1);

	char *pField[3];
	int nField = 3;
	char *p1;

	 p1 = strtok (strRead," ");
  	while (p1 != NULL)
  	  {
    	printf ("%s\n",p1);
    	p1 = strtok (NULL, " ");
	  }

	return 1;
}