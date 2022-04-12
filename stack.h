// stack.h
// AUTHOR: Pranav Shridhar
// Description:
/*  
	The contents of stack.h consist of the implementation of the stack abstract data type (ADT) in C.
	Elements, specifically characters for the Balanced Brackets project, can be pushed onto and popped from the stack.
	Memory relating to instances of this implementation of the stack are allocated to the heap with the 
	stack_init() function, and must be freed with the stack_dealloc() function.
	
*/

#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    struct node* next;
    char data;
} NODE;

typedef struct stack {
    NODE* top;
    int size;
} STACK;

// Initialises a STACK and returns a pointer to it
STACK* stack_init() {
    STACK* newOne = (STACK*)malloc(sizeof(STACK));
    newOne->size = 0;
    newOne->top = NULL;
    return newOne;
}

// Accepts a STACK pointer and a character, and then pushes that character on to the stack
void stack_push(STACK* s, char c) {
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data = c;
    temp->next = s->top;
    s->top = temp;
    s->size++;
}

// Accepts a STACK pointer and pops an element from the stack. Does not return anything.
void stack_pop(STACK* s) {
    NODE* poptop = s->top;
    s->top = s->top->next;
    free(poptop);
    s->size--;
}

// Accepts a STACK pointer and returns the character at the top of the stack
char stack_top(STACK* s) {
    return s->top->data;
}

// Accepts a STACK pointer and frees all memory associated with it.
void stack_dealloc(STACK* s) {
	while(s->size > 0) {
		stack_pop(s);
	}
	free(s);
}

// Returns the size of the stack.
int stack_size(STACK* s) {
	return s->size;
}
