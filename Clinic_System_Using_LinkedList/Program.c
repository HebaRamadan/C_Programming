/*
 *      Author: Heba Ramadan Taha
 */

#include <stdio.h>
#include <stdlib.h>
#include  "StdTypes.h"
#include  "SingleLinkedList.h"
#include  "UserInterface.h "
#include  "Program.h"

extern u8 Exit_flag  ;  

Node * Start = NULL;

u8 User_Flag  = 0;
u8 input_value =0;

void Admin_Mode(void)
{
	u8 Admin_Mode_Exit_Flag = 0;
	u8 return_val = 0;
	printf("\n*******************You are in admin mode*******************\n");
	/* Enter password && check */
	return_val = CheckPassword();
	if(return_val == 1)
	{
		Exit_flag = 1;
		Admin_Mode_Exit_Flag = 1;
	}
	else
	{
		printf("\n...............Welcome Admin...............\n");
	}

	while(!(Admin_Mode_Exit_Flag ))
	{
		u8 input_value = 0;
		
		printf("To add new patient record pres		:  1\n");
		printf("To edit in patient record press		:  2\n");
		printf("To reserve slot for patient press	:  3\n");
		printf("To cancel  reservation patient press	:  4\n");
		printf("To exit	 admin mode press		:  5\n\n");
		
		printf("Enter your selection	:  ");
		scanf("%d",&input_value);
		printf("\n");
		
		switch( input_value)
		{
			case 1:
				getchar();
				Start = AddPatientRecord(Start);
				break;
				
			case 2:
				EditInformationPatient(Start);
				break;
				
			case 3:
				ReserveSlotPatient(Start);
				break;

			case 4:
				CancelReseravation(Start);
				break;
			
			case 5:
				Admin_Mode_Exit_Flag = 1;
				break;
				
			default :
				printf("Not Valid input\n\n");
		}
	}	
}


void User_Mode(void)
{
	User_Flag = 0;
	
	printf("\n*******************You are in user mode*******************\n");
	
	while(!(User_Flag))
	{
		printf("To View Patient Record Press		:  1\n");
		printf("To Display Reservation Slots Press	:  2\n");
		printf("To Exit	 User Mode press		:  3\n\n");
		
		printf("Enter your selection	:  ");
		scanf("%d",&input_value);
		printf("\n");
		
		switch(input_value)
		{
			case 1:
				ViewPatientRecord(Start);
			break;
			
			case 2:
				DisplayReservationSlots(Start);
			break;
			
			case 3:
				User_Flag = 1;
			break;
			
			default :
				printf("Not Valid input\n\n");
			break;
		}
	}
}