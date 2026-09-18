#include <stdio.h>


float find_area( int, int );
float find_perimeter( int, int );
float find_vol( int, int, int );
float check_neg( int);
int dimension[3];



int main() 
{
int i,j,k, neg_check, check, end = 0;
float  area = 0, perimeter = 0, volume = 0;

//while (end !=1){
printf ("Enter length, width, and height in cm: ");
scanf (" %d %d %d", &dimension[0], &dimension[1], &dimension[2]);

for (i = 0;i<3;i++){
neg_check = check_neg(dimension[i]);
if(neg_check == 1){
printf("Error: All dimensions must be greater than 0.\n");
check = 1;
break;
}
}
if (check != 1){
area = find_area(dimension[0], dimension[1]);
printf("Base Area: %.2f\n", area);

perimeter = find_perimeter(dimension[0], dimension[1]);
printf("Perimeter: %.2f\n", perimeter);

volume = find_vol(dimension[0], dimension[1], dimension[2]);
printf("Volume: %.2f\n", volume);
}
/*if (volume != 0 && perimeter !=0 && area != 0){
end = 1;
}
}*/
return 0;


}

float check_neg(int num)
{
int answer = 0;
if (num<=0){
answer = 1;
}
else{
answer = 0;
}

return answer;
}

float find_area(int length, int width)
{
float answer1=0;
answer1 = length * width ;
return answer1;
}

float find_perimeter(int length, int width)
{
float answer2=0;
answer2 = ( length * 2)+( width * 2) ;
return answer2;
}
float find_vol(  int length, int width, int height )
{
float answer3=0;
answer3 = height * width * length ;
return answer3;
}