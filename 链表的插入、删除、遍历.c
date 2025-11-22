#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertathead(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertattail(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    struct node* last = *head_ref;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}

void deletenode(struct node** head_ref, int key)
{
    struct node *temp = *head_ref, *prev = NULL;
    if(temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("未找到值为%d的节点\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void printlist(struct node* node)
{
    printf("当前链表: ");
    while(node != NULL)
    {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node* head = NULL;
    insertattail(&head, 10);
    insertattail(&head, 20);
    insertattail(&head, 30);
    printlist(head);
    insertathead(&head, 5);
    printlist(head);
    deletenode(&head, 20);
    printlist(head);
    deletenode(&head, 100);
    return 0;
}


