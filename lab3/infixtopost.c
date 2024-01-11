#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define size 30

char stack[size];
int top=-1;

void push(char a){
    stack[++top]=a;
}

char pop(){
    return stack[top--];
}

int precedence(char a){
    if(a=='^')
        return(3);
    else if(a=='*' || a=='/')
        return(2);
    else if(a=='+' || a=='-')
        return(1);
    else 
        return(0);
}


void main(){
    char infix[size],postfix[size];

    printf("Enter infix expression:");
    scanf("%s",infix);
    int len=strlen(infix);
    int j=0;
    printf("Char\tStack\tpostfix\n");

    for(int i=0;i<len;i++){
        if(infix[i]=='(')
            push('(');
        else if(infix[i]==')'){
            while(stack[top]!='('){
                postfix[j++]=pop();
            }
            pop();
        }
        else{
            if(isalnum(infix[i])){
                postfix[j++]=infix[i];
            }
            else{
                if(precedence(stack[top])<precedence(infix[i]))
                    push(infix[i]);
                else{
                    while(stack[top]!='('){
                        postfix[j++]=pop();
                    }
                    push(infix[i]);
                }
            }
        }
        stack[top+1]='\0';
        postfix[j]='\0';
        printf("%c\t%s\t%s\n",infix[i],stack,postfix);
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("Postfix Expression is:%s",postfix);

}
