#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node* next;
};
typedef struct node listnode;
typedef struct node* linkedlist;
listnode* createnode(int data)
{
    listnode* newnode=(listnode*)malloc(sizeof(listnode));
    if(newnode==NULL)
    {
        printf("内存分配失败！\n");
        return NULL;
    }
    newnode->data=data;
    newnode->next=NULL;//需要初始化为独立节点，暂时不指向任何节点
    return newnode;
}
void insertathead(linkedlist* head,int data)//头部插入函数
{
    listnode* newnode=createnode(data);
    if(newnode==NULL)
    {
        return;
    }
    newnode->next=*head;//新节点指向原来的头节点
    *head=newnode;//头指针指向新节点
    //两处的head有不同      
    printf("在头部插入节点:%d\n",data);
}
void insertattail(linkedlist* head,int data)//在尾部插入节点
{
    listnode* newnode=createnode(data);
    if(newnode==NULL)
    {
        return;
    }
    if(*head==NULL)//如果链表为空，新节点就是头节点
    {
        *head=newnode;
        printf("在尾部插入节点：%d\n",data);
        return;
    }
    //从头开始一直找到最后一个节点
    listnode* current=*head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newnode;//循环结束后current指向最后一个节点
    printf("在尾部插入节点=%d\n",data);//最后一节点的next指向新的节点
}
void insertatposition(linkedlist* head,int data,int position)
{
    if(position<0)
    { 
        printf("插入位置无效\n");
        return;
    }
    if(position==0)//位置0为头部插入
    {
        insertathead(head,data);
        return;
    }
    listnode* newnode=createnode(data);
    if(newnode==NULL)
    {
        return;
    }
    listnode* current=*head;
    //循环position-1次，找到要插入位置的前一个节点
    for(int i=0;i<position-1;i++)
    {
        current=current->next;
    }
        if(current==NULL)
        {
            printf("插入位置超出链表长度\n");
            free(newnode);//释放刚刚创建的节点，避免内存泄漏(malloc每次都必须有对应的free)
            return;
        }
        newnode->next=current->next;
        current->next=newnode;
        printf("在%d位置插入节点:%d\n",position,data);
}
void deletenode(linkedlist* head,int data)
{
    if(*head==NULL)
    {
        printf("链表为空，无法删除节点:%d\n",data);
        return;
    }
    listnode* current=*head;//当前正在检查的节点
    listnode* previous=NULL;//始终指向current的前一个指针
    //遍历列表直到找到匹配的节点或者达到末尾
    while(current!=NULL && current->data!=data)
    {
        previous=current;
        current=current->next;
    }
    if(current==NULL)
    {
        printf("未找到要删除的节点:%d\n",data);
        return;
    }
    if(previous==NULL)
    {
        *head=current->next;
    }
    else
    {
        previous->next=current->next;
    }
    printf("删除节点:%d\n",data);
    free(current);
}
void traverselist(linkedlist head)
{
    if(head==NULL)
    {
        printf("链表为空\n");
        return;
    }
    printf("当前列表:");
    listnode* current=head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        if(current->next!=NULL)
        {
            printf("->");
        }
        current=current->next;
    }
    printf("->NULL\n");
}
void clearlist(linkedlist* head)
{
    listnode* current=*head;
    printf("清空列表中\n");
    while(current !=NULL)
    {
        listnode* nextnode = current->next;
        free(current);
        current=nextnode;
    }  
    *head=NULL;
    printf("链表已经清空了\n");
}
int main()
{
    linkedlist head=NULL;
    printf("=========单链表操作展示=========\n");
    printf("1. 测试尾部插入:\n");
    insertattail(&head, 10);
    insertattail(&head, 20);
    insertattail(&head, 30);
    traverselist(head);
    printf("\n");
    printf("2. 测试头部插入:\n");
    insertathead(&head, 5);
    insertathead(&head, 1);
    traverselist(head);
    printf("\n");
    printf("3. 测试指定位置插入:\n");
    insertatposition(&head, 15, 3);  
    traverselist(head);
    printf("\n");
    printf("4. 测试删除操作:\n");
    deletenode(&head, 15); 
    traverselist(head);
    deletenode(&head, 1);  
    traverselist(head);
    deletenode(&head, 99);  
    traverselist(head);
    printf("\n");
    printf("5. 测试清空链表:\n");
    clearlist(&head);
    traverselist(head);
    return 0;
}


