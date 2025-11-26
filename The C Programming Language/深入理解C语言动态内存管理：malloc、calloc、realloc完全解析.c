#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    printf("=========动态内存管理完整演示=========\n");
    //malloc:从堆区分配指定大小的内存块，内容为随机值
    printf("1.malloc分配-未初始化的内存:\n");
    int *malloc_arr=(int*)malloc(5*sizeof(int));
    if(malloc_arr==NULL)
    {
        printf("内存分配失败\n");
        return 1;
    }
    printf("malloc分配地址:%p\n",(void*)malloc_arr);
    printf("初始内容(随机值)");
    for(int i=0;i<5;i++)
    {
        printf("%d ",malloc_arr[i]);//显示未初始化的值
    }
    printf("\n\n");
    //calloc演示:分配并清的零的内存
    printf("2.calloc分配-自动清零的内存:\n");
    int *calloc_arr=(int*)calloc(5,sizeof(int));//分配并清零
    if(calloc_arr==NULL)
    {
        printf("calloc分配失败\n");
        free(malloc_arr);
        return 1;
    }
    printf("calloc分配地址:%p\n",(void*)calloc_arr);
    printf("初始内容(全零):");
    for(int i=0;i<5;i++)
    {
        printf("%d ",calloc_arr[i]);//显示已初始化的零值
    }
    printf("\n\n");
    //3.realloc演示:调整已分配内存大小
    printf("3.realloc调整-内存大小调整:\n");
    void *original_addr=(void*)calloc_arr;//先保存原始地址用于比较
    printf("原始地址:%p\n",original_addr);
    int *temp=(int*)realloc(calloc_arr,10*sizeof(int));
    if(temp==NULL)
    {
        printf("realloc失败,保持原内存\n");//失败时原内存仍有效
        temp=calloc_arr;//继续使用原指针
    }
    else
    {
        calloc_arr=temp;//使用新指针
        printf("新地址:%p\n",(void*)calloc_arr);
        if(original_addr==(void*)calloc_arr)
        {
            printf("内存原地扩展\n");
        }
        else
        {
            printf("内存异地扩展\n");
        }
    }
    //4.内存使用演示
    printf("4.内存内容状态演示:\n");
    // 初始化malloc数组
    for(int i = 0; i < 5; i++) 
    {
        malloc_arr[i] = i * 10;
    }
    printf("   malloc数组初始化后: ");
    for(int i = 0; i < 5; i++) 
    {
        printf("%d ", malloc_arr[i]);
    }
    printf("\n");
    // 展示realloc后新增部分的内容（未初始化）
    printf("realloc后新增部分(未初始化): ");
    for(int i = 5; i < 10; i++) 
    {
        printf("%d ", calloc_arr[i]);  // 显示可能存在的随机值
    }
    printf("\n");
    // 初始化realloc新增的内存
    for(int i = 5; i < 10; i++) 
    {
        calloc_arr[i] = i * 10;
    }
    printf("   realloc数组完整内容: ");
    for(int i = 0; i < 10; i++) 
    {
        printf("%d ", calloc_arr[i]);
    }
    printf("\n\n");
    //5. 内存释放和清理
     printf("5. 内存释放:\n");
    
    free(malloc_arr);           // 释放malloc分配的内存
    malloc_arr = NULL;          // 避免悬空指针
    
    free(calloc_arr);           // 释放realloc调整后的内存  
    calloc_arr = NULL;          // 避免悬空指针
    
    printf("所有内存已释放\n");
    printf("释放后指针状态: malloc_arr=%p, calloc_arr=%p\n",(void*)malloc_arr, (void*)calloc_arr);
    printf("\n=== 演示结束 ===\n");
    return 0;
}