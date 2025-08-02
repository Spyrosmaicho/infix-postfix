# Infix/Postfix

This program converts an infix expression to postfix and then evaluates the expression, printing the result.

## Core Program Functions

- `int precedence(char operator)`  
  Determines the precedence of an operator.

- `int isoperator(char ch)`  
  Checks if a character is a valid mathematical operator (+, -, *, /, ^).

- `double PostFixToEval(char *string)`  
  Evaluates the postfix expression using a stack to store intermediate values.

- `char* InfixToPostfix(char* infix)`  
  Converts an infix expression to postfix using a stack to manage operators and parentheses.

- `double InfixToEval(char* infix)`  
  Combines the infix-to-postfix conversion and evaluation, returning the result.

## Stack

The program uses two stack implementations to convert and evaluate the mathematical expression:

### Stack for Numbers (`Stack`)

Used in `PostFixToEval` to store intermediate values during evaluation.

- `StackPush` adds a new value to the top of the stack.  
- `StackPop` removes and returns the top value of the stack.

### Stack for Operators (`Stackc`)

Used in `InfixToPostfix` to manage operators and parentheses during infix-to-postfix conversion.

- `StackcPush` adds a new operator to the top of the stack.  
- `StackcPop` removes and returns the top operator.  
- `StackcPeek` retrieves the top operator without removing it.

## How to Run

To run the program, use:
```sh
./run.sh
```
If the script is not executable, first run:
```sh
chmod +x run.sh
```

An `input.txt` file is provided where you can enter any infix expression (single line), and the program will evaluate it. It supports multi-digit numbers.

## Example Execution

### Example 1
```sh
$ cat input.txt
(2+3)*4^2+(1+2)
$ ./run.sh
...
Enter infix: 
Postfix: 23+42^*12++
Result: 83.00
...
== All heap blocks were freed -- no leaks are possible
```

### Example 2
```sh
$ ./run.sh
...
Enter infix: 
Postfix: 100 3 * 4 2 ^ +
Result: 316.00
...
== All heap blocks were freed -- no leaks are possible
```

## References

To better understand infix-to-postfix conversion, see:  
- [GeeksforGeeks - Convert Infix to Postfix](https://www.geeksforgeeks.org/convert-infix-expression-to-postfix-expression/)