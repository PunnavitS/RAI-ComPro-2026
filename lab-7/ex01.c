#include <stdio.h>

int main()

{
    int test = 0;
    int *ptr;
    ptr = &test;
    printf("The address test variable is at: %p\n", ptr);

    int temp1;
    ptr = &test;
    *ptr = 99;
    printf("The new value of test via pointer is: %d\n", test);
    return 0;

}
