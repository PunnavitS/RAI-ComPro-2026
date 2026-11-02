#include<stdio.h>
#include<math.h>
#include<string.h>

#define PI 3.14

void printname(int); /*Function Prototype*/

struct namelastname{
char name[50];
char surname[50];

};
struct namelastname fullname[3];
struct info{
struct namelastname fullname[3];
int age;


};
struct info name[3];
int number;
int main()
{
int i = 0;

for(i=0;i<3;i++)
{
printf("Student %d ",(i+1));
printf(" name:");
scanf("%s",name[i].fullname[i].name);
printf(" age:");
scanf("%d",&name[i].age);
}

printf("How many student to print?\n");
scanf("%d", &number);
printname(number);
}



void printname(int numprint){
    int n = 0;
for(n=0;n<numprint;n++)
{
printf("\n %s,%d\n",name[n].fullname[n].name,name[n].age);
} 
}