#include <stdio.h>
#include <math.h>
#include <string.h>
 int main()
{
struct minsec {
int min, sec;
};

int i,totmin = 0, totsec = 0;
struct minsec time[3];
for(i=0;i<3;i++)
{
printf ("Time input (m:s): ");
scanf (" %d: %d", &time[i].min, &time[i].sec);
}

for(i=0;i<3;i++)
{

    totmin = totmin+time[i].min;
    totsec = totsec+time[i].sec;
}
tsec ot= (totmin*60) + totsec;

printf ("Total time elasped: %d second(s)\n", totsec);



return 0;
}