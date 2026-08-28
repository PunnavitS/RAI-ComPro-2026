#include <stdio.h>
#include <math.h>
#include <string.h>
 int main()
{
struct Student {
char name[101];
int age;
float score;
};

int i, topstudent;
float top = 0;
struct Student name[3];
for(i=0;i<3;i++)
{
printf ("Student %d\'s name : ", i+1);
scanf (" %[^\n]", name[i].name);
printf ("Student %d\'s age : ", i+1);
scanf (" %d", &name[i].age);
printf ("Student %d\'s score : ", i+1);
scanf (" %f", &name[i].score);
}

for(i=0;i<3;i++)
{
  if (top<name[i].score){
    top = name[i].score;
    topstudent = i;
}
}

printf("The highest scores belongs to %s at %.1f scores!\n", name[topstudent].name, name[topstudent].score);
/*for(i=0;i<3;i++)
{
  printf ("Student %d name is \"%s\", age %d. score %.1f\n", i+1,  name[i].name, name[i].age, name[i].score);
}*/


return 0;
}