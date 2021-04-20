/*
 *      Author: Heba Ramadan Taha
 */
 
#include <stdio.h>
#include <stdlib.h>
#include  "StdTypes.h"
#include  "SingleLinkedList.h"


/* Insert new node in empty list 											*/
Node * InsertInEmptyList(Node * Start , u8 ** Name ,  u8 Age , u8  Gender , u32   Id)
{
	/* create new node 										*/
	Node * temp = (Node *)malloc(sizeof(Node));
	
	/* assign values in new node */
	temp -> name			= Name  	;
	temp -> age			= Age		;
	temp -> gender		= Gender	;
	temp -> ID				= Id	   		;
	temp -> Slot_State	= No_Slot	;
	
	/*  exchange links to save addresses				*/
	Start = temp;
	temp->Link = NULL;
	
	return Start;
}


/* Insert new node at the end of list										*/
void     InsertAtEnd(Node * Start , u8 ** Name ,  u8 Age , u8  Gender , u32   Id)
{
	Node * ptr = NULL;
	
	/* create new node 										*/
	Node * temp = (Node *)malloc(sizeof(Node));
	
	/* assign values in new node */
	temp -> name  		= Name  	;
	temp -> gender 		= Gender	;
	temp -> age     		= Age		;
	temp -> ID      		= Id			;
	temp -> Slot_State	= No_Slot	;
	
	temp->Link = NULL;
	
	/* loop to the end node in list						*/
	ptr = Start;
	while(ptr -> Link != NULL)
	{
		ptr = ptr -> Link;
	}
	ptr -> Link = temp;
}


/* search about ID in list	and return address of this value in list	*/
Node * SearchInList	(Node * Start , u32 Value )
{
	Node * temp = Start;
		
	/* search about ID in List */
	while(temp != NULL )
	{
		if(temp -> ID == Value)
		{
			break;
		}
		temp = temp -> Link;
	}
	if(temp == NULL)
	{
		return NULL;
	}
	return temp;
	
}

/* delete node in list															*/
Node * DeleteNode(Node * Start , u32 Value )
{
	Node * temp;
	Node * ptr;
	if(Start == NULL)
	{
		printf("The List is empty\n\n");
		return Start;
	}
	/* Case 2 Node is the First Node */
	if(Start -> ID == Value)
	{
		temp  = Start;
		Start = Start->Link;
		free(temp);
		temp = NULL;
		return Start;
	}
	ptr = Start;
	while(ptr->Link != NULL)
	{
		if(ptr->Link->ID == Value)
			break;
		ptr = ptr ->Link;
	}
	if(ptr->Link == NULL)
	{
		printf("Element %d is not found in the List\n\n",Value);
	}
	else
	{
		temp = ptr->Link;
		ptr->Link = temp->Link;
		free(temp);
	}
	return Start;
}


/* search about Slot in list and return address of this value in list	*/
Node * SearchSlot(Node * Start , Slots    Slot	    )
{
	Node * temp = Start;
		
	/* search about Slot in List */
	while(temp != NULL )
	{
		if(temp -> Slot_State == Slot)
		{
			break;
		}
		temp = temp -> Link;
	}
	if(temp == NULL)
	{
		return NULL;
	}
	return temp;
}