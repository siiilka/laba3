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
