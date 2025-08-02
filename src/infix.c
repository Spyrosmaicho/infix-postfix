#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "stack.h"

/* Functions hidden from the user */
int precedence(char operator);
int isoperator(char ch);
double PostFixToEval(char *string);
char* InfixToPostfix(char* infix);

/* Operator precedence */
int precedence(char operator) 
{
    switch (operator) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default : return -1;
    }
}

/* All valid operators */
int isoperator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' 
         || ch == '/' || ch == '^');
}

/* Function that evaluates postfix */
double PostFixToEval(char *string) 
{
    Stack stack = NULL;  // Initializing an empty stack
    double left, right, res; 
    int len = strlen(string); 
    for (int i = 0; i < len; ++i) 
    {
        if (isspace(string[i])) continue;

        // If the character is a digit, read the entire number
        if (isdigit(string[i])) {
            int capacity = 32; //Initial capacity
            char *numStr = malloc(sizeof(char)*capacity); // Buffer to hold the number as a string, 
            if(!numStr) 
            {
                fprintf(stderr,"Problem allocating memory.\n");
                exit(1);
            } 
            int j = 0;
            while (i < len && (isdigit(string[i]) || string[i] == '.')) {
                if(j >= capacity -1) //That means we have stored 32 digits and not null terminator so the number has more digits.
                {
                    capacity*=2; //double the capacity to make space for all the digits of the number
                    char *temp  =realloc(numStr,sizeof(char)*capacity);
                    if(!temp)
                    {
                        free(numStr);
                        fprintf(stderr,"Problem allocating memory.\n");
                        exit(1);
                    }
                    numStr = temp;
                }
                numStr[j++] = string[i++];
                
            }
            numStr[j] = '\0';  // Null-terminate the number string
            StackPush(&stack, atof(numStr));  // Push the number onto the stack
            free(numStr);
            i--;  // Since the for loop will increase i, we need to decrease it here
        }
        else if (isoperator(string[i])) {
            // Pop numbers from the stack for the operation
            right = StackPop(&stack);  
            left = StackPop(&stack);   

            // For every operation push the result to the stack
            switch (string[i]) {
                case '+':  
                    StackPush(&stack, left + right);  
                    break;
                case '-':  
                    StackPush(&stack, left - right);  
                    break;
                case '*':  
                    StackPush(&stack, left * right);  
                    break;
                case '/':  
                    StackPush(&stack, left / right); 
                    break;
                case '^':  
                    StackPush(&stack, pow(left, right));  
                    break;
                default:
                    break;
            }
        }
    }
    res = StackPop(&stack);  // The final result is the last value left on the stack
    return res; 
}

/* Function that converts infix to postfix */
char* InfixToPostfix(char* infix) 
{
    Stackc stack = NULL;  // Initializing an empty stack for operators
    int len = strlen(infix); 
    char* postfix = malloc((len * 2) * sizeof(char));  // Allocate more space to handle multi-digit numbers
    if(!postfix) exit(1); 
    int i = 0, j = 0;
    for( ; i < len; i++) {
        if (isspace(infix[i])) continue; 

        // If the character is a digit, read the entire number
        if (isdigit(infix[i])) {
            while (i < len && isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';  // Add a space to separate numbers
            i--;  // Since the for loop will increase i, we need to decrease it so as not to ignore an element.
        }
        else if (infix[i] == '(') {
            StackcPush(&stack, infix[i]);
        }
        else if (infix[i] == ')') {
            // Pop all operators until '(' is encountered
            while (stack && StackcPeek(stack) != '(') {
                postfix[j++] = StackcPop(&stack);
                postfix[j++] = ' ';  // Add a space to separate operators
            }
            assert(stack && StackcPeek(stack) == '('); 
            StackcPop(&stack); 
        }
        else if (isoperator(infix[i])) {
            // Pop operators with higher or equal precedence
            while (stack && precedence(StackcPeek(stack)) >= precedence(infix[i])) {
                postfix[j++] = StackcPop(&stack);
                postfix[j++] = ' ';  //Add a space to separate operators
            }
            StackcPush(&stack, infix[i]);  // Push the current operator onto the stack
        }
    }
    // Pop all remaining operators from the stack
    while (stack) {
        assert(StackcPeek(stack) != '('); 
        postfix[j++] = StackcPop(&stack);
        postfix[j++] = ' ';  // Add a space to separate operators
    }
    postfix[j] = '\0';  // Null-terminate the postfix
    return postfix; 
}

/* Function that evaluates an infix by converting it to postfix first */
double InfixToEval(char* infix, char **postfix) {
    *postfix = InfixToPostfix(infix);
    double ret = PostFixToEval(*postfix); 
    return ret; 
}