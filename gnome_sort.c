#include "stack.h"
#include "comparators.h"

void gnome_sort(Stack* stack, Comparator cmp, bool ascending) 
{
    if (stack == NULL || cmp == NULL) 
    {
        return;
    }
    
    size_t n = stack_size(stack);
    if (n <= 1) 
    {
        return; 
    }
    
    size_t i = 0;
    
    while (i < n) 
    {
        if (i == 0) 
        {
            i++;
            continue;
        }
        
        //Publication prev = stack_get (stack, i-1);
        //Publication curr = stack_get (stack, i);
        
        //if (cmp(&prev, &curr) <= 0) 
        //{
        //    i++;
        //} else 
        //{
        //    stack_swap(stack, i-1, i);
        //   if (i > 0) 
        //    {
        //       i--;
        //    }
        //}
    }
    
    if (!ascending) 
    {
        for (size_t j = 0; j < n/2; j++) 
        {
            stack_swap(stack, j, n-1-j);
        }
    }
}