#include <stdio.h>

int main() 

{
int numarray[] = {3, 1, 2, 4, 5, 6};
int sum = 0, i;
int *Ptr = numarray;

for(i=0;i<6;i++)
{
    Ptr = &numarray[i];
  if (*Ptr % 2 == 0){
    sum += *Ptr;
}
}

printf("The sum of even numbers is: %d\n", sum);
}