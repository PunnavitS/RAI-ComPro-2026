#include <stdio.h>


float sum_even( void );
float sum_odd( void );
float avg_even( void );
float avg_odd( void );
int dimension[3];
int evensum, oddsum;
float avgeven, avgodd;
int temparray[99999];
int size2;
int i;

int main() 
{
int size;
int temp1 = 0, temp2 = 0, j;

printf ("N: ");
scanf (" %d", &size);

size2 = size;

int numarray[size];

for(i=0;i<size;i++)
{ 
    printf ("Input : ");
    scanf (" %d", &numarray[i]);
    temparray[i] = numarray[i];
}
evensum = sum_even();
oddsum = sum_odd();

avgeven = avg_even();
avgodd = avg_odd();

printf ("Output :\n");
printf("Even index elements -> Sum: %d, Average: %.2f\n", evensum, avgeven);
printf("Odd index elements -> Sum: %d, Average: %.2f\n", oddsum, avgodd);


return 0;
}

float sum_even(void)
{
int answer = 0;
for(i=0;i<size2;i++)
{ 
    if (i % 2 == 1){
        answer += temparray[i];
    }
}
return answer;
}

float sum_odd(void)
{
int answer = 0;
for(i=0;i<size2;i++)
{ 
    if (i % 2 == 0){
        answer += temparray[i];
    }
}
return answer;
}

float avg_even(void)
{
float answer = 0;
float temp = 0;
for(i=0;i<size2;i++)
{ 
    if (i % 2 == 1){
        answer += temparray[i];
        temp +=1;
    }
    answer = evensum/temp;
}
return answer;
}

float avg_odd(void)
{
float answer = 0;
float temp = 0;
float temp2;
for(i=0;i<size2;i++)
{ 
    if (i % 2 == 0){
        answer += temparray[i];
        temp +=1;
    }
    answer = oddsum/temp;
}
return answer;
}
