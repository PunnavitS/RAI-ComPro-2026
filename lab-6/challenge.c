#include <stdio.h>
#include <math.h>
#include <string.h>
 int main()
{
struct totgrade {
float math, sci, eng, his;
float avg;
};
struct Student {
char name[21];
int id;
struct totgrade grade;
};

struct aveggrade {
float avg4, sum;
};

char topsubjectbyscore[99];
int i, j, topavg = 0, topavgbysubject = 0;
struct aveggrade avggrade[4];
struct Student score[3];
float avg, avg2 = 0, avgmath = 0, avgsci = 0, avghis = 0, avgeng = 0, summath = 0, sumsci = 0, sumhis = 0, sumeng = 0, avg3 = 0;
float averagescore[4];
for(i=0;i<3;i++)
{
printf ("Enter name, ID, and 4 grades for student  %d:\n", i+1);
scanf (" %s %d %f %f %f %f", score[i].name, &score[i].id, &score[i].grade.math, &score[i].grade.eng, &score[i].grade.sci, &score[i].grade.his);
printf("\n");
}


printf("\nStudent Averages:\n");

for(i=0;i<3;i++)
{
    score[i].grade.avg = ((score[i].grade.math + score[i].grade.eng + score[i].grade.sci + score[i].grade.his)/4);
  printf ("%s (ID: %d) : %.2f\n", score[i].name, score[i].id, score[i].grade.avg);
  if (avg2 < score[i].grade.avg){
    topavg = i;
  }
}
printf("Top Student: %s with %.2f\n", score[topavg].name, score[topavg].grade.avg);

printf("\nSubject Averages:\n");
for(i=0;i<=4;i++)
{
summath = summath+score[i].grade.math;
sumsci = sumsci+score[i].grade.sci;
sumeng = sumeng+score[i].grade.eng;
sumhis = sumhis+score[i].grade.his;
}
averagescore[0] = summath/3;
averagescore[1] = sumeng/3;
averagescore[2] = sumsci/3;
averagescore[3] = sumhis/3;

for(i=0;i<=4;i++)
{
  if (avg3 < averagescore[i]){
    avg3 = averagescore[i];
    topavgbysubject = i;
  }
}
if (topavgbysubject == 1){
    strcpy(topsubjectbyscore, "Math");
} else if (topavgbysubject == 2){
    strcpy(topsubjectbyscore, "English");
} else if (topavgbysubject == 3){
    strcpy(topsubjectbyscore, "Science");
} else if (topavgbysubject == 4){
    strcpy(topsubjectbyscore, "History");
}

for(j=0;j<=4;j++)
{
  if (j == 0){
    printf("Math: %.2f\n", averagescore[j]);
} else if (j == 1){
    printf("English: %.2f\n", averagescore[j]);
} else if (j == 2){
    printf("Science: %.2f\n", averagescore[j]);
} else if (j == 3){
    printf("History: %.2f\n", averagescore[j]);
}
}

printf("Top Subject: %s with average %.2f\n", topsubjectbyscore, averagescore[topavgbysubject-1]);

return 0;
}


// cc testing.c -lm