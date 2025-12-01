#include <stdio.h>
int main()
{
    int a=10;
    short d=10;
    long e=10;
    long long int g=10;
    printf("int       byte count:%zu,a=%d\n",sizeof(a),a);
    printf("short     byte count:%zu,d=%d\n",sizeof(d),d);
    printf("long      byte count:%zu,e=%ld\n",sizeof(e),e);
    printf("long long byte count:%zu,g=%lld\n",sizeof(g),g);
    return 0;
}