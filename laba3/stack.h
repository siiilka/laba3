#pragma once

#include "publication.h"
#include <stddef.h>
#include <stdbool.h>

typedef Publication* StackElement;

typedef struct 
{
    StackElement* data;     
    size_t capacity;        
    size_t size;           
} Stack;

void stack_init(Stack* stack, size_t initial_capacity);

void stack_clear(Stack* stack);

bool stack_empty(const Stack* stack);

size_t stack_size(const Stack* stack);

void stack_push(Stack* stack, StackElement element);

StackElement stack_pop(Stack* stack);

StackElement stack_top(const Stack* stack);





StackElement stack_get(const Stack* stack, size_t index);

StackElement* stack_begin(Stack* stack);
StackElement* stack_end(Stack* stack);


StackElement* stack_next(Stack* stack, StackElement* current);
StackElement* stack_prev(Stack* stack, StackElement* current);


void stack_insert_front(Stack* stack, StackElement element);
void stack_insert_back(Stack* stack, StackElement element);
void stack_insert_at(Stack* stack, size_t index, StackElement element);


StackElement stack_remove_front(Stack* stack);
StackElement stack_remove_back(Stack* stack);
StackElement stack_remove_at(Stack* stack, size_t index);


void stack_swap(Stack* stack, size_t index1, size_t index2);


StackElement* stack_to_array(const Stack* stack);
void stack_from_array(Stack* stack, StackElement* array, size_t size);
