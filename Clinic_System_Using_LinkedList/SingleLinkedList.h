/*
 *      Author: Heba Ramadan Taha
 */
#ifndef   SINGLELINKEDLIST_H_
#define  SINGLELINKEDLIST_H_


typedef enum  slots
{
	No_Slot	,
	Slot_1		,
	Slot_2 		,
	Slot_3 		,
	Slot_4 		,
	Slot_5 	
}Slots;


typedef struct node
{
	u8			age		;
	u8			gender ;
	u32		    ID		;
	u8   **	name	;
	Slots        Slot_State;
	struct node * Link    ;
}Node;

/* Prototypes for single Linked List Functions */
Node * InsertInEmptyList		(Node * Start , u8 ** Name   ,  u8 Age , u8  Gender , u32   Id);
void     InsertAtEnd              	(Node * Start , u8 ** Name   ,  u8 Age , u8  Gender , u32   Id);
Node * SearchInList				(Node * Start , u32 Value 	    );
Node * SearchSlot			    	(Node * Start , Slots    Slot	    );
Node * DeleteNode 				(Node * Start , u32 Value 	    );




#endif