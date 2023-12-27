/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: RTOSstack		**************/
/********************		SWC: RTOS				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-8-2020			**************/
/*****************************************************************/
/*****************************************************************/
#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

/*function to start RTOS system*/
void RTOS_voidStart(void);

/*function to create a new task*/
u8 RTOS_voidCreateTask(u8 Copy_u8Priority , u16 Copy_u16Periodicity, void (*Copy_pvtaskfunc)(void),u16 Copy_u16FirstDelay);

/*function to disable task*/
void RTOS_voidSuspendTask(void (*Copy_pvtaskfunc)(void));

/*function to return task enable */
void RTOS_voidResumeTask(void (*Copy_pvtaskfunc)(void));

/*function to delete task*/
void RTOS_voidDeleteTask(void (*Copy_pvtaskfunc)(void));

/********** structure for Semaphore ***********/
typedef struct
{
	u8 state;
	u8 value;
}SEMAPHORE_T;

/*
 * create semaphore function
 * return 1 if create semaphore
 * return 0 if can not create semaphore
 */
u8 Semaphore_u8Create(SEMAPHORE_T * Copy_STSemaphore);

/*
 * Give semaphore function
 * return 1 if give semaphore
 * return 0 if can not give semaphore
 */

u8 Semaphoreu8Give(SEMAPHORE_T * Copy_STSemaphore);

/*
 *
 * Take semaphore function
 * return 1 if take semaphore
 * return 0 if can not take semaphore
 *
 */

u8 Semaphoreu8Take(SEMAPHORE_T * Copy_STSemaphore);

/*
 * delete semaphore function
 * return 1 if delete semaphore
 * return 0 if can not delete semaphore
 *
 */
u8 Semaphoreu8Delete(SEMAPHORE_T * Copy_STSemaphore);

/********** structureC for counter Semaphore ***/
typedef struct
{
	u8 state;
	u8 Users;
	u8 MaxUsers;

}SEMAPHOREC_T;

/*
 * create semaphore function
 * return 1 if create semaphore
 * return 0 if can not create semaphore
 */
u8 SemaphoreC_u8Create(SEMAPHOREC_T * Copy_STSemaphore, u8 Copy_u8MaxUsers);

/*
 * Give semaphore function
 * return 1 if give semaphore
 * return 0 if can not give semaphore
 */

u8 SemaphoreCu8Give(SEMAPHOREC_T * Copy_STSemaphore);

/*
 *
 * Take semaphore function
 * return 1 if take semaphore
 * return 0 if can not take semaphore
 *
 */

u8 SemaphoreCu8Take(SEMAPHOREC_T * Copy_STSemaphore);

/*
 * delete semaphore function
 * return 1 if delete semaphore
 * return 0 if can not delete semaphore
 *
 */
u8 SemaphoreCu8Delete(SEMAPHOREC_T * Copy_STSemaphore);

/********** structure for Queue ***********/
typedef struct
{
	u8 state;
	u8 value;
	u32 buffer;
}QUEUE_T;

/*
 * create queue function
 * return 1 if create queue
 * return 0 if can not create queue
 */
u8 Queue_u8Create(QUEUE_T * Copy_STQueue);

/*
 * Give semaphore function
 * return 1 if Push queue
 * return 0 if can not Push queue
 *
 */

u8 Queueu8Push(QUEUE_T * Copy_STQueue,  u32 *Copy_arrQueueBuffer);

/*
 *
 * Take Queue function
 * return 1 if Pop Queue
 * return 0 if can not Pop Queue
 *
 */

u8 Queueu8POP(QUEUE_T * Copy_STQueue,  u32* Copy_arrQueueBuffer);

/*
 * delete semaphore function
 * return 1 if delete semaphore
 * return 0 if can not delete semaphore
 *
 */

u8 Queueu8Delete(QUEUE_T * Copy_STQueue);
#endif
