#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int priority;
    struct node* next;
}Node;

Node* newNode(int d, int p)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp -> data = d;
    temp -> priority = p;
    temp -> next = NULL;
    return temp;
}

int peek(Node **head)
{
    if((*head) == NULL)
        return -1;
    return (*head) -> data;
}

void push(Node** head, int d, int p)
{
    Node *start = *head;
    Node *temp = newNode(d,p);

    if((*head) == NULL)
    {
        *head = temp;
        return;
    }

    if((*head) -> priority > p)
    {
        temp -> next = *head;
        (*head) = temp;
    }
    else
    {
        while(start -> next != NULL &&
              start -> next -> priority < p)
        start = start -> next;

        temp -> next = start -> next;
        start -> next = temp;
    }

}

void pop(Node **head)
{
    Node *temp = *head;
    (*head) = (*head) -> next;
    free(temp);
}

int isempty(Node **head)
{
    return (*head) == NULL;
}

int main()
{
    Node *pq = NULL;
    int res=-1;
    while(res!=5)
    {
        printf("*****MAIN MENU*****");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Print");
        printf("\n5. EXIT");
        printf("\nEnter response : ");
        scanf("%d", &res);

        switch(res)
        {
            int d,p;
            case 1:
                printf("\nEnter data : ");
                scanf("%d", &d);
                printf("\nEnter priority : ");
                scanf("%d", &p);
                push(&pq, d, p);
                break;

            case 2:
                pop(&pq);
                 break;

            case 3:
                printf("\nHead : %d\n",peek(&pq));
                break;

            case 4:
                while(!isempty(&pq))
                {
                    printf("%d ", peek(&pq));
                    pop(&pq);
                }
                printf("\n");
                break;
        }
    }

    return 0;
}
