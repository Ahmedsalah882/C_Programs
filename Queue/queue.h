#ifndef _QUEUE_H_
#define _QUEUE_H_

/* Section: Includes */
#include "../std_types.h"
#include <stdio.h>
#include <stdlib.h>

/* Section: Macro Definitions */

/* Section: Data Type Declarations */
typedef struct 
{
    void ** Array_Data;
    uint32 Element_Count;
    uint32 Queue_Max_Size;
    sint32 Front;
    sint32 Rear;
}queue_t;

typedef enum
{   QUEUE_EMPTY,
    QUEUE_OK,
    QUEUE_NOT_OK,
    QUEUE_FULL,
    QUEUE_NULL
}queue_status_t;


/* Section: Function Prototypes */

/**
*@brief create a queue with size entered from the user
*@param size
*@param status
*@return a pointer to the created Queue
*/
queue_t* Queue_Create(uint32 size, queue_status_t* status);

/**
*@brief Destroy a queue 
*@param queue
*@return status of the Queue
*        QUEUE_NULL: if a null pointer passed instead of queue pointer
*        QUEUE_OK: if the Queue Destroyed Successfully     
*/
queue_status_t Queue_Destroy( queue_t* queue);

/// @brief insert an item to the queue at the rear
/// @param queue 
/// @param elem_ptr 
/// @return status of the Queue
///         QUEUE_NULL: if a null pointer passed instead of queue pointer
///         QUEUE_OK: if the Queue item inserted Successfully
///         QUEUE_FULL: If the queue is full of items
queue_status_t Enqueue(queue_t* queue, void* elem_ptr);

/// @brief Remove and return the elemet in the front 
/// @param queue 
/// @param elem_ptr 
/// @return status of the Queue
///         QUEUE_NULL: if a null pointer passed instead of queue pointer or address of elem_ptr
///         QUEUE_OK: if the Queue item removed and returned Successfully 
///         QUEUE_EMPTY: if the Queue has no items
queue_status_t Dequeue(queue_t* queue, void** elem_ptr);

/// @brief Return the front item
/// @param queue 
/// @param elem_ptr 
/// @return status of the Queue
///         QUEUE_NULL: if a null pointer passed instead of queue pointer or address of elem_ptr
///         QUEUE_OK: if the Queue front item returned Successfully 
///         QUEUE_EMPTY: if the Queue has no items
queue_status_t Queue_Front(queue_t* queue, void** elem_ptr);

/// @brief Return the rear item
/// @param queue 
/// @param elem_ptr 
/// @return status of the Queue
///         QUEUE_NULL: if a null pointer passed instead of queue pointer or address of elem_ptr
///         QUEUE_OK: if the Queue rear item returned Successfully 
///         QUEUE_EMPTY: if the Queue has no items
queue_status_t Queue_Rear(queue_t* queue, void** elem_ptr);

/// @brief Return the number of elements in the queue 
/// @param queue 
/// @param elem_count 
/// @return status of the Queue
///         QUEUE_NULL: if a null pointer passed instead of queue pointer or address of elem_ptr
///         QUEUE_OK: if the Queue rear item returned Successfully 
///         QUEUE_EMPTY: if the Queue has no items
queue_status_t Queue_Count(queue_t* queue, uint32 * elem_count);


#endif