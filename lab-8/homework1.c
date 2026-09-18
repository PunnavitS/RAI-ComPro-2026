#include<stdio.h>
#include<math.h>

float find_area(float); /*Function Prototype*/


int main()
{

int sidearray[3];
int i;

float area;

for(i=0;i<3;i++)
{ 
    printf ("Enter side %d : ", (i+1));
    scanf (" %d", &sidearray[i]);
}
area = find_area(sidearray[0]);
return 0;
}
float find_area(float num1)
{
float ans;
return(ans);
}