#include <stdio.h>
#include <math.h>
#include <string.h>
 int main()
{
struct Student {
char name[51];
int age;
};

int i,j;
struct Student name[10];
for(i=0;i<10;i++)
{
printf ("Enter name %d : ", i+1);
scanf ("%s", name[i].name);
printf ("Enter age %d : ", i+1);
scanf (" %d", &name[i].age);
}
printf ("all old ppl: \n");
for(i=0;i<10;i++)
{
    if (name[i].age > 20){
printf ("name: %s\n", name[i].name);
printf ("age : %d\n", name[i].age);
}
}


return 0;
}