#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} node;

typedef struct Stack {
    node *top;
} stack;

node* createStackNode(int value){
    node *newNode;

    newNode = malloc(sizeof(newNode));
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

stack* createStack(){
    stack *newStack;

    newStack = malloc(sizeof(stack));
    newStack->top = NULL;

    return newStack;
}

void push(stack *myStack, int value){
    node *newNode = createStackNode(value);

    if(myStack->top == NULL){
        myStack->top = newNode;
    }else{
        newNode->next = myStack->top;
        myStack->top = newNode;
    }
}

void pop(stack *myStack){
    if(myStack->top != NULL){
        node *erasedNode = myStack->top;
        myStack->top = myStack->top->next;
        erasedNode->next = NULL;
        free(erasedNode);
    }
}

void deleteStack(stack *myStack){
    node *topNode = myStack->top;

    while(topNode->next != NULL){
        node *auxNode = topNode;
        topNode = topNode->next;
        free(auxNode);
    }

    myStack->top = NULL;
    free(topNode);
    free(myStack);
}

int main(){
    stack *myStack = createStack();
    return 0;
}
