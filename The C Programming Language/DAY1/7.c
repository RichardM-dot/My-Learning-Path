#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c;
    double d;
    printf("输入二次方程的三个参数:");
    scanf("%d%d%d",&a,&b,&c);
    d=(double)(b*b-4*a*c);
    if(a==0)
    {
        printf("该函数为一次函数请重新输入");
        return 1;
    }
    else
    {
        if(d<0)
        {

            printf("该二次方程无解");
            return 1;
        }
        else if(d==0)
        {
            printf("该二次方程有一解为:%f",(double)(-b)/2*a);
            return 0;
        }
        else
        {
            printf("该二次方程有两解分别为:%f,%f",(double)((-b)+sqrt(d))/2*a,(double)((b)+sqrt(d))/2*a);
            return 0;
        }
    }
    return 0;
}