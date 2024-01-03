#include "S_LinkedList.h"


void Insert_node_At_Beginning(struct node ** list)
{
    struct node* temp_node=NULL;
    uint32 Data=0;
    temp_node=(struct node *)malloc(sizeof(struct node));
    if(temp_node==NULL)
    {
     printf("couldn`t allcote the node\n");   
    }
    else
    {   
        printf("enter the data:");
        scanf("%i",&Data);
        if(*list==NULL) //linked list is empty
        {
            temp_node->Node_Data=Data;
            *list=temp_node;
            temp_node->Node_Link=NULL;
        }
        else
        {   
            temp_node->Node_Data=Data;
            temp_node->Node_Link=*list;
            *list=temp_node;
        }
    }
}

void Insert_node_At_End(struct node ** list)
{
    struct node * temp_node=NULL;
    struct node * node_counter_list=NULL;
    uint32 Data;
    temp_node=(struct node*)malloc(sizeof(struct node));
    if (NULL==temp_node)
    {
        printf("couldn`t allcote the node\n"); 
    }
    else
    {
        printf("enter the data:");
        scanf("%i",&Data);
        if(NULL==*list)
        {
            temp_node->Node_Data=Data;
            *list=temp_node;
            temp_node->Node_Link=NULL;
        }
        else
        {
            node_counter_list=*list;
            while (node_counter_list->Node_Link !=NULL) // traverse through the last node
            {
                node_counter_list=node_counter_list->Node_Link;
            }
            temp_node->Node_Link=NULL;
            temp_node->Node_Data=Data;
            node_counter_list->Node_Link=temp_node;
        }
    }

}

void Insert_node_After(struct node * list,uint32 position)
{
    struct node* temp_node=NULL;
    struct node* node_counter=NULL;
    if (NULL==list)
    {
        printf("Linked list is EMPTY or null pointer is entered !!! \n");  
    }
    else
    {   uint32 counter=1,len=0,Data=0;
        temp_node=(struct node*)malloc(sizeof(struct node));
        if(NULL== temp_node)
        {
             printf("couldn`t allcote the node\n");       
        }
        else
        {
            node_counter=list;
            len=Get_Linked_List_Length(list);
            printf("enter the data:");
            scanf("%i",&Data);
            temp_node->Node_Data=Data;
            while (counter< position)
            {
                counter++;
                node_counter=node_counter->Node_Link;
            }
            if(position==len)
            {
                temp_node->Node_Link=NULL;
                node_counter->Node_Link=temp_node;    

            }
            else if (position<len)
            {
                temp_node->Node_Link=node_counter->Node_Link;
                node_counter->Node_Link=temp_node;
            }
            else
            {
               printf("Linked list hasn`t reached to this number of nodes !!! \n");
            }
        }
    }
    
}

void Insert_node_Before(struct node ** list,uint32 position)
{
     struct node* temp_node=NULL;
    struct node* node_counter=NULL;
    if (NULL==*list)
    {
        printf("Linked list is EMPTY or null pointer is entered !!! \n");  
    }
    else
    {   uint32 counter=1,len=0,Data=0;
        temp_node=(struct node*)malloc(sizeof(struct node));
        if(NULL== temp_node)
        {
             printf("couldn`t allcote the node\n");       
        }
        else
        {
            node_counter=*list;
            len=Get_Linked_List_Length(*list);
            printf("enter the data:");
            scanf("%i",&Data);
            temp_node->Node_Data=Data;
            while (counter< position-1)
            {
                counter++;
                node_counter=node_counter->Node_Link;
            }
            if(position==1)
            {
                temp_node->Node_Link=*list;
                *list=temp_node;    

            }
            else if (position<len)
            {
                temp_node->Node_Link=node_counter->Node_Link;
                node_counter->Node_Link=temp_node;
            }
            else
            {
               printf("Linked list hasn`t reached to this number of nodes !!! \n");
            }
        }
    }
    
}

void Delete_node_At_Beginning(struct node ** list)
{
    struct node * temp_node=NULL;
    if(NULL== *list)
    {
        printf("Linked list is empty or null pointer is entered !!! \n"); 
    }
    else
    {
        temp_node=*list;
        *list=temp_node->Node_Link;
        free(temp_node);
        temp_node=NULL;
    }    
}


void Delete_node_At_End(struct node ** list)
{
    struct node * node_counter_list=NULL;
    struct node * node_counter_list_two=NULL;
    if(NULL== (*list)->Node_Link) // only  one node exists
    {
        free(*list);
        *list=NULL; 
    }
    else
    {  
    node_counter_list=*list;
    while (node_counter_list->Node_Link !=NULL)
    {   
        node_counter_list_two=node_counter_list;
        node_counter_list=node_counter_list->Node_Link;
    }
    free(node_counter_list);
    node_counter_list_two->Node_Link=NULL;
    node_counter_list=NULL;
    }
}

void Delete_node_After(struct node * list,uint32 position)
{
    struct node * node_counter_one=NULL;
    struct node* node_counter_two=NULL;
    uint32 counter=1,len=0;
    len=Get_Linked_List_Length(list);
    node_counter_one=list;
    while (counter< position)
    {
        counter++;
        node_counter_one=node_counter_one->Node_Link;
    }
    if(position==len)
    {
        free(node_counter_one->Node_Link);
        node_counter_one->Node_Link=NULL;
    }
    else if (position< len)
    {
        node_counter_two=node_counter_one->Node_Link;
        node_counter_one->Node_Link=node_counter_two->Node_Link;
        free(node_counter_two);
        node_counter_two=NULL;
    }
    else
    {
         printf("Linked list hasn`t reached to this number of nodes !!! \n");
    }
    
    

}

void Delete_node_Before(struct node ** list,uint32 position)
{
    struct node * node_counter_one=NULL;
    struct node* node_counter_two=NULL;
    uint32 counter=1,len=0;
    len=Get_Linked_List_Length(*list);
    node_counter_one=*list;
    while (counter< position-2)
    {
        counter++;
        node_counter_one=node_counter_one->Node_Link;
    }
    if(position-1==1)
    {   printf("entered1");
        *list=node_counter_one->Node_Link;
        free(node_counter_one);
        node_counter_one=NULL;
        
    }
    else if (position <= len )
    {   
        node_counter_two=node_counter_one->Node_Link;
        node_counter_one->Node_Link=node_counter_two->Node_Link;
        free(node_counter_two);
        node_counter_two=NULL;
    }
    else 
    {   
        printf("Linked list hasn`t reached to this number of nodes !!! \n");
    }
    
    
}

void Display_All_Nodes(struct node *list)
{
    struct node * NodeListCounter=NULL;
    if(NULL== list)
    {
        printf("Invalid address NULL pointer entered or Empty linked list !!!!");
    }
    else
    {
        NodeListCounter=list;
        printf("data id=");
        printf("%i-->",NodeListCounter->Node_Data);
        while (NodeListCounter->Node_Link != NULL)
        {
            NodeListCounter=NodeListCounter->Node_Link;
            printf("%i-->",NodeListCounter->Node_Data);
        }
        printf("NULL\n");
        
    }
}

uint32 Get_Linked_List_Length(struct node* list)
{
uint32 l_counter=1;
    struct node * NodeListCounter=NULL;
    if(NULL== list)
    {
        printf("Linked list is empty or null pointer is entered !!! \n");
        l_counter=0;
    }
    else
    {
        NodeListCounter=list;
        while (NodeListCounter->Node_Link != NULL)
        {
            l_counter++;
            NodeListCounter=NodeListCounter->Node_Link;
        }
       
    }
    return  l_counter;
}




