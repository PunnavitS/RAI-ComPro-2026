#include <stdio.h>


float find_sum( int, int );
int num[2];


int i, upperlim, lowerlim, totnum ;
float tot, upperlim2, lowerlim2;


int main() 
{
printf ("Enter the two integers (start end): ");
scanf (" %d %d", &num[0], &num[1]);

if (num[0] < num [1]){
upperlim = num[1];
lowerlim = num[0];
}else{
upperlim = num[0];
lowerlim = num[1];
}

tot = find_sum(upperlim, lowerlim);
printf ("Sum of squares of odd numbers from %d to %d is %.0f\n", lowerlim, upperlim, tot);

return 0;
}


float find_sum(int upper_lim, int lower_lim)
{
float answer=0;
totnum = (upper_lim - lower_lim);

for (i = lower_lim;i<=upper_lim;i++){
if (i % 2 == 1){
    answer += (i*i);
}
}
return answer;
}