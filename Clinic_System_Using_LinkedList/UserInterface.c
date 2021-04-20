/*
 *      Author: Heba Ramadan Taha
 */

#include <stdio.h>
#include <stdlib.h>
#include  "StdTypes.h"
#include  "SingleLinkedList.h"
#include  "UserInterface.h "
#define   NUM_OF_SLOTS    5

u8 	* Name[1]      ;

/* Enter and Check Password */
u8 	CheckPassword( void)
{
	u8 counter         = 0;
	u8 flag		          = 0;
	u32 input_value = 0;
	
	printf("Please Enter Password	: ");
	scanf("%d",&input_value);
	for(counter=1;  counter<3;  counter++)
	{
		if(input_value == 1234)
		{
			flag =1;
			break;
		}
		printf("\nIncorrect Password\nPlease try again	: ");
		scanf("%d",&input_value);	
	}
	if(flag == 1){
		printf("correct password\n");
		return 0;
	}
	else{
		printf("xxxxxxxxxxxxxxxxxsorry program closed ):\n ");
		return 1;
	}

}

/* Add new patient */
Node * AddPatientRecord     ( Node * Start )
{
	u8		Gender = 0	;
	u8		Age		= 0	;
	u32		Id			= 0	;
	printf("***************************\n");
	/* first patient */
	if( Start == NULL )
	{
		/* ask user to enter name 	*/
		printf("Enter Name	:  ");
		scanf("%[^\n]", Name);    //scan string from user till \n
		getchar(); 
		
		/* ask user to enter age		*/
		printf("Enter Age	:  ");
		scanf("%d"   , &(Age));
		getchar();             //to ignore Buffer
	
		/* ask user to enter gender 	*/
		printf("Enter Gender	:  ");
		scanf("%c"   , &Gender);
		getchar();          //to ignore Buffer
		
		/* ask user to enter ID 		*/
		printf("Enter ID	:  ");
		scanf("%d"   , &(Id) );
		getchar(); 
	
		/* record patient information in system */
		Start = InsertInEmptyList( Start , Name  , Age , Gender , Id );
		printf("***************************\n\n");
		return Start;	
	}
	else
	{
		/* ask user to enter name 	*/
		printf("Enter Name	:  ");
		scanf("%[^\n]", Name);
		getchar();              //to ignore Buffer
	
		/* ask user to enter age		*/
		printf("Enter Age	:  ");
		scanf("%d"   , &(Age));
		getchar();              //to ignore Buffer
	
		/* ask user to enter gender 	*/
		printf("Enter Gender	:  ");
		scanf("%c"   , &Gender);
		getchar();            //to ignore Buffer
		
	
		/* ask user to enter ID 		*/
		printf("Enter ID	:  ");
		scanf("%d"   , &(Id) );
		getchar(); 
		printf("\n");

		Node * ptr = SearchInList(Start , Id);
		
		/* Check Id existed or not */
		while(ptr != NULL)
		{
			/* ask user to enter ID again till enter unique ID  */
			printf("Existed ID  ):  , Please try another ID\n");
			printf("Enter ID again	:	");
			scanf("%d"   , &(Id));
			printf("\n");
			ptr = SearchInList(Start , Id);
		}
	}
	/* record patient information in system */
	InsertAtEnd( Start , Name , Age , Gender , Id );
	printf("***************************\n\n");
	return Start;	
	
}

/* Edit patient information  */
void	EditInformationPatient	( Node * Start )
{
	if(Start == NULL)
	{
		printf("No Recorded patient in system\n");
	}
	else
	{
		u32	Id				= 0	;		
		u8	Gender	= 0	;
		u8	Age			= 0	;
		u8  selection	= 0	;
		
		Node * ptr  = NULL;
		
		/* ask user to enter ID to search   */
		printf("Enter ID to Edit	:  ");
		scanf("%d"   , &(Id));
		
		ptr = SearchInList(Start , Id);
		while(ptr == NULL)
		{
			/* ask user to enter ID and assign at node		*/
			printf("\nNot Valid ID  ):  , Please try another ID\n");
			printf("Enter ID again	:	");
			scanf("%d"   , &(Id));
			ptr = SearchInList(Start , Id);
		}
		printf("\nValid ID  (:");
		printf("\n***************************\n");
		printf("Select option to Edit in patient information\n");
		printf("To Edit name Enter	1\n");
		printf("To Edit age Enter	2\n");
		printf("To Edit gender Enter	3\n");
		printf("To Edit ID Enter	4\n");
		
		/* ask user to enter data to select option		*/
		printf("\nEnter your selection	:  ");
		scanf("%d"   , &selection);
		switch(selection)
		{
			case 1:
				getchar();
				printf("Enter new name	:");
				scanf("%[^\n]", Name);
				ptr -> name = Name;
				break;
				
			case 2:
				printf("Enter new age	:");
				scanf("%d" , &(Age));
				ptr -> age = Age;
				break;
				
			case 3:
				getchar();
				printf("Enter new gender	:");
				scanf("%c" , &Gender);
				getchar();
				ptr -> gender = Gender;
				break;
				
			case 4:
				printf("Enter new ID	:");
				scanf("%d" , &(Id));
				ptr -> ID = Id;
				break;
				
			default :
				printf("\nNot Valid selection :(");
		}
		
		printf("***************************\n");
		
	}
	
}

