void append(struct ListNode** head,int val){
    struct ListNode *new_node=(struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val=val;
    new_node->next=NULL;
    struct ListNode *prev=*head;
    if(prev==NULL){
        *head=new_node;
        return;
    }
    while(prev->next!=NULL)
        prev=prev->next;
    prev->next=new_node;
}

void mid(struct ListNode *prev,int val){

    struct ListNode* new_node=(struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val=val; 
    new_node->next=prev->next;
    prev->next=new_node;
}

void push(struct ListNode **head,int value){
    struct ListNode *new_node=(struct ListNode*)malloc(sizeof(struct ListNode));

    new_node->val=value;
    new_node->next=(*head);
    *head=new_node;
}
struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
    struct ListNode* newhead=NULL;
    int i=1;
    struct ListNode* cur=head;
    struct ListNode* prev=newhead;
    while(cur!=NULL)
    {
        
        if(left<=i && right>=i)
        {   
            if(prev==NULL){
                append(&newhead,cur->val);
                prev=newhead;
                cur=cur->next;
                i++;
                continue;
            }
            else if(left==1){
                push(&newhead,cur->val);
            }

            else
                mid(prev,cur->val);
        }
        else
        {
            append(&newhead,cur->val);
            prev = (prev == NULL) ? newhead : prev->next;
        }

        i++;
        cur=cur->next;
    }
    
    return newhead;
}

void display(struct ListNode* head) {
    if (head == NULL) {
        printf("Linked List empty.\n");
        return;
    }
    printf("Linked List:");
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
