#include <stdio.h>

int main()

{
    int i = 10;
    int *p;
    p = &i;
    printf("%p %d\n", &i, i);
    // address of i, value of i
    printf("%p %p %d\n", &p, p, *p);
    // address of p, p (address of i), value at p (i)
    return 0;

}