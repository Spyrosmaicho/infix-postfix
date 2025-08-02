#ifndef STACK_H_
#define STACK_H_


typedef struct Stack* Stack;

/*Push a new value to the stack */
void StackPush(Stack* stack, double data);

/*Function that pops the top value from the stack and returns it */
double StackPop(Stack* stack);

typedef struct Stackc* Stackc;

/*Push a new value to the stack*/
void StackcPush(Stackc* stackc, char data);

/*Function that pops the top value from the stack and returns it */
char StackcPop(Stackc* stackc);

/*Peek at the top value from the stack without removing it */
char StackcPeek(Stackc stackc);

#endif /* STACK_H_ */