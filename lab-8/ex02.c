#include <stdio.h>


float find_pal( int, int );
int num[2];



int main() 
{
int i,j,k, upperlim, lowerlim;
printf ("Enter the start and end numbers: ");
scanf (" %d %d", &num[0], &num[1]);

if (num[0] < num [1]){
upperlim = num[1];
lowerlim = num[0];
}else{
upperlim = num[0];
lowerlim = num[1];
}

printf ("The palindrome numbers within the interval [ %d, %d] are: \n", num[0], num[1]);
find_pal(upperlim, lowerlim);
printf("\n");
return 0;
}


float find_pal(int upper_lim, int lower_lim)
{
    int i;
float answer=0;

for (i = lower_lim;i<=upper_lim;i++){
int firstdigit, lastdigit;

firstdigit = i/100;
lastdigit = i - ((i/10)*10);
if (firstdigit == lastdigit){
    printf(" %d", i);
}
}
}