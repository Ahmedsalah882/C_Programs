#include <stdio.h>
//#include "Dynamic_Stack/D_stack.h"
#include "Singly_Linked_List/S_LinkedList.h"


struct node* ListHead=NULL;
uint32 len=0;
int main(void)
{
  uint8 l_option=0;  
  while (1)
  {
    printf("-------------------------------->\n");
    printf("please select one of these options:\n");
    printf("option1: insert node at the beginning\n");
    printf("option2: insert node at the end\n");
    printf("option3: insert node After(the first node number is:1 )\n");
    printf("option4: insert node before(the first node number is:1 )\n");

    printf("option5: delete node at the beginning\n");
    printf("option6: delete node at the end\n");
    printf("option7: delete node After(the first node number is:1 )\n");
    printf("option8: delete node before(the first node number is:1 )\n");

    printf("option9: diplay all nodes \n");
    printf("option10: get the length of linked list \n");
    
    printf("option11: Quit the application\n");
    
    printf("-------------------------------->\n");
    scanf("%i",&l_option);
    switch (l_option)
    {
    case 1:
        Insert_node_At_Beginning(&ListHead);
       // Insert_node_At_Beginning(&ListHead,44);
        break;
    case 2:
        Insert_node_At_End(&ListHead);
        break;
    case 3:
        Insert_node_After(ListHead,1);
        break;        
    case 4:
        Insert_node_Before(&ListHead,3);
        break;
    case 5:
        Delete_node_At_Beginning(&ListHead);
        break;
    case 6:
        Delete_node_At_End(&ListHead);
        break;
    case 7:
        Delete_node_After(ListHead,2);
        break;
    case 8:
        Delete_node_Before(&ListHead,3);
        break;
    case 9:
        Display_All_Nodes(ListHead);
        break;
    case 10:
        len=Get_Linked_List_Length(ListHead);
        printf("len=%i\n",len);
        break;
    case 11:
        printf("Quitting the application......\n");
        exit(1);
        break;
    default:
        printf("Invalid option Number !!!\n");
        break;
    }
  }
  
    return 1;
}


