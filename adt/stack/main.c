#include "stack.h" 

int main(){
    Stack* stack_floats = stack_init(sizeof(float),5);

    float value_on_the_top_dest = 0;
    peek(stack_floats,&value_on_the_top_dest);
    printf("value on the top %f\n",value_on_the_top_dest);

    float pushed_value = 1.1f;
    push(stack_floats, &pushed_value);
    pushed_value = 3.14f;
    push(stack_floats, &pushed_value);
    pushed_value = 1.2f;
    push(stack_floats, &pushed_value);

    
    value_on_the_top_dest = 0;
    peek(stack_floats,&value_on_the_top_dest);
    printf("value on the top %f\n",value_on_the_top_dest);

    float value_popped = 0.0f;
    pop(stack_floats,&value_popped);
    printf("---> value popped: %f\n",value_popped);
    pop(stack_floats,&value_popped);
    printf("---> value popped: %f\n",value_popped);
    pop(stack_floats,&value_popped);
    printf("---> value popped: %f\n",value_popped);
    pop(stack_floats,&value_popped);

    return 0;
}