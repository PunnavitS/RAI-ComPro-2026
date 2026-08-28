#include <stdio.h>
#include <math.h>
#include <string.h>
 int main()
{
struct coords {
float x;
float y;
};

int i;
float distance;
struct coords dot[2];
for(i=0;i<=1;i++)
{
printf ("x%d : ", i+1);
scanf (" %f", &dot[i].x);
printf ("y%d : ", i+1);
scanf (" %f", &dot[i].y);
}
distance = sqrt(pow((dot[0].x-dot[1].x), 2)+pow((dot[0].y-dot[1].y), 2));
printf("Distance between ( %.1f, %.1f) and ( %.1f, %.1f) is %.3f unit(s)\n", dot[0].x, dot[0].y, dot[1].x, dot[1].y, distance);


return 0;
}
// cc ex03.c -lm