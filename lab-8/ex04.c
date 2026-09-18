#include <stdio.h>
#include <string.h>

int separate_char_type( void );
int num_count( void );
int char_count( void );
char string[99];
int length;
int tot_spe_char = 0;
int tot_num_char = 0;
int tot_alp_char = 0;


int main() 
{
printf ("Input: ");
scanf (" %[^\n]", string);
length = strlen(string);
tot_spe_char = separate_char_type();
tot_num_char = num_count();
tot_alp_char = char_count();
printf ("Letters: %d\n", tot_alp_char);
printf ("Digits: %d\n", tot_num_char);
printf ("Special Characters / Symbols: %d\n", tot_spe_char);
return 0;
}


int separate_char_type(void)
{
int i, temp2;
char temp;
float answer=0;
for (i = 0; i<length; i ++){
temp = string[i];
if (temp == ' ' || temp == ','|| temp == '!'|| temp == '@'|| temp == '#'|| temp == '$'|| temp == '%'|| temp == '^'|| temp == '&'|| temp == '*'|| temp == '('|| temp == ')'|| temp == '_'|| temp == '-'|| temp == '+'|| temp == '=' || temp == '\''|| temp == '\"'|| temp == ';'|| temp == ':'|| temp == '<'|| temp == '>'|| temp == '?' || temp == '/'){
answer +=1;
}
}
return answer;
}

int num_count(void)
{
int i, temp2;
char temp;
float answer1=0;
for (i = 0; i<length; i ++){
temp = string[i];
if (temp == '0' || temp == '1'|| temp == '2'|| temp == '3'|| temp == '4'|| temp == '5'|| temp == '6'|| temp == '7'|| temp == '8'|| temp == '9'){
answer1 +=1;
}
}
return answer1;
}

int char_count(void)
{
float answer2=0;
answer2 = length - tot_spe_char - tot_num_char;
return answer2;
}