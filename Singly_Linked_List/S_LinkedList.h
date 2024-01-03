#ifndef _S_LINKED_LIST_H_
#define _S_LINKED_LIST_H_

/* Section: Includes*/

#include "../std_types.h"
#include <stdio.h>
#include <stdlib.h>

/* Section: Data Type Declarations */
struct node
{
    uint32 Node_Data;
    struct node *Node_Link;
};

/* Section: Function Prototypes*/
void Insert_node_At_Beginning(struct node ** list);
void Insert_node_At_End(struct node ** list);
void Insert_node_After(struct node * list,uint32 position);
void Insert_node_Before(struct node ** list,uint32 position);

void Delete_node_At_Beginning(struct node ** list);
void Delete_node_At_End(struct node ** list);
void Delete_node_After(struct node * list,uint32 position);
void Delete_node_Before(struct node ** list,uint32 position);

void Display_All_Nodes(struct node *list);
uint32 Get_Linked_List_Length(struct node* list);


#endif