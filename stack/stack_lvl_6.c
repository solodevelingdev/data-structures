#include <stdlib.h>
#include <stdio.h>
#include "stack_lvl_6.h"

struct Stack{
    int* data;
    int capacity;
    int top;
};

int stack_init(struct Stack* self, int capacity){
    self->data = malloc(capacity * sizeof(int));
    self->capacity = capacity;
    for(int i=0; i < self->capacity ; i+= 1){
        self->data[i] = 0;
    }
    self->top=-1;
    return 1;
}

struct Stack* create_stack(int capacity){
    Stack* stack = malloc(sizeof(struct Stack));
    if(stack == NULL){
        printf("Stack malloc error");
        return NULL;
    }else{
        stack_init(stack,capacity);
        return stack;
    }
}

int destruct_stack(Stack* self){
    free(self->data);
    free(self);
}

int push(Stack* self, int new_element){
    if(self->top < self->capacity-1){
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
        for(int i=0; i < stack->capacity; i+=1){
            printf("%i,",stack->data[i]);
        }
    }else{
        printf("Stack is empty!");
    }
    printf("top:%i",stack->top);
    return 0;
}
