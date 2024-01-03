#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"

#define arr_size    5

sint32 Binary_Search_Algorithm(uint32 Data[],uint32 size,uint32 w_elem);

sint32 ret=0;
uint32 arr[arr_size]={0,2,5,7,9};
int main()
{

    ret=Binary_Search_Algorithm(arr,arr_size,7);
    printf("value=%i\n",ret);

    ret=Binary_Search_Algorithm(arr,arr_size,2);
    printf("value=%i\n",ret);

    ret=Binary_Search_Algorithm(arr,arr_size,0);
    printf("value=%i\n",ret);

    ret=Binary_Search_Algorithm(arr,arr_size,9);
    printf("value=%i\n",ret);

    ret=Binary_Search_Algorithm(arr,arr_size,5);
    printf("value=%i\n",ret);

    ret=Binary_Search_Algorithm(arr,arr_size,10);
    printf("value=%i\n",ret);
  
    return 0;
}

sint32 Binary_Search_Algorithm(uint32 Data[],uint32 size,uint32 w_elem)
{
    uint32 l_index=0,r_index=arr_size-1,value=0,m_index=0;
    while (r_index>=l_index)
    {  
         m_index=(r_index+l_index)/2;
        
        if (arr[m_index]==w_elem)
        {
            value=m_index;
            break;
        }
        else if(arr[m_index]>w_elem )
        {  
            r_index=m_index-1;
        }
        else if (arr[m_index]< w_elem)
        {  
            l_index=m_index+1;
        }   
        value=-1; 
    }
    
    return value;
}
