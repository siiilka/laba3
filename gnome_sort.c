#include "stack.h"
#include "comparators.h"

void gnome_sort(Stack* stack, Comparator cmp, bool ascending) 
{
{
    if (!stack || !cmp) return;
    
    size_t n = stack_size(stack);
    if (n <= 1) return;
    
    size_t i = 0;
    
    while (i < n) 
    {
        if (i == 0) 
        {
            i++;
            continue;
        }
        
        StackElement* prev = &stack->data[i - 1];
        StackElement* curr = &stack->data[i];
        
        int comparison = cmp(prev, curr);
        
        if ((ascending && comparison <= 0) || (!ascending && comparison >= 0)) 
        {
            i++;
        } else 
        {
            stack_swap(stack, i - 1, i);
            i--;
        }
    }
}
}
