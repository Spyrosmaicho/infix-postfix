#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "infix.h"
#include <unistd.h>


int main(void)
{
    char *infix = NULL;
    char *postfix = NULL;
    size_t len = 0;
    ssize_t read;

    
    printf("Enter infix: ");
    read = getline(&infix, &len, stdin); 

    if (read == -1) fprintf(stderr,"Error.\n");

    if (infix[read - 1] == '\n')
        infix[read - 1] = '\0';

    printf("\n");

    double num = InfixToEval(infix,&postfix);

    printf("Postfix: %s\n\n",postfix);

    free(postfix);  // Free the memory allocated for the postfix string

    printf("Result: %.2lf\n", num);
    free(infix); //free memory allocated by getline.
    return 0;
}