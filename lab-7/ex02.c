#include <stdio.h>

int main()

{
    int a = 10;
    int b = 20;
    int c = 30;
    int *ptr1;
    int temp1, temp2, temp3;

    printf("Before swap: a=%d, b=%d, c=%d\n", a, b, c);

    ptr1 = &a;
    temp1 = *ptr1;
    ptr1 = &b;
    temp2 = *ptr1;
    ptr1 = &c;
    temp3 = *ptr1;
    a = temp2;
    b = temp3;
    c = temp1;
    printf("Before swap: a=%d, b=%d, c=%d\n", a, b, c);
    return 0;

}