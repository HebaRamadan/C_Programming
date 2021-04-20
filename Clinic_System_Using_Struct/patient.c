/*
 *      Author: Heba Ramadan Taha
 */

#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "patient.h"
extern patient arr[10];
extern slot array_slots[5];
u8 n = 1;
u8 reserve = 1;

void add_patient(void){
	patient* ptr;
    ptr = arr;
	static u8 i =0;
	u32 x;
	for(i ; i<n; i++){
		printf("name of patient : ");
		scanf("%s",&((ptr+i)->name));
		printf("age of patient : ");
		scanf("%d",&((ptr+i)->age));
		printf("gender of patient : ");
		scanf("%s",&((ptr+i)->gender));
		if(n==1){
			printf("ID of patient : ");
			scanf("%d",&((ptr+i)->ID));
		}
		else{
			printf("ID of patient : ");
			scanf("%d",&((ptr+i)->ID));
			x = search_ID((ptr+i)->ID);
			while(x==1){
				printf("Rejected ID\n");
				printf("Please Enter another ID : ");
			    scanf("%d",&((ptr+i)->ID));
			    x = search_ID((ptr+i)->ID);			
			}
		}
	}
	n++;
}


u32 search_ID(u32 id){
	patient* ptr;
    ptr = arr;
	u8 i;
	u8 flag =0;
	for(i=0; i<(n-1); i++){
		if((ptr+i)->ID == id){
			flag = 1;
			break;
		}
	}
	if(flag ==1){
		return 1;
	}
	else{
		return 0;
	}
}


void edit_patient(void){
	patient* ptr;
	patient* pttr;
    ptr = arr;	
	u8 flag =0;
	u8 flag_edit =1;
	u8 index;
	u8 i;
	u8 j;
	u32 id;
	if(n>1){
		printf("Enter ID for patient : ");
		scanf("%d",&id);
		for(i=0; i<(n-1); i++){
			if((ptr+i)->ID == id){
				flag = 1;
				pttr = ptr+i;
				break;
			}		
		}
		if(flag ==1){
			while(flag_edit == 1){
				printf("To edit name    1\n");
				printf("To edit age       2\n");
				printf("To edit gender  3\n");
				printf("To confirm edit 4\n");
				printf("you choice : ");
				scanf("%d",&index);
				switch(index){
					case 1:
						for(j=0; j<MAX; j++){
							pttr->name[j] = 0; 
						}
						printf("new name of patient : ");
						scanf("%s",&(pttr->name));
					    break;
					case 2:
						pttr->age =0;
						printf("Enter age of patient : ");
						scanf("%d",&(pttr->age));
						break;
					case 3:
						for(j=0; j<MAX; j++){
							pttr->gender[j] = 0; 
						}
						printf("Enter gender of patient : ");
						scanf("%s",&(pttr->gender));	
						break;
				    case 4:
						printf("\n\n");
						flag_edit =0;
						break;
					default :
						printf("invalid choice");
				}
			}		
		}
		else{
			printf("Incorrect ID\n");
			printf("........................................................................\n");		
		}
	}
	else{
		printf("no patient added\n\n");
	}
}


void print_patient(void){
	patient* ptr;
    ptr =arr;	
	u8 i;
	for(i=0; i<(n-1); i++){
		printf("\n");
		printf("information of patient %d\n",i+1);
		printf("name of patient : %s\n",(ptr+i)->name);
		printf("age    of patient : %d\n",(ptr+i)->age);
		printf("gender of patient : %s\n",(ptr+i)->gender);
		printf("ID of patient : %d\n",(ptr+i)->ID);
		printf("\n");
	}
}

