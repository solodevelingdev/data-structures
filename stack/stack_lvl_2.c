#include <stdio.h>

#define STACK_SIZE 5

int stack[STACK_SIZE];
int top=-1;

int push(int new_element){
    if(top >= STACK_SIZE){
        printf("Stack full!;");
        return 0;
    }else{
        top+=1;
        stack[top]=new_element;
        return new_element;
    }
}

int pop(){
    int popped_element = stack[top];
    stack[top] = 0;
    top -=1;
    return popped_element;
}

int print_stack(){
    if(top > -1){
        printf("stack:",stack[0]);
        for(int i=0; i < STACK_SIZE; i+=1){
            printf(",%i",stack[i]);
        }
    }else{
        printf("Stack is empty!");
    }
    printf("top:%i",top);
    return 0;
}

int main(int argc, char** argv){
    int exit_condition = 1;
    int menu_option=0;
    while(exit_condition){
        printf("\nChoose one option(1.push;2.pop;3.exit):");
        scanf("%d",&menu_option);
        switch (menu_option)
        {
        case 1:
            push(10);
            print_stack();
            break;
        case 2:
            pop();
            print_stack();
            break;
        case 3:
            exit_condition = 0;
            break;
        default:
            break;
        }
    }    
    return 0;
}