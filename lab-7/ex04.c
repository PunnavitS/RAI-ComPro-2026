#include <stdio.h>

int main()

{
    int size = 6;
    int numarray[] = {3, 1, 2, 4, 5, 6};
    int *ptr1;
    int temp[6];
    int i,j;

    for(i=0;i<size;i++)
    {
        ptr1 = &numarray[i];
        temp[i] = *ptr1;
    }
    for(i=0;i<size;i++)
    {
        ptr1 = &temp[(size-1-i)];
        numarray[i] = *ptr1;
    }
    for(i=0;i<size;i++)
    {
    printf("%d\n", numarray[i]);
    }
    return 0;

}
