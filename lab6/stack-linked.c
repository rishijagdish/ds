#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};


void append(struct node** head, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = NULL;
    struct node* last = *head;

    if (*head == NULL)
        *head = new_node;
    else {
        while (last->next != NULL)
            last = last->next;

        last->next = new_node;
    }
}

void display(struct node* head) {
    if (head == NULL) {
        printf("Linked List empty.\n");
        return;
    }
    printf("Stack:");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


void del_end(struct node *head){
    if(head==NULL){
        printf("List Empty\n");
        return;
    }
    struct node *last=head;

    struct node *prev;
    while(last->next!=NULL){
        prev=last;
        last=last->next;
    }
    free(last);
    prev->next=NULL;

}


int main() {
    struct node* head = NULL;

    int choice,a;


    while(choice<4){
        printf("1.Push\n2.Pop\n3.Display\nChoice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter value:");
            scanf("%d",&a);
            append(&head,a);
            display(head);
            break;
        case 2:
            del_end(head);
            display(head);
            break;
        case 3:
            display(head);
        default:
            break;
        }
    }

    return 0;
}
