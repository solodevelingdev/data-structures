#include <stdlib.h>
#include <stdio.h>
#include "stack_lvl_5.h"

struct Stack{
    int data[STACK_SIZE];
    int top;
};

struct Stack* create_stack(){
    struct Stack* stack = malloc(sizeof(struct Stack));
    if(stack == NULL){
        printf("Stack malloc error");
    }
    for(int i=0; i < STACK_SIZE ; i+= 1){
        stack->data[i] = 0;
    }
    stack->top=-1;
    return stack;
}

int push(Stack* self, int new_element){
    if(self->top < STACK_SIZE-1){
        self->top+=1;
        self->data[self->top] = new_element;
        return 1;
    }else{
        return 0;
    }
}

int pop(Stack* self, int* out){
    if(self->top > -1){
        *out = self->data[self->top];
        self->top-=1;
        return 1;
    }else{
        return 0;
    }
}

int print_stack(Stack* stack){
    if(stack->top > -1){
        printf("stack:");
        for(int i=0; i < STACK_SIZE; i+=1){
            printf("%i,",stack->data[i]);
        }
    }else{
        printf("Stack is empty!");
    }
    printf("top:%i",stack->top);
    return 0;
}
