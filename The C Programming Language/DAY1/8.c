#include <stdio.h>
int main()
{
    int a=10;
    printf("the value of the variable:%d,the address of the variable:%p\n",a,(void*)&a);
    printf("the number of bytes at the variable's address:%zu ",sizeof(a));
    return 0;
}