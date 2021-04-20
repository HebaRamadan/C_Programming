/*
 *      Author: Heba Ramadan Taha
 */

#include <stdio.h>
#include  "StdTypes.h"
#include  "Program.h"

u8 Exit_flag = 0;

int main(void)
{	
	while( !(Exit_flag) )
	{
		u8 input_value = 0;
		printf("\n*******************Clinic System*******************\n");
		
		/* print options in system         */
		printf("To Select Admin Mode Press	:  1\n");
		printf("To Select User Mode Press	:  2\n");
		printf("To Exit	 System press		:  3\n\n");
		
		/*	ask user to enter selection    */
		printf("Select your Mode	:  ");
		scanf("%d",&input_value);
		

		switch( input_value )
		{
			case 1:
				Admin_Mode();
				break;
				
			case 2:
				User_Mode();
				break;
				
			case 3:
				Exit_flag = 1;
				break;
				
			default :
				printf("Not Valid input\n\n");
				
		}
	}
	return 0;
}