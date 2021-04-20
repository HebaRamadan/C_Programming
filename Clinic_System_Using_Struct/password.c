/*
 *      Author: Heba Ramadan Taha
 */

#include <stdio.h>
#include "STD_Types.h"
extern u8 Exit_flag ;

void Enter_password(void){
	u8 i ;
	u8 flag =0;
	u32 x;
	printf("Enter Password : ");
	scanf("%d",&x);
	for(i=0; i<2; i++){
		if(x == 1234){
			flag =1;
			break;
		}
	printf("Incorrect Password\nPlease try again : ");
	scanf("%d",&x);	
	}
	if(flag == 1){
		printf("correct password\n");
		printf("\n                Hello in Admin Mode (:\n");
	}
	else{
		printf("sorry program closed ):\n ");
		Exit_flag = 0;
	}

}	
	
