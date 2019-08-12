#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node* next;
};

struct node *start = NULL;

struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);

int main()
{
    int option;
    do
    {
        printf("\n*****MAIN MENU*****");
        printf("\n1:  Create a list");
        printf("\n2:  Display the list");
        printf("\n3:  Add node to beginning");
        printf("\n4:  Add node to end");
        printf("\n5:  Add node before a given node");
        printf("\n6:  Add node after a given node");
        printf("\n7:  Delete a node from beginning");
        printf("\n8:  Delete a node from end");
        printf("\n9:  Delete a given node");
        printf("\n10: Delete a node after a given node");
        printf("\n11: Delete the entire list");
        printf("\n12: Sort the list");
        printf("\n13: EXIT");
        printf("\n\nEnter your option : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:  start = create_ll(start);
                     printf("\n LINKED LIST CREATED");
                     break;
            case 2:  start = display(start);
                     break;
            case 3:  start = insert_beg(start);
                     break;
            case 4:  start = insert_end(start);
                     break;
            case 5:  start = insert_before(start);
                     break;
            case 6:  start = insert_after(start);
                     break;
            case 7:  start = delete_beg(start);
                     break;
            case 8:  start = delete_end(start);
                     break;
            case 9:  start = delete_node(start);
                     break;
            case 10: start = delete_after(start);
                     break;
            case 11: start = delete_list(start);
                     printf("\nLINKED LIST DELETED");
                     break;
            case 12: start = sort_list(start);
                     break;

        }
        }while(option!=13);
        getch();
        return 0;

    }

    struct node *create_ll(struct node *start)
    {
        struct node *new_node, *ptr;
        int num;
        printf("\n Enter -1 to end");
        printf("\n Enter the data : ");
        scanf("%d", &num);

        while(num!=-1)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node -> data = num;
            new_node -> next = NULL;
            if(start == NULL)
            {
                start = new_node;
            }
            else
            {
                ptr = start;
                while(ptr -> next != NULL)
                ptr = ptr -> next;

                ptr -> next = new_node;
            }
            printf("\n Enter the data : ");
            scanf("%d", &num);
        }
        return start;
    }

    struct node *display(struct node *start)
    {
        struct node *ptr;
        ptr = start;

        while(ptr != NULL)
        {
            printf("%d ", ptr -> data);
            ptr = ptr -> next;
        }
        return start;
    }

    struct node *insert_beg(struct node *start)
    {
        struct node *new_node;
        int num;
        printf("\nEnter the data : ");
        scanf("%d", &num);
        new_node = (struct node *)malloc(sizeof(struct node*));
        new_node -> data = num;
        new_node -> next = start;
        start = new_node;
        return start;
    }

    struct node *insert_end(struct node *start)
    {
        struct node *ptr, *new_node;
        int num;
        printf("\nEnter the data : ");
        scanf("%d", &num);
        new_node = (struct node *)malloc(sizeof(struct node *));
        new_node -> data = num;
        new_node -> next = NULL;
        ptr = start;

        while(ptr -> next != NULL)
        ptr = ptr -> next;

        ptr -> next = new_node;
        return start;
    }

    struct node *insert_before(struct node *start)
    {
        struct node *new_node, *ptr, *preptr;
        int num, val;
        printf("\nEnter the data : ");
        scanf("%d", &num);
        printf("\nEnter value before which data has to be inserted : ");
        scanf("%d", &val);
        new_node = (struct node *)malloc(sizeof(struct node *));
        new_node -> data = num;
        ptr = start;

        while(ptr -> data != val)
        {
            preptr = ptr;
            ptr = ptr -> next;
        }

        preptr -> next = new_node;
        new_node -> next = ptr;

        return start;
    }

    struct node *insert_after(struct node *start)
    {
        struct node *new_node, *ptr, *preptr;
        int num, val;
        printf("\nEnter the data : ");
        scanf("%d", &num);
        printf("\n Enter the value after which the data has to be inserted : ");
        scanf("%d", &val);

        new_node = (struct node *)malloc(sizeof(struct node *));
        new_node -> data = num;
        ptr = start;
        preptr = ptr;

        while(preptr -> data != val)
        {
            preptr = ptr;
            ptr = ptr -> next;
        }
        preptr -> next = new_node;
        new_node -> next = ptr;
        return start;
    }

    struct node *delete_beg(struct node *start)
    {
        struct node *ptr;
        ptr = start;
        start = start -> next;
        free(ptr);
        return start;
    }

    struct node *delete_end(struct node *start)
    {
        struct node *ptr, *preptr;
        ptr = start;

        while(ptr -> next != NULL)
        {
            preptr = ptr;
            ptr = ptr -> next;
        }
        preptr -> next = NULL;
        free(ptr);
        return start;
    }

    struct node *delete_node(struct node *start)
    {
        struct node *ptr, *preptr;
        int val;
        printf("\nEnter value of node which is to be deleted : ");
        scanf("%d", &val);
        ptr = start;

        if(ptr -> data == val)
        {
            start = delete_beg(start);
            return start;
        }

        while(ptr -> data != val)
        {
            preptr = ptr;
            ptr = ptr -> next;
        }

        preptr -> next = ptr -> next;
        free(ptr);
        return start;
    }

    struct node *delete_after(struct node *start)
    {
        struct node *ptr, *preptr;
        int val;
        printf("\nEnter the value after which the node has to be deleted : ");
        scanf("%d", &val);

        ptr = start;
        preptr = ptr;

        while(preptr -> data != val)
        {
            preptr = ptr;
            ptr = ptr -> next;
        }
        preptr -> next = ptr -> next;
        free(ptr);
        return start;
    }

    struct node *delete_list(struct node *start)
    {
        struct node *ptr;
        if(start != NULL)
        {
            ptr = start;
            while(ptr != NULL)
            {
                printf("\n%d is to be deleted next", ptr -> data);
                start = delete_beg(ptr);
                ptr = start;
            }
        }

        return start;
    }

    struct node *sort_list(struct node *start)
    {
        struct node *ptr1, *lptr = NULL;
        int temp, swapped = 0;
        ptr1 = start;

        if(start == NULL)
        return start;

        do
        {
            swapped = 0;
            ptr1 = start;
            while(ptr1-> next != lptr)
            {
                if(ptr1 -> data > ptr1 -> next -> data)
                {
                    temp = ptr1 -> data;
                    ptr1 -> data = ptr1 -> next -> data;
                    ptr1 -> next -> data = temp;
                    swapped = 1;
                }
                ptr1 = ptr1 -> next;
            }
            lptr = ptr1;
        }while(swapped);

        return start;
    }
