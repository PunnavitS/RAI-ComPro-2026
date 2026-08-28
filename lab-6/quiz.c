#include <stdio.h>
#include <math.h>
#include <string.h>
 int main()

{
int AMatrix[3][3] = {{1,0,-1},{-1,2,3},{2,4,5}};
int i,j;
printf("Diagonal matrix of A = \n");

for (i = 0;i<=2;i++){
    for (j = 0;j<=2;j++){

            if (i != j){
                AMatrix[i][j] = 0;
                printf(" %d", AMatrix[i][j]);
            } else{
                printf(" %d", AMatrix[i][j]);
        }   
        }
    printf("\n");
    }
}

// cc testing.c -lm