#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

typedef struct Stack {
    int elements[STACK_SIZE];
    int top;
} Stack;

int print_stack(Stack* stack){
    if(stack->top > -1){
        printf("stack:",stack->elements[0]);
        for(int i=0; i < STACK_SIZE; i+=1){
            printf(",%i",stack->elements[i]);
        }
    }else{
        printf("Stack is empty!");
    }
    printf("top:%i",stack->top);
    return 0;
}

Stack* create_stack(){
    struct Stack* stack = malloc(sizeof(struct Stack));
    if(stack == NULL){
        printf("Not possible to allocate Stack");
    }else{
        stack->top=-1;
        for(int i; i < STACK_SIZE; i+= 1){
            stack->elements[i]=0;
        }
        print_stack(stack);
        return stack;
    }
}

int push(Stack* self, int new_element){
    printf("pushing...");
    if(self->top < STACK_SIZE-1){
        printf("top < stack_size; ");
        self->top += 1;
        self->elements[self->top] = new_element;
    }else{
        printf("Stack is full!, %i",self->top);
        return 0;
    }
    return 1;
}

int pop(Stack* self){
    if(self->top == -1){
        printf("Stack is empty!,%i",self->top);
        return 0;
    }else{
        self->elements[self->top] = 0;
        self->top -= 1;
        return 1;
    }
}

int main(int argc, char** argv){
    Stack* stack = create_stack();
    int exit_condition = 1;
    int menu_option=0;
    while(exit_condition){
        printf("\nChoose one option(1.push;2.pop;3.exit):");
        scanf("%d",&menu_option);
        switch (menu_option)
        {
        case 1:
            push(stack,10);
            print_stack(stack);
            break;
        case 2:
            pop(stack);
            print_stack(stack);
            break;
        case 3:
            exit_condition = 0;
            break;
        default:
            break;
        }
    }
}