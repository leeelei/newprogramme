#ifndef _stack_h
#define _stack_h
typedef int element_type;
struct stack_record{
        int capacity;
        int top_of_stack;
        element_type* array;
};


typedef struct stack_record *stack;
int is_empty(stack s);
int is_full(stack s);
stack create_stack(int max_elements);
void dispose_stack(stack s);
void make_empty(stack s);
void push(element_type x,stack s);
element_type top(stack s);
void pop(stack s);
element_type top_and_pop(stack s);

#endif
