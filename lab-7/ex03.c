#include <stdio.h>

int main() 

{
int numarray[] = {3, 1, 2, 4, 5, 6};
int max = 0, min = 0, temp = 0, i;
int *Ptr = numarray;

for(i=0;i<6;i++)
{
    Ptr = &numarray[i];
  if (max<*Ptr){
    max = *Ptr;
    min = *Ptr;
}
}
for(i=0;i<6;i++)
{
  Ptr = &numarray[i];
  if (min>*Ptr){
    min = *Ptr;
}
}
printf("Max value: %d\n", max);
printf("Min value: %d\n", min);
}
