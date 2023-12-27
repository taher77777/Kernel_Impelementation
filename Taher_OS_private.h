/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: RTOSstack		**************/
/********************		SWC: RTOS				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-8-2020			**************/
/*****************************************************************/
/*****************************************************************/
#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

/*Task Status*/
#define enable                 1
#define disable                2

/*Number of tasks that have the same priority*/
#define one_task			   1
#define Two_task               2
#define Three_task             3

/*SCHEDULING TYPE OPTIONS*/
#define preemptive             1
#define nonpreemptive          2

/********** structure for tasks ***********/
typedef struct 
{
	u16 Periodicity;
	void (*TaskFunc)(void);
	u8 state;
	u16 FirstDelay;
}Task_T;

/********** Semaphore *******************/

#define Semaphore_create      1
#define Semaphore_delete      2

#define Semaphore_available   1
#define Semaphore_taked       0

/********** Queue ************************/

#define Queue_create      1
#define Queue_delete      2

#define Queue_available   1
#define Queue_busy        0



/* function to control all tasks in our system */
static void voidScheduler (void);
/* function to notification only */
static void Scheduler_notification (void);


#endif
