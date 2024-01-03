#ifndef _D_STACH_H_
#define _D_STACH_H_

/* Section: Includes */
#include "../std_types.h"
#include <stdio.h>
#include <stdlib.h>
/* Section: Macro Definitions */

/* Sdction: Data Type Declarations */
typedef struct
{
    void **stack_Array;
    uint32 stack_max_size;
    uint32 stack_num_elements;
    uint32 stack_Top;
} d_stack_t;

typedef enum
{
    STACK_EMPTY,
    STACK_FULL,
    STACK_NULL
} stack_status_t;

/* Section: Function Prototypes */
/**
 * @brief create the stack with dynamic size
 * @param statuts
 * @param stack_size
 * @return pointer to the created stack
 *         
 */

d_stack_t* Stack_create(uint32 stack_size, stack_status_t* status);

/**
 * @brief Destroy the stack 
 * @param stack
 * @return status of the function:
 *         E_OK: the function executed successfully
 *         E_NOT_OK: the function failed
 */

std_return Stack_Destroy(d_stack_t* stack);
/**
 * @brief add new element to the stack 
 * @param stack
 * @param element_ptr
 * @return status of the function:
 *         E_OK: the function executed successfully
 *         E_NOT_OK: the function failed
 */

std_return Stack_Push(d_stack_t* stack, void* element_ptr);
/**
 * @brief Remove the last element from the stack and return it through pointer 
 * @param stack
 * @param element_ptr
 * @return status of the function:
 *         E_OK: the function executed successfully
 *         E_NOT_OK: the function failed
 */

std_return Stack_Pop(d_stack_t* stack, void* element_ptr);
/**
 * @brief  return top element from stack through pointer without removing it 
 * @param stack
 * @param element_ptr
 * @return status of the function:
 *         E_OK: the function executed successfully
 *         E_NOT_OK: the function failed
 */

std_return Stack_Top(d_stack_t* stack,void* stack_top);
/**
 * @brief return current number of elements of stack through pointer 
 * @param stack
 * @param stack_size
 * @return status of the function:
 *         E_OK: the function executed successfully
 *         E_NOT_OK: the function failed
 */
std_return Stack_Size(d_stack_t* stack, uint32* stack_size);
/**
 * @brief Display all stack content is select was equal to -1
 *        or display specific element depending on the value of select 
 * @param stack
 * @param selsect
 * @return status of the function:
 *         E_OK: the function executed successfully
 *         E_NOT_OK: the function failed
 */
std_return Stack_Display(d_stack_t* stack, uint32 select);


#endif