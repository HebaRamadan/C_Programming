/*
 *      Author: Heba Ramadan Taha
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "patient.h"

void Enter_password(void);
u8 Exit_flag = 1;
u8 admin_flag = 1;
u8 user_flag = 1;

u8 value;
u8 i =1;
patient arr[10];
slot array_slots[5];

int main(void){
	u8 index;
	u8 index_admin;
	u8 index_user;
	while(Exit_flag == 1){
		printf("To choice admin mode enter 1\n");
		printf("To choice user mode enter 2\n");
		printf("To exit program 3\n");
		printf("Your choice : ");
		scanf("%d",&index);
		switch(index){
			case 1:
				Enter_password();
				while(admin_flag == 1 && Exit_flag == 1){
					printf("To add patient 1\n");
					printf("To edit patient 2\n");
					printf("To print info_patient 3\n");
					printf("To reserve slot 4\n");
					printf("To cancel reserve 5\n");
					printf("To View reservation 6\n");
					printf("To exit from Admin mode 7\n");
					printf("Your choice : ");
					scanf("%d",&index_admin);
					switch(index_admin){
						case 1:
						    printf("\n");
							printf("Enter information obout patient %d\n",i);
							add_patient();
							printf("\n\n");
							i++;
						break;
						
						case 2:
							edit_patient();
							printf("\\n");
						break;	
					
						case 3:
							print_patient();
							printf("\n");
							break;
						
						case 4:
						    value =available_slot();
							if(value == 0){
								printf("\n");
								break;
							}
						    add_slot();
							printf("\n");
							break;
							
						case 5:
							cancel_reservation();
							printf("\n");
							break;
							
						case 6:
							view_reservation();
							printf("\n");
							break;
						
						case 7:
							admin_flag = 0;
							printf("\n");
							break;
						

						default :
							printf("wrong index\n");
						
				    }
				}
			break;
			
			case 2:
				printf("\n                Hello in USER Mode (:\n");
				while(user_flag == 1 && Exit_flag == 1){
					printf("To View Patient Record 1\n");
					printf("To View Reservation 2\n");
					printf("To exit from User mode 3\n");
					printf("Your choice : ");
					scanf("%d",&index_user);
					switch(index_user){
						case 1:
							view_record();
							printf("\n");
							break;
						case 2:
							view_reservation();
							printf("\n");
							break;
						case 3:
								user_flag=0;
								break;
						default :
							printf("wrong index\n");	
				    }
				}
			break;
			
			case 3:
				Exit_flag = 0;
			break;
			
			default :
			printf("wrong index\n");
		}
		
	}
	
}