#ifndef _STACK_H_
#define _STACK_H_

/* Section: Includes */
#include "../std_types.h"

/* Section: Macro Definitions */
#define Stack_MAX_SIZE          5

#define STACK_EMPTY             -1
#define STACK_FULL              (Stack_MAX_SIZE-1)
/* Section: Data Type Declarations */

typedef struct 
{
  uint32 data[Stack_MAX_SIZE];
  sint32 stack_pointer;
} stack_ds_t;

typedef enum 
{ 
  Stack_Empty, 
  Stack_FULL,
} stack_status_t;



/* Section: Function Prototypes */
std_return stack_init(stack_ds_t * stack);
std_return stack_push(stack_ds_t* stack, uint32 value);
std_return stack_pop(stack_ds_t* stack, uint32* value);
std_return stack_top(stack_ds_t* stack, uint32* value);
std_return stack_size(stack_ds_t* stack, uint32* size);
std_return stack_display(stack_ds_t* stack,sint16 select);

#endif