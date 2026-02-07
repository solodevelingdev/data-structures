#include <stdio.h>

#define STACK_SIZE 5

int stack[STACK_SIZE];
int top=-1;

int push(int new_element){
    top+=1;
    stack[top]=new_element;
    return new_element;
}

int pop(){
    int popped_element = stack[top];
    top -=1;
    return popped_element;
}

int main(int argc, char** argv){
    printf("pushed: %i\n",push(10));
    printf("pushed: %i\n",push(20));
    printf("pushed: %i\n",push(30));

    printf("poped: %i\n",pop());
    printf("poped: %i\n",pop());
    printf("poped: %i\n",pop());
    
    return 0;
}