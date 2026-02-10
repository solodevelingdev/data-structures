#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 5

typedef struct Stack{
    int data[STACK_SIZE];
    int top;
} Stack;

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

int main(int argc, char** argv){
    Stack* stack = create_stack();
    int exit_condition = 1;
    int option;
    int popping_element;
    while(exit_condition){
        printf("Choose an option:(1.push 2.pop 3.print 4.exit): ");
        scanf("%d",&option);
        switch(option){
            case 1: 
                push(stack,10); 
                break;
            case 2: 
                if(pop(stack,&popping_element)){
                    printf("Pop:%i\n",popping_element);
                }else{
                    printf("Stack is empty!");
                }
                break;
            case 3:
                print_stack(stack);
                break;
            case 4:
                printf("Exit gracefully!\n");
                exit_condition = 0;
                break;
        }
    }
}