void add_slot(void){
	static u8 i =0;
	u32 x;
	u32 y;
	u32 z;
	u8   j;

	for(i ; i<reserve; i++){
		printf("Enter ID of patient : ");
		scanf("%d",&array_slots[i].ID);
		x = search_ID(array_slots[i].ID);
		z = search_ID_slot(array_slots[i].ID);
		while(x !=1 | z==1){
			if(x !=1 ){
				printf("Rejected ID\n");
				printf("Please Enter another ID : ");
				scanf("%d",&array_slots[i].ID);
				x = search_ID_slot(array_slots[i].ID);
			}
		    if( z ==1){
				printf("This ID already has an slot\n");
				printf("Please Enter another ID : ");
				scanf("%d",&array_slots[i].ID);
				z = search_ID(array_slots[i].ID);					
			}
			x = search_ID(array_slots[i].ID);
			z = search_ID_slot(array_slots[i].ID);
		}

		if(reserve ==1){
			printf("Enter the slot :");
			scanf("%d",&array_slots[i].times);
		}
		else{
			printf("Enter the slot :");
			scanf("%d",&array_slots[i].times);
			y = search_slot(array_slots[i].times);
		    while(y ==1){
				printf("Aready Reserved Slot\n");
				printf("Please Enter another Slot : ");
				scanf("%d",&array_slots[i].times);
				y = search_slot(array_slots[i].times);			
			}			
		}
	}
	reserve ++;
}
void print_time(u8 i){
	if(i==1)
		printf("2 : 2.30\n");
	else if(i==2)
		printf("2.30 : 3\n");
	else if(i==3)
		printf("3 : 3.30\n");
	else if(i==4)
		printf("4 : 4.30\n");
	else
		printf("4.30 : 5\n");
}

u8 available_slot(void){
	u8 i;
	u8 j;
	u8 n=0;
	printf("available_slots :\n");
	if(reserve ==1){
		for(i=1; i<=5; i++){
			printf("slot %d  At  ",i);
			print_time(i);
		}
	}
	else{
		for(i=1; i<=5; i++){
			u8 flag =0;
			for(j=0; j<5; j++){
				if(array_slots[j].times == i){
					flag =1;
					n++;
					break;
				}	
			}
		    if(flag==1){
				continue;
			}
			else{
				printf("slot %d  At  ",i);
				print_time(i);
			}
		}

		if(n==5){
			printf("ALL slot reserved\n");
			return 0;
		}	
	}		
}
u32 search_slot(u32 slot){
	u8 i;
	u8 flag =0;
	for(i=0; i<(reserve-1); i++){
		if(array_slots[i].times == slot){
			flag = 1;
			break;
		}
	}
	if(flag ==1){
		return 1;
	}
	else if(flag == 0 && slot>5 ){
		printf("Not available slots\n");
		return 2;
	}
	else
		return 0;	
}

u32 search_ID_slot(u32 id){
	u8 i;
	u8 flag =0;
	for(i=0; i<(reserve-1); i++){
		if(array_slots[i].ID == id){
			flag = 1;
			break;
		}
	}
	if(flag ==1){
		return 1;
	}
	else{
		return 0;
	}	
}


void cancel_reservation(void){
	u32 id;
	u32 x;
	u8 i;
	printf("Cancel Reservation :\n");
	if(reserve ==1){
		printf("No Slot reserved to cancel it\n");
		}
	else{
		u8   flag = 0;
		printf("Enter ID :");
		scanf("%d",&id);
		for(i=0; i<(reserve-1); i++){
			if(array_slots[i].ID == id){
				flag =1;
				break;
			}
		}
		if(flag == 1){
			array_slots[i].times =0;
			array_slots[i].ID      =0;
		}
		else{
			printf("This ID not existing in reservation\n");
		}
	}
}
//for user mode
void view_record(void){
	if(n==1){
		printf("NO Patient recorded\n");
	}
	else{
		patient* ptr;
		u32 id;
		u8 i;
		u8 flag =0;
		ptr = arr;
		printf("enter patient ID :");
		scanf("%d",&id);
		for(i=0; i<(n-1); i++){
			if((ptr+i)->ID == id){
				flag = 1;
				break;
			}
		}
		if(flag ==1){
			printf("information of patient\n");
			printf("name of patient : %s\n",(ptr+i)->name);
			printf("age    of patient : %d\n",(ptr+i)->age);
			printf("gender of patient : %s\n",(ptr+i)->gender);		
		}
		else{
			printf("Not available ID\n");
		}
	} 
	
}

void view_reservation(void){
	if(reserve==1){
		printf("No Slots Reserved");
	}
	else{
		u8 i;
		u8 k;
		printf("\n\n");
		printf("information about reservation\n");
		for(i=0; i<(reserve-1); i++){
			printf("ID of patient  : %d\n",array_slots[i].ID);
			printf("Slot of patient At ");
			k = array_slots[i].times;
			print_time(k);
			printf("\n");
		}
	}
}