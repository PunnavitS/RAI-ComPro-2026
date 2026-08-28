#include <stdio.h>
#include <math.h>
#include <string.h>
 int main()
{
struct vector {
float x;
float y;
};

int i;
float resultx, resulty;
struct vector dot[2];
printf ("u_x: ");
scanf (" %f", &dot[0].x);
printf ("u_y: ");
scanf (" %f", &dot[0].y);

printf ("v_x: ");
scanf (" %f", &dot[1].x);
printf ("v_y: ");
scanf (" %f", &dot[1].y);


resultx = dot[0].x + dot[1].x;
resulty = dot[0].y + dot[1].y;
printf("Resultant vector is equvalence to %.1fi + %.1fj\n", resultx, resulty);


return 0;
}
// cc ex04.c -lm