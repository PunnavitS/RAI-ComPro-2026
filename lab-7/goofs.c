#include <stdio.h>

int main() 

{
char kind;
int size;
int temp1 = 0, temp2 = 0, i, j; // temporary and counting variables

printf ("How many numbers would you like to sort? "); // Input the number of how many number input for sorting
scanf (" %d", &size);

int numarray[size]; // Create array to store numbers with the size of the previously input numbers

for(i=0;i<size;i++)
{ 
    printf ("Enter integer %d : ", (i+1));
    scanf (" %d", &numarray[i]);
}

printf ("Sort by descending or ascending? (a/d: a for ascending, d for descending) : "); // user choose to sort by ascending or descending
scanf (" %c", &kind);

int *Ptr = numarray;
temp1 = *Ptr;
if (kind == 'a') // bubble sort for ascending
{
    for (i = 0;i<size;i++)
    {
        for(j=1;j<size;j++)
        {
            Ptr = &numarray[j-1];
            temp1 = *Ptr;
            Ptr = &numarray[j];
            temp2 = *Ptr;
            if(temp1 > temp2)
            {
                Ptr = &numarray[j];
                *Ptr = temp1;
                Ptr = &numarray[j-1];
                *Ptr = temp2;
 
            }
        }
    }
    printf("Sorted number ascending: ");
}
else if (kind == 'd') // bubble sort for descending
{
    for (i = 0;i<size;i++)
    {
        for(j=1;j<size;j++)
        {
            Ptr = &numarray[j-1];
            temp1 = *Ptr;
            Ptr = &numarray[j];
            temp2 = *Ptr;
            if(temp1 < temp2)
            {
                Ptr = &numarray[j];
                *Ptr = temp1;
                Ptr = &numarray[j-1];
                *Ptr = temp2;
 
            }
        }
    }
    printf("Sorted number descending: ");
}
else
{
    printf("Invalid input\n"); // prevent error in case of misinput
}

if (kind == 'a' || kind == 'd')
{
    for(i=0;i<size;i++)
    {
        Ptr = &numarray[i];
        printf("%d ", *Ptr);
    }
    printf("\n");
}
return 0;
}