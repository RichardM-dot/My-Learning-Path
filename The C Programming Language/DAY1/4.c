#include <stdio.h>
int main()
{
    printf("number square cube\n");
    for(int i=0;i<5;i++)
    {
        printf("%d\t%d\t%d\n",i+1,(i+1)*(i+1),(+1)*(i+1)*(i+1));
    }
    return 0;
}