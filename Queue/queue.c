#include "queue.h"


static queue_status_t Queue_IsEmpty(queue_t* queue);

static queue_status_t Queue_IsFull(queue_t* queue);

queue_t* Queue_Create(uint32 size, queue_status_t* status)
{
    *status=QUEUE_OK;
    queue_t* queue=NULL;
    if (NULL==status)
    {
        *status=QUEUE_NULL;
    }
    else
    { 
        queue=(queue_t*)malloc(sizeof(queue_t));
        if (NULL== queue)
        {
             *status=QUEUE_NULL;
        }
        else
        {   
            
            queue->Array_Data= (void**) calloc(size,sizeof(void*));
            if (NULL== (queue->Array_Data))
            {
                 *status=QUEUE_NULL;
            }
            else
            { 
            queue->Element_Count=0;
            queue->Queue_Max_Size=size;
            queue->Front=-1;
            queue->Rear=-1;
            }
        }    
    }
    return queue;
}

queue_status_t Queue_Destroy( queue_t* queue)
{   
    queue_status_t status=QUEUE_OK;
    if (NULL== queue)
    {
        status=QUEUE_NULL;
    }
    else
    {
        free(queue->Array_Data);
        free(queue);
    }
    return status;
}

queue_status_t Enqueue(queue_t* queue, void* elem_ptr)
{
    queue_status_t status=QUEUE_OK;
    if (NULL== queue || NULL==elem_ptr)
    {
        status=QUEUE_NULL;
    }
    else
    {
        if (QUEUE_FULL==Queue_IsFull(queue))
        {
           status=QUEUE_FULL;
        }
        else
        {
            
            (queue->Rear)++;
            if (queue->Queue_Max_Size==queue->Rear)
            {
                queue->Rear=0;
            }
            else {/*Nothing*/}
            queue->Array_Data[queue->Rear]=elem_ptr;
            if(queue->Element_Count==0)
            {
                  queue->Front=0;  
            }
            else {/*Nothing*/}
            (queue->Element_Count)++;
            
        }
        
    }
    return status;
}

queue_status_t Dequeue(queue_t* queue, void** elem_ptr)
{
    queue_status_t status=QUEUE_OK;
    if (NULL== queue || NULL==elem_ptr)
    {
        status=QUEUE_NULL;
    }
    else
    {
        if (!Queue_IsEmpty(queue))
        {
            status=QUEUE_EMPTY;
        }
        else
        {   
            if(queue->Element_Count==0)
            {
                queue->Front=-1;
                queue->Rear=-1;
            }
            else 
            {
                *elem_ptr=queue->Array_Data[queue->Front];
                (queue->Front)++;
                if (queue->Queue_Max_Size==queue->Front)
                {
                    queue->Front=0;
                }
                else{/* Nothing*/}
                (queue->Element_Count)--;
            }   
        }
    }
    return status;
}

queue_status_t Queue_Front(queue_t* queue, void** elem_ptr)
{
    queue_status_t status=QUEUE_OK;
    if (NULL== queue || NULL==elem_ptr)
    {
        status=QUEUE_NULL;
    }
    else
    {
        if (!Queue_IsEmpty(queue))
        {
            status=QUEUE_EMPTY;
        }
        else
        {
            *elem_ptr=queue->Array_Data[queue->Front];
        }    
    }
    return status;
}

queue_status_t Queue_Rear(queue_t* queue, void** elem_ptr)
{
    queue_status_t status=QUEUE_OK;
    if (NULL== queue || NULL==elem_ptr)
    {
        status=QUEUE_NULL;
    }
    else
    {
        if (!Queue_IsEmpty(queue))
        {
            status=QUEUE_EMPTY;
        }
        else
        {
            *elem_ptr=queue->Array_Data[queue->Rear];
        }    
    }
    return status;
}

queue_status_t Queue_Count(queue_t* queue, uint32 * elem_count)
{
    queue_status_t status=QUEUE_OK;
    if (NULL== queue || NULL==elem_count)
    {
        status=QUEUE_NULL;
    }
    else
    {   if(!Queue_IsEmpty(queue))
        {
            queue->Element_Count=QUEUE_EMPTY;            
        }
        else
        {
            *elem_count=queue->Element_Count;
        }
    }
    return status;
}

static queue_status_t Queue_IsEmpty(queue_t* queue)
{
    queue_status_t status=QUEUE_OK;
    if (NULL== queue )
    {
        status=QUEUE_NULL;
    }
    else
    {
        if (QUEUE_EMPTY==queue->Element_Count)
        {
           status=QUEUE_EMPTY;
        }
        
    }
    return status;
}

static queue_status_t Queue_IsFull(queue_t* queue)
{
    queue_status_t status=QUEUE_OK;
    if (NULL== queue )
    {
        status=QUEUE_NULL;
    }
    else
    {
        if (queue->Queue_Max_Size==queue->Element_Count)
        {
           status=QUEUE_FULL;
        }
        
    }
    return status;
}


