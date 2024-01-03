#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


static std_return  stack_empty(stack_ds_t* stack);
static std_return  stack_full(stack_ds_t* stack);

/**
 * 
 * @param stack
 * @return status of the function:
 *         E_OK: the function executed successfully
 *         E_NOT_OK: the function failed
 */
std_return stack_init(stack_ds_t * stack)
{std_return ret=E_OK;
    if(NULL== stack)
    {
        ret=E_NOT_OK;
    }
    else
    {
        uint8 l_stack_counter=0;
        stack->stack_pointer=-1;
        for(l_stack_counter=0;l_stack_counter<Stack_MAX_SIZE;l_stack_counter++)
        {
            stack->data[l_stack_counter]=0;
        }
        
    }
    return ret;
}
/**
 * 
 * @param stack
 * @param value
 * @return status of the function:
 *         E_OK: the function executed successfully
 *         E_NOT_OK: the function failed
 */
std_return stack_push(stack_ds_t* stack, uint32 value)
{
    std_return ret=E_OK;
    if(NULL== stack)
    {
        ret=E_NOT_OK;
    }
    else
    {
        ret=stack_full(stack);
        if (E_NOT_OK==ret || STACK_FULL==stack_full(&stack))
        {
            ret=E_NOT_OK;
        }
        else
        {
            stack->stack_pointer++;
            stack->data[stack->stack_pointer]=value;
        }
        
    }
    return ret;
}

/**
 * 
 * @param stack
 * @param value
 * @return status of the function:
 *         E_OK: the function executed successfully
 *         E_NOT_OK: the function failed
 */
std_return stack_pop(stack_ds_t* stack, uint32* value)
{
    std_return ret=E_OK;
    if(NULL== stack || NULL==value || STACK_EMPTY==stack_empty(&stack))
    {
        ret=E_NOT_OK;
    }
    else
    {
        ret=stack_empty(stack);
        if (E_NOT_OK==ret)
        {
            ret=E_NOT_OK;
        }
        else
        {
            *value=stack->data[stack->stack_pointer];
            stack->stack_pointer--;
        }
           
    }
    return ret;
}
/**
 * 
 * @param stack
 * @param value
 * @return status of the function:
 *         E_OK: the function executed successfully
 *         E_NOT_OK: the function failed
 */
std_return stack_top(stack_ds_t* stack, uint32* value)
{
    std_return ret=E_OK;
    if(NULL== stack || NULL==value || STACK_EMPTY==stack_empty(&stack))
    {
        ret=E_NOT_OK;
    }
    else
    {
        *value=stack->data[stack->stack_pointer];
    }
    return ret;
}

/**
 * 
 * @param stack
 * @param size
 * @return status of the function:
 *         E_OK: the function executed successfully
 *         E_NOT_OK: the function failed
 */
std_return stack_size(stack_ds_t* stack, uint32* size)
{
    std_return ret=E_OK;
    if(NULL== stack || NULL==size)
    {
        ret=E_NOT_OK;
    }
    else
    {
       // *size= (*(&(stack->data)+1)) - stack->data;
       *size=++stack->stack_pointer;
    }
    return ret;
}

/**
 * 
 * @param stack
 * @param select
 * @return status of the function:
 *         E_OK: the function executed successfully
 *         E_NOT_OK: the function failed
 */
std_return stack_display(stack_ds_t* stack,sint16 select)
{
    std_return ret=E_OK;
    if(NULL== stack || STACK_EMPTY==stack_empty(&stack) )
    {
        ret=E_NOT_OK;
    }
    else
    {
        uint16 l_stack_counter=ZERO_INIT;
        if (-1==select)
        {
            for (l_stack_counter = 0; l_stack_counter < stack->stack_pointer; l_stack_counter++)
            {
                printf("stack_element_%i= %i\n",l_stack_counter,stack->data[l_stack_counter]);
            }
        }
        else
        {
                printf("stack_element_%i= %i\n",select,stack->data[select]);
        }
        
        
    }
    return ret;

}
/**
 * 
 * @param stack
 * @return status of the function and stack:
 *         E_OK: the function executed successfully
 *         E_NOT_OK: the function failed or stack is empty
 */
static std_return  stack_empty(stack_ds_t* stack)
{   
    std_return ret=E_OK;
    if(NULL== stack)
    {
        ret=E_NOT_OK;
    }
    else
    {
        if(STACK_EMPTY==stack->stack_pointer)
        {
            ret= E_NOT_OK;
        }
        else
        {
            ret= E_OK;
        }
    }
    return ret;
}
/**
 * 
 * @param stack
 * @return status of the function and stack:
 *         E_OK: the function executed successfully
 *         E_NOT_OK: the function failed or stack is full
 */
static std_return  stack_full(stack_ds_t* stack)
{
    std_return ret=E_OK;
    if(NULL== stack)
    {
        ret=E_NOT_OK;
    }
    else
    {
        if(STACK_FULL==stack->stack_pointer)
        {
            ret= E_NOT_OK;
        }
        else
        {
            ret= E_OK;
        }
    }
    return ret;
}
