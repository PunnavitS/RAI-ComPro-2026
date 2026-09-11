#include<stdio.h>
#include<string.h>
int main()
{
struct name{
char firstname[50];
char lastname[50];
int id;
char tel[14];
};
struct name firstlastname;
struct address{
int add;
int moo;
char road[20];
char district[20];
char province[20];
};
struct university{
char name[70];
struct address place;
};
struct university king;

strcpy (firstlastname.firstname,"POOM");
strcpy (firstlastname.lastname,"KONGHUAYROB");
firstlastname.id = 69011014;
strcpy (firstlastname.tel,"088 888 8888");
strcpy (king.name,"King Mongkut\'s Institute of Technology Ladkrabang");
king.place.add = 3;
king.place.moo = 2;
strcpy(king.place.road,"Chalongkrung");
strcpy(king.place.district,"Ladkrabang");
strcpy(king.place.province,"Bangkok");

printf ("Full name: %s %s %d\n",firstlastname.firstname, firstlastname.lastname, firstlastname.id);
printf ("Address : %d Moo %d, %s Rd.\n", king.place.add,king.place.moo,king.place.road);
printf ("%s, %s\n",king.place.district, king.place.province);
printf ("Tel. %s\n",firstlastname.tel);
return 0;
}