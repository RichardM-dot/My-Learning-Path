#include <stdio.h>
#include <stdlib.h>
//1.定义链表节点结构体
struct node
{
    int data;
    struct node* prev;//指向前一个节点的指针
    struct node* next;//指向后一个节点的指针
};
int main()
{
    //创建三个节点
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* third=(struct node*)malloc(sizeof(struct node));
    //3.连接节点形成双向链表
    head->data=1;
    head->prev=NULL;
    head->next=second;
    second->data=2;
    second->prev=head;
    second->next=third;
    third->data=3;
    third->prev=second;
    third->next=NULL;
    //正向遍历
    printf("正向遍历");
    struct node* current=head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    //反向遍历
    printf("\n反向遍历");
    current=third;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->prev;
    }
    return 0;
}