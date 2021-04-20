/*
 *      Author: Heba Ramadan Taha
 */

#ifndef _PATIENT_H
#define _PATIENT_H
#define MAX 100	
typedef struct patient patient;
typedef struct slot slot;

struct patient{
	u32 name[MAX];
	u32 ID;
	u32 gender[MAX];
	u32 age;
};

struct slot{
	u32 ID;
	u32 times;
};

void add_patient(void);
void print_patient(void);
u32 search_ID(u32 id);
void edit_patient(void);
void add_slot(void);
void print_time(u8 i);
u8 available_slot(void);
u32 search_slot(u32 slot);
u32 search_ID_slot(u32 id);
void view_reservation(void);
void cancel_reservation(void);
void view_record(void);
#endif