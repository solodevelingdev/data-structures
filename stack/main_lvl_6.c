#include "stack_lvl_6.h"
#include <stdio.h>

int main(int argc, char** argv){
    int stack_capacity=10;
    Stack* stack = create_stack(stack_capacity);
    int exit_condition = 1;
    int option;
    int popping_element;
    while(exit_condition){
        printf("Choose an option:(1.push 2.pop 3.print 4.exit): ");
        scanf("%d",&option);
        switch(option){
            case 1: 
                if(!push(stack,10)){
                    printf("Stack is full!\n");
                } 
                break;
            case 2: 
                if(pop(stack,&popping_element)){
                    printf("Pop:%i\n",popping_element);
                }else{
                    printf("Stack is empty!\n");
                }
                break;
            case 3:
                print_stack(stack);
                break;
            case 4:
                destruct_stack(stack);
                printf("Exit gracefully!\n");
                exit_condition = 0;
                break;
            
        }
    }
}