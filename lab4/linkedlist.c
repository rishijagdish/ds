#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertAtHead(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAtMiddle(struct node *prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertAtEnd(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void display(struct node *node) {
    printf("Linked List:");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int choice = 0, a,b;
    while (choice != 3) {
        printf("Select an option\n1.Insert\n2.Display\n3.Exit\nChoice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted:");
                scanf("%d", &a);
                int choice2;
                printf("--------------\n1.Insert at Head\n2.Insert at end\n3.Insert in the middle\nChoice:");
                scanf("%d", &choice2);
                switch (choice2) {
                    case 1:
                        insertAtHead(&head, a);
                        display(head);
                        break;
                    case 2:
                        insertAtEnd(&head, a);
                        display(head);
                        break;
                    case 3:
                        printf("Enter the value after which to insert:");
                        scanf("%d", &b);
                        struct node *temp = head;
                        while (temp != NULL && temp->data != b) {
                            temp = temp->next;
                        }
                        if (temp == NULL) {
                            printf("Element not found in the list.\n");
                        } else {
                            insertAtMiddle(temp, a);
                            display(head);
                        }
                        break;
                }
                break;
            case 2:
                display(head);
                break;
            default:
                break;
        }
    }

    return 0;
}
