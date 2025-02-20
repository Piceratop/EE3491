// Lop: 
// Ho va ten
// MSSV: 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

int UserCompareFc(const void *input1, const void* input2) 
{
    
    if((*(int*)input1) - (*(int*)input2) < 0)
        return 0;
    else 
        return 1;

}

int StringCompareFc(const void *input1, const void* input2) 
{
    char *t1 = *(char**)input1; 
    char *t2 = *(char**)input2; 

    if(strcmp(t1, t2) <0)
        return 0;
    else
        return 1;


}


int main(int argc, char *argv[])
{
    printf("Hello World \n");

    

    int nTest[] = { 3, 8, 20, 2, 9, 3, 6, 7};

    char *strTest[] = {"Telephone", "Quick", "Test1", "test2", "Name", "SurName" };

    qsort( nTest, sizeof(nTest)/sizeof(int), sizeof(int), UserCompareFc);

    for(int i = 0; i < sizeof(nTest)/sizeof(int); i ++)
        printf(" %d", nTest[i]);

    qsort( strTest, sizeof(strTest)/sizeof(char*), sizeof(char*), StringCompareFc);

    for(int i = 0; i < sizeof(strTest)/sizeof(char*); i ++)
        printf(" %s", strTest[i]);

    return 0;
}

