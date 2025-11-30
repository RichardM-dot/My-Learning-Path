#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
//在循环列表尾部插入节点
void insert(struct node** head,int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(*head==NULL)
    {
        *head=newnode;
        newnode->next=newnode;//指向自己形成循环
    }
    else
    {
        struct node* temp=*head;
        while(temp->next!=*head)//遍历找到尾节点
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=*head;
    }
}
    void traverse(struct node* head)
    {
        if(head==NULL) return;
        struct node * temp=head;
        do
        {
            printf("%d ",temp->data);
            temp=temp->next;
        } while(temp!=head);
        printf("\n");
    }
    int main()
    {
        struct node* head=NULL;
        insert(&head,1);
        insert(&head,2);
        insert(&head,3);
        printf("循环列表:");
        traverse(head);
        return 0;
    }