/* Display  Record for patient in system  */
void    ViewPatientRecord     ( Node * Start )
{
	if( Start == NULL)
	{
		printf("System Empty \n\n");
	}
	else
	{
		u8 Id = 0;
		/* ask user to enter ID to to display record   */
		printf("\nEnter ID to View Recorded information	:  ");
		scanf("%d"   , &(Id)); 
		
		Node * ptr = SearchInList(Start , Id);
		if(ptr == NULL)
		{
			/* user enter incorrect ID		*/
			printf("Not Valid ID  ):  \n");
		}
		else
		{
			printf("***************************\n");

			printf("Information of this patient	:\n"		 );
			printf("name	:  %s\n"  ,    (ptr -> name)	  );
			printf("age	:  %d\n"      ,	(ptr -> age	)	  );
			printf("gender	:  %c\n"  ,	(ptr -> gender) );
			printf("ID	:  %d\n"    	   ,	(ptr -> ID)    	  );
			
			printf("***************************\n");
		}		
	}

}

/* display avaliable slots in system */
void	DisplayAvaliableSlots  	( Node * Start )
{
	printf("***************************\n");
	printf("Avaliable Slots in system :\n");
	for(u8 i=1; i<= NUM_OF_SLOTS; i++)
	{
		Node * temp = Start;
		while(temp != NULL)
		{
			/* check existed slot */
			if(temp -> Slot_State  == i)
			{
				break;
			}
			temp = temp -> Link;
		}
		/* avaliable slot */
		if(temp == NULL)
		{
			printf("Slot_%d	:	",i);
			if(i==1)
			{
				printf("2	->	2:30\n");
			}
			else if(i==2)
			{
				printf("2:30	->	3\n");
			}
			else if(i==3)
			{
				printf("3	->	3:30\n");
			}
			else if(i==4)
			{
				printf("4	->	4:30\n");
			}
			else
			{
				printf("4:30	->	5\n");
			}
		}
	}
	printf("***************************\n");
}

/* reserve patient slot  */
void    ReserveSlotPatient   ( Node * Start	)
{
	/* display avaliable slots in system */
	DisplayAvaliableSlots(Start);
	
	u8 Id = 0;
	/* ask user to enter ID to  reserve slot for patient   */
	printf("\nEnter ID to reserve Slot :  ");
	scanf("%d"   , &(Id));
	getchar();
	
	Node * ptr = SearchInList(Start , Id);
	if(ptr == NULL)
	{
		/* user enter incorrect ID		*/
		printf("Not Valid ID  ):  \n");
	}
	else
	{
		u8 slot_patient = 0;
		/* ask user to enter  reserve slot for patient   */
		printf("Enter Slot to reserve it for patient	:  ");
		scanf("%d"   , &(slot_patient));
		getchar();
		if((slot_patient > 0) && (slot_patient <= NUM_OF_SLOTS))
		{
			Node * temp = SearchSlot(Start , slot_patient);
			if(temp != NULL)
			{
				/* user enter reserved slot for another patient		*/
				printf("you enter reserved slot for another patient  ):  \n");
			}
			else
			{
				/* assign slot to 3m elzeffffffffft :( */
				ptr -> Slot_State = slot_patient;
			}
		}
		else
		{
			printf("Not Valid Slot in system  ):  \n");
		}

	}
	printf("*****************************\n");
}

/* Display Reservation Slots */
void  DisplayReservationSlots( Node * Start )
{
	if( Start == NULL)
	{
		printf("System Empty \n\n");
	}
	else
	{
		printf("***************************\n");
		printf("Reservation of patients today :\n");
		
		Node * temp = Start;
		u8 i = 1;
		while(temp != NULL)
		{
			if( temp -> Slot_State  != No_Slot)
			{
				u8 Reservred_Slot  = temp -> Slot_State;
				printf("Patient_%d :\n",i);
				printf("ID		:  %d\n", temp -> ID);
				printf("Reservred Slot	:  Slot_%d  ", Reservred_Slot);
				if(Reservred_Slot==1)
				{
					printf("2	->	2:30\n\n");
				}
				else if(Reservred_Slot==2)
				{
					printf("2:30	->	3\n\n");
				}
				else if(Reservred_Slot==3)
				{
					printf("3	->	3:30\n\n");
				}
				else if(Reservred_Slot==4)
				{
					printf("4	->	4:30\n\n");
				}
				else
				{
					printf("4:30	->	5\n\n");
				}
				i++;
			}
				temp = temp -> Link;
		}
			printf("***************************\n\n");
	}	

}


/* Cancel Reseravation for patient */
Node * CancelReseravation	( Node * Start )
{
	u8 Id = 0;
	/* ask user to enter ID to  cancel reseravation  for this ID */
	printf("\nEnter ID to  cancel reseravation :  ");
	scanf("%d"   , &(Id));
	
	Node * ptr = SearchInList(Start , Id);
	if(ptr == NULL)
	{
		/* user enter incorrect ID		*/
		printf("Not Valid ID  ):  \n");
	}
	else
	{
		Start = DeleteNode(Start ,  Id);
		
	}
	return Start;
	
}