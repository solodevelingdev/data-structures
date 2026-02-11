#define STACK_SIZE 5

typedef struct Stack Stack;

struct Stack* create_stack();
int push(Stack* self, int new_element);
int pop(Stack* self, int* out);
int print_stack(Stack* stack);