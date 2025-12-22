#pragma once

#include "publication.h"
#include <stddef.h>
#include <stdbool.h>

typedef Publication StackElement;

typedef struct 
{
    StackElement* data;     
    size_t capacity;        
    size_t size;           
} Stack;

void stack_init(Stack* stack, size_t initial_capacity);
void stack_destroy(Stack* stack);
void stack_clear(Stack* stack);

bool stack_is_empty(const Stack* stack);
bool stack_is_full(const Stack* stack);
size_t stack_get_size(const Stack* stack);
size_t stack_get_capacity(const Stack* stack);

bool stack_push(Stack* stack, const StackElement* element);
bool stack_pop(Stack* stack);
StackElement* stack_peek(const Stack* stack);
bool stack_top(const Stack* stack, StackElement* result);

StackElement* stack_at(const Stack* stack, size_t index);
bool stack_get(const Stack* stack, size_t index, StackElement* result);
bool stack_set(Stack* stack, size_t index, const StackElement* element);
bool stack_swap(Stack* stack, size_t index1, size_t index2);

StackElement* stack_begin(Stack* stack);
StackElement* stack_end(Stack* stack);
const StackElement* stack_const_begin(const Stack* stack);
const StackElement* stack_const_end(const Stack* stack);
StackElement* stack_next(const StackElement* current);
StackElement* stack_prev(const StackElement* current);

bool stack_insert_at(Stack* stack, size_t index, const StackElement* element);
bool stack_remove_at(Stack* stack, size_t index, StackElement* result);

bool stack_reserve(Stack* stack, size_t new_capacity);
bool stack_shrink_to_fit(Stack* stack);