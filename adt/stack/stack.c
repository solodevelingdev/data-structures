#include "stack.h" 

Stack* stack_init(size_t element_size, size_t capacity){
    Stack *stack = calloc(1,sizeof(Stack));
    stack->buffer = calloc(capacity,element_size);
    stack->top = -1;
    stack->capacity = capacity;
    stack->element_size = element_size;

    if(stack == NULL){
        // TODO: Define error message values later
        printf("Error: Stack was not created!");
    }else{
        printf("Stack was created!\n");
        printf("stack->capacity:%zu ;",stack->capacity);
        printf("stack->element_size:%zu",stack->element_size);
    }

    return stack;
}

void* peek(Stack *stack, void *p_element_dest){
    memcpy(p_element_dest,((char*)stack->buffer)+(stack->top*stack->element_size),stack->element_size);
}

int push(Stack *stack,void *p_element){
    if(isEmpty(stack)){
        memcpy(stack->buffer,p_element,stack->element_size);
    }else{
        memcpy(((char*)stack->buffer)+((stack->top+1)*stack->element_size),p_element,stack->element_size);
    }
    stack->top += 1;
    
    printf("top: %d ;",stack->top);
    for(char* i = stack->buffer ; i <= ((char*)stack->buffer)+(stack->top*stack->element_size) ; i+=stack->element_size){
        printf(" element: %.2f ",*(float*)i);
    }
    printf("\n");
    return 0;
}

int pop(Stack *stack, void* p_element_dest){
    if(!isEmpty(stack)){
        memcpy(p_element_dest,((char*)stack->buffer)+(stack->top*stack->element_size),stack->element_size);
    }else{
        printf("Stack is already empty");
        return 1;
    }
    stack->top -=1;

    printf("top: %d ;",stack->top);
    for(char* i = stack->buffer ; i <= ((char*)stack->buffer)+(stack->top*stack->element_size) ; i+=stack->element_size){
        printf(" element: %.2f ",*(float*)i);
    }
    return 0;
}

bool isEmpty(Stack *stack){
    return stack->top == -1;
}