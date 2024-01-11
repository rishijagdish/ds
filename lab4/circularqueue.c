#include <stdio.h>
#include <stdlib.h>
#define size 5

int q[size], f = 0, r = -1;
int count = 0;

void enqueue(int item){
    if(count == size){
        printf("\nQueue full!");
        return;
    }
    q[(++r)%size] = item;
    count++;
}

void dequeue(){
    if(count == 0){
        printf("\nQueue empty!");
        return;
    }
    f = (f+1)%size;
    count--;
}

void display(){
    if(count == 0){
        printf("\nQueue empty!");
        return;
    }
    int front = f;
    for(int i = 0; i<count; i++){
        printf("%d ",q[front]);
        front = (front+1)%size;
    }
}

int main(){
    int ch, item;
    while(1){
        printf("\nSelect choice \n1.Enqueue \n2.Dequeue \n3.Display: ");
        scanf("%d",&ch);

        switch(ch){
        case 1:
            printf("\nEnter value to insert: ");
            scanf("%d",&item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            printf("\nItem popped");
            break;
        case 3:
            display();
            break;
            default:
        exit(0);
    }
    }
}
