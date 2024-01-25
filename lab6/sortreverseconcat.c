#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;

};

void append(struct node **head, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = NULL;
    struct node *last = *head;

    if (*head == NULL)
        *head = new_node;
    else
    {
        while (last->next != NULL)
            last = last->next;

        last->next = new_node;
    }
}


void display(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked List empty.\n");
        return;
    }
    printf("Linked List:");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


void bubble_sort(struct node *head)
{
    struct node *prev;
    struct node *cur;
    int nex;
    int flag = 1;
    int flag2 = 1;

    while (flag)
    {
        prev = head;
        while (prev != NULL && prev->next != NULL)
        {
            cur = prev->next;

            if (cur->data < prev->data)
            {
                nex = cur->data;
                cur->data = prev->data;
                prev->data = nex;
            }

            prev = prev->next;
        }

        int max = 0;
        prev = head;

        while (prev != NULL)
        {
            if (max > prev->data)
            {
                flag2 = 0;
                break;
            }
            max = prev->data;
            prev = prev->next;
        }

        if (flag2)
            flag = 0;
        else
            flag2 = 1;
    }
}

void reverse(struct node **head)
{
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;


        prev = current;
        current = next;
    }

    *head = prev;
}

void concat(struct node *head1,struct node *head2){
    struct node *prev=head2;

    while(prev!=NULL){
                    append(&head1,prev->data);
        prev=prev->next;
    }
}

int main()
{
    struct node *head=NULL;
    int choice;
    append(&head,5);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,1);
    append(&head,6);
    struct node *head2=NULL;

 while (1)
    {
        printf("------------------------------\n");
        printf("1.Bubble Sort\n2.Reverse\n3.Concat\nChoice:");
        scanf("%d",&choice);
        printf("------------------------------\n");
        switch (choice)
        {
            case 1:bubble_sort(head);
                   display(head);

                   break;
            case 2: reverse(&head);
                    display(head);
                    break;

            case 3:
                    append(&head2,76);
                    append(&head2,43);
                    append(&head2,34);

                    concat(head,head2);
                    display(head);
                    break;
           
        }
    }
    return 0;
}
