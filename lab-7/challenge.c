#include <stdio.h>

int main() 

{
int size = 5;
int numarray[5];
printf ("Enter 5 integers: ");
scanf (" %d %d %d %d %d", &numarray[0], &numarray[1], &numarray[2], &numarray[3], &numarray[4]);
int temp1 = 0, temp2 = 0, i, j;
int *Ptr = numarray;
temp1 = *Ptr;
for (j = 0;j<size;j++)
{
for(i=1;i<size;i++)
{
    Ptr = &numarray[i-1];
    temp1 = *Ptr;
    Ptr = &numarray[i];git add *.c
    temp2 = *Ptr;
    if(temp1 < temp2 ){
    Ptr = &numarray[i];
        *Ptr = temp1;
    Ptr = &numarray[i-1];
        *Ptr = temp2;
 
    }
}
}

printf("Sorted descending: ");
for(i=0;i<size;i++)
{
    Ptr = &numarray[i];
  printf("%d ", *Ptr);
}
printf("\n");
}
