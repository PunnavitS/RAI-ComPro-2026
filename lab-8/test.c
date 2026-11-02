#include<stdio.h>
#include<math.h>
#include<string.h>

#define PI 3.14

float deg_rad(float); /*Function Prototype*/

int main()
{
struct namelastname{
char name[20];
char surname[20];

};
struct namelastname fullname[3];
struct info{
struct namelastname fullname[3];
int age;


};
struct info name[3];
int i = 0;

for(i=0;i<3;i++)
{
printf("Student %d ",(i+1));
printf(" name:");
scanf("%s",name[i].fullname[i].name);
printf(" age:");
scanf("%d",&name[i].age);
}

for(i=0;i<3;i++)
{
printf("\n %s,%d\n",name[i].fullname[i].name,name[i].age);
}

float deg,rad;
/*printf ("Enter Degree : ");
scanf ("%f",&deg);
rad = deg_rad(deg); //printf ("%f->%f\n",deg,rad);
printf ("sin(%.2f) = %.3f\n",deg,sin(rad));
printf ("cos(%.2f) = %.3f\n",deg,cos(rad));
printf ("tan(%.2f) = %.3f\n",deg,tan(rad));
return 0;*/
}
float deg_rad(float num)
{
float ans;
ans = num * PI / 180;
return(ans);
}

