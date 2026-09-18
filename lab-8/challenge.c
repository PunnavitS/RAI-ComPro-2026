#include <stdio.h>
#include<string.h>

float avg( void );
float findmin( void );
float findmax( void );
char findgradenpass( int );
int dimension[3];
float average, minimum, maximum;
int temparray[99999];
int size;
int maxscore, minscore, numofpass;
char grade;
int i;
struct Student {
char name[101];
};



int main() 
{

int temp1 = 0, temp2 = 0, j;

printf ("Enter number of students: ");
scanf (" %d", &size);

struct Student st[size];
int numarray[size];


for(i=0;i<size;i++)
{ 
    printf ("Enter name of student %d: ", (i+1));
    scanf  (" %s", st[i].name);
    printf ("Enter grade of student %d: ", (i+1));
    scanf (" %d", &numarray[i]);
    temparray[i] = numarray[i];
}
printf ("--- Results ---\n");
average = avg();
printf("Average grade: %.2f\n", average);
maximum = findmax();
printf("Highest grade: %.2f ( %s)\n", maximum, st[minscore].name);
minimum = findmin();
printf("Lowest grade: %.2f ( %s)\n", minimum, st[maxscore].name);

printf("Students who passed:\n");
printf(" %s - Grade %s", st[numofpass].name, findgradenpass(i));


return 0;
}

float avg(void)
{
float answer = 0;
float temp = 0;
for(i=0;i<size;i++)
{ 
        temp += temparray[i];
        answer = temp/size;

}
return answer;
}

float findmin(void)
{
float answer = temparray[0];
for(i=0;i<size;i++)
{ 
    if (answer > temparray[i]){
        answer = temparray[i];
        maxscore = i;
    }
}
return answer;
}

float findmax(void)
{
float answer = 0;
for(i=0;i<size;i++)
{ 
    if (answer < temparray[i]){
        answer = temparray[i];
        minscore = i;
    }
}
return answer;
}

float findgradenpass(i)
{
char answer;
float temp = 0;
float temp2;
for(i=0;i<size;i++)
{ 
    if (temparray[i] >= 50){
        numofpass = i;
        if (temparray[i] >= 80){
            grade = 'A';
        }
            else if(temparray[i] >= 80)
            {
            grade = 'A';
        }
            else if(temparray[i] >= 70){
            grade = 'B';}
            else if(temparray[i] >= 60){
            grade = 'C';} 
            else{
                grade = 'D';
            }
    }
    answer = grade;
}
return answer;
}