/* 
    Stack should provide the following operations:
    1. Push
    Insert a new element onto the top of the stack.
    2. Pop
    Remove the element currently at the top of the stack.
    3. Peek
    Return the element at the top.
    Do not remove it.
    4. IsEmpty
    Report whether the stack currently contains any elements.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

typedef struct{
    void* buffer;
    size_t element_size;
    int top;
    size_t capacity;
}Stack;

Stack* stack_init(size_t element_size, size_t capacity);
void* peek(Stack *stack, void *p_element_dest); // shows the element
int push(Stack *stack,void *p_element);
int pop(Stack *stack, void *p_element_dest); // pops the element
bool isEmpty(Stack *stack);