#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <stdbool.h>

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
struct node *print_middle(struct node *);
struct node *delete_middle(struct node *);
struct node *remove_duplicates(struct node *);
struct node *reverse_list(struct node *);
struct node *rotate_list(struct node *);
struct node *check_palindrome(struct node *);

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
        printf("\n13: Print middle node");
        printf("\n14: Delete middle node");
        printf("\n15: Remove duplicates from sorted linked list");
        printf("\n16: Reverse the list");
        printf("\n17: Rotate the list counter-clockwise by k nodes");
        printf("\n18: Check if list is palindrome");
        printf("\n19: EXIT");
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
            case 13: start = print_middle(start);
                     break;
            case 14: start = delete_middle(start);
                     break;
            case 15: start = remove_duplicates(start);
                     printf("\nDUPLICATES REMOVED");
                     break;
            case 16: start = reverse_list(start);
                     printf("\nLIST REVERSED");
                     break;
            case 17: start = rotate_list(start);
                     printf("\nLIST ROTATED");
                     break;
            case 18: start = check_palindrome(start);
                     break;
        }
        }while(option!=19);
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

struct node *print_middle(struct node *start)
{
    struct node *slow_ptr = start;
    struct node *fast_ptr = start;

    if(start != NULL)
    {
        while(fast_ptr != NULL && fast_ptr -> next != NULL)
        {
            fast_ptr = fast_ptr -> next ->next;
            slow_ptr = slow_ptr -> next;
        }
        printf("\nMiddle element is : %d", slow_ptr -> data);
    }
    return start;
}

struct node *delete_middle(struct node *start)
{
    if(start == NULL)
        return start;

    if(start -> next == NULL)
    {
        free(start);
        return NULL;
    }

    struct node *slow_ptr = start;
    struct node *fast_ptr = start;
    struct node *prev = start;

    while(fast_ptr != NULL && fast_ptr -> next != NULL)
    {
        fast_ptr = fast_ptr -> next -> next;
        prev = slow_ptr;
        slow_ptr = slow_ptr -> next;
    }

    prev -> next = slow_ptr -> next;
    free(slow_ptr);
    printf("\nMIDDLE NODE DELETED");
    return start;
}

struct node *remove_duplicates(struct node *start)
{
    struct node *current = start;
    struct node *next_next;

    if(current == NULL)
        return start;

    while(current -> next != NULL)
    {
        if(current -> data == current -> next -> data)
        {
            next_next = current -> next -> next;
            free(current -> next);
            current -> next = next_next;
        }
        else
        current = current -> next;
    }

    return start;
}

struct node* reverse_list(struct node *start)
{
    struct node* prev = NULL;
    struct node *current = start;
    struct node* next;

    while(current != NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    start = prev;
    return start;
}

struct node* rotate_list(struct node *start)
{
    int k;
    printf("\nEnter the value of k : ");
    scanf("%d", &k);

    if(k == 0)
        return start;

    struct node *current = start;
    int count =1;

    while(count < k && current != NULL)
    {
        current = current -> next;
        count++;
    }

    if(current == NULL)
        return start;

    struct node *kthnode = current;
    while(current -> next != NULL)
        current = current -> next;

    current -> next = start;
    start = kthnode -> next;
    kthnode -> next = NULL;
    return start;
}

bool is_palindrome_util(struct node **left, struct node *right)
{
    if(right == NULL)
        return true;

    bool isp = is_palindrome_util(left, right -> next);
    if(isp == false)
        return false;

    bool isp1 = (right -> data == (*left) -> data);
    *left = (*left) -> next;

    return isp1;
}

bool is_palindrome(struct node *start)
{
    is_palindrome_util(&start, start);
}

struct node *check_palindrome(struct node *start)
{
    if(is_palindrome(start))
        printf("\nLIST IS PALINDROME");
    else
        printf("\nLIST IS NOT PALINDROME");

    return start;
}
