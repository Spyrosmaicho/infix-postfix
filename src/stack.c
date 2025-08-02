#include <stdlib.h>
#include <limits.h>
#include "stack.h"

/* Creating 2 different stacks for postfix and infix */

struct Stack {
    double data;
    Stack next;
};

/*Push a new value to the stack */
void StackPush(Stack* stack, double data) 
{
    Stack node = malloc(sizeof(struct Stack)); 
    if(!node) exit(1); 
    node->next = *stack;  //Set the next pointer to the current top of the stack
    node->data = data;    //Store the value in the node
    *stack = node;        //Update the stack to point to the new top node
}

/*Function that pops the top value from the stack and returns it */
double StackPop(Stack* stack) 
{
    Stack to_free = (*stack); 
    double data = (*stack)->data;  //Store the value from the top node
    *stack = (*stack)->next;  //Move the stack pointer to the next node
    free(to_free);
    return data;    
}

struct Stackc {
    char data;     
    Stackc next; 
};

/*Push a new value to the stack*/
void StackcPush(Stackc* stackc, char data) 
{
    Stackc node = malloc(sizeof(struct Stackc)); 
    if(!node) exit(1);  
    node->next = *stackc;  //Set the next pointer to the current top of the stack
    node->data = data;     //Store the value in the new node
    *stackc = node;      
}

/*Function that pops the top value from the stack and returns it */
char StackcPop(Stackc* stackc) 
{
    Stackc to_free = (*stackc);
    char data = (*stackc)->data;  //Store the value from the top node
    *stackc = (*stackc)->next;  //Move the stack pointer to the next node
    free(to_free); 
    return data; 
}

/*Peek at the top value from the stack without removing it */
char StackcPeek(Stackc stackc) 
{
    return stackc->data; 
}