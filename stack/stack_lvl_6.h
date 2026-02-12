typedef struct Stack Stack;

struct Stack* create_stack();
int stack_init(Stack* stack, int capacity);
int push(Stack* self, int new_element);
int pop(Stack* self, int* out);
int print_stack(Stack* stack);
int destruct_stack();