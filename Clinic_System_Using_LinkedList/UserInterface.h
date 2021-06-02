/*
 *      Author: Heba Ramadan Taha
 */

#ifndef   USER_INTERFACE_H_
#define   USER_INTERFACE_H_

/* for admin mode*/
u8    	CheckPassword		( void		);             //done
Node *	AddPatientRecord	( Node * Start  );      		//done
void	EditInformationPatient  ( Node * Start	);           //done
void	DisplayAvaliableSlots	( Node * Start	);                //done
void	ReserveSlotPatient	( Node * Start	);                //done
Node *	CancelReseravation      ( Node * Start	);                //done


/* for user mode */
void      ViewPatientRecord	 ( Node * Start	);		 //done
void      DisplayReservationSlots( Node * Start	);     		      //done


#endif
