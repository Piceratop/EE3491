/* Tricky tabbing adapted from snippets: tabtrick.c. 
 * This code contains a number of common C idioms apart from 
 * just printf formatting. Can you find them all? 
 */

#include <stdio.h>
#include <string.h>

#define putnum(i) putchar((i) + '0')
void draw_ruler(int length);

int main(void)
{
      char *firstname[] = { "Aloysius",   "Bob",   "Dennis",  NULL },
           *lastname[]  = { "Fuddrucker", "Stout", "Ritchie", NULL };
      int   score[]     = { -10,          70,      200,       0    },
            i, tabwidth;

      printf("%15sStudent Name%30s\n\n", "", "Test Score");
      for (i = 0; NULL != lastname[i]; ++i)
	  {
            tabwidth = 36						/* spaces to tab  */
                       -2						/* allow for ", " */
                       -strlen(lastname[i]);	/* lastname space */
            printf("%15s%s, %-*s%3d\n",
                  "", lastname[i], tabwidth, firstname[i], score[i]);
      }

	  draw_ruler(60);
}

void draw_ruler(int length)
/* Draw an ASCII ruler to measure number of characters across */
{
	int i; 

	putchar('\n');
	for (i = 0, ++length; i < length; ++i) {
		if (i == 10 * (i / 10))
			putnum(i / 10);
		else  putchar(' ');
	}

	putchar('\n');
	for (i = 0; i < length; ++i)
		putnum(i % 10);	
	putchar('\n');
}
