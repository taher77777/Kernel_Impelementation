/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: RTOSstack		**************/
/********************		SWC: RTOS				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-8-2020			**************/
/*****************************************************************/
/*****************************************************************/
#include "STD_TYPE.h"

#include "TIMER0_interface.h"
#include "GIE_interface.h"

#include "Taher_OS_private.h"
#include "Taher_OS_interface.h"
#include "Taher_OS_config.h"


/*******************************************/
/********* semaphore part *****************/

/*
 * create semaphore function
 * return 1 if create semaphore
 * return 0 if can not create semaphore
 */
u8 Semaphore_u8Create(SEMAPHORE_T * Copy_STSemaphore)
{
	Copy_STSemaphore->state=Semaphore_create;
	Copy_STSemaphore->value=Semaphore_available;
	if(Copy_STSemaphore->state==Semaphore_create)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
 * Give semaphore function
 * return 1 if give semaphore
 * return 0 if can not give semaphore
 */

u8 Semaphoreu8Give(SEMAPHORE_T * Copy_STSemaphore)
{
	if(Copy_STSemaphore->state==Semaphore_create)
	{
		Copy_STSemaphore->value=Semaphore_available;
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
 *
 * Take semaphore function
 * return 1 if take semaphore
 * return 0 if can not take semaphore
 *
 */

u8 Semaphoreu8Take(SEMAPHORE_T * Copy_STSemaphore)
{
	if(Copy_STSemaphore->state==Semaphore_create)
	{
		if (Copy_STSemaphore->value==Semaphore_available)
		{
			Copy_STSemaphore->value=Semaphore_taked;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}

}

/*
 * delete semaphore function
 * return 1 if delete semaphore
 * return 0 if can not delete semaphore
 *
 */

u8 Semaphoreu8Delete(SEMAPHORE_T * Copy_STSemaphore)
{
	if(Copy_STSemaphore->state==Semaphore_create)
	{
		Copy_STSemaphore->state=Semaphore_delete;
		return 1;
	}
	else
	{
		return 0;
	}
}

/******************************************/

/******************************************/
/********* Counter semaphore part *********/

/*
 * create semaphore function and set max users
 * return 1 if create semaphore
 * return 0 if can not create semaphore
 */
u8 SemaphoreC_u8Create(SEMAPHOREC_T * Copy_STSemaphore,u8 Copy_u8MaxUsers)
{
	Copy_STSemaphore->state=Semaphore_create;
	Copy_STSemaphore->MaxUsers=Copy_u8MaxUsers;
	if(Copy_STSemaphore->state==Semaphore_create)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
 * Give semaphore function
 * return 1 if give semaphore
 * return 0 if can not give semaphore
 */

u8 SemaphoreCu8Give(SEMAPHOREC_T * Copy_STSemaphore)
{
	if(Copy_STSemaphore->state==Semaphore_create)
	{
		if (Copy_STSemaphore->Users>0)
		{
			Copy_STSemaphore->Users--;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

/*
 *
 * Take semaphore function
 * return 1 if take semaphore
 * return 0 if can not take semaphore
 *
 */

u8 SemaphoreCu8Take(SEMAPHOREC_T * Copy_STSemaphore)
{
	if(Copy_STSemaphore->state==Semaphore_create)
	{

		if((Copy_STSemaphore->Users)<(Copy_STSemaphore->MaxUsers))
		{
			Copy_STSemaphore->Users++;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}

}

	/*
	 * delete semaphore function
	 * return 1 if delete semaphore
	 * return 0 if can not delete semaphore
	 *
	 */

	u8 SemaphoreCu8Delete(SEMAPHOREC_T * Copy_STSemaphore)
	{
		if(Copy_STSemaphore->state == Semaphore_create)
		{
			Copy_STSemaphore->state = Semaphore_delete;
			return 1;
		}
		else
		{
			return 0;
		}
	}

	/******************************************/
	/*******************************************/
	/********* queue part *****************/

	/*
	 * create queue function
	 * return 1 if create queue
	 * return 0 if can not create queue
	 */
	u8 Queue_u8Create(QUEUE_T * Copy_STQueue)
	{
		Copy_STQueue->state=Queue_create;
		Copy_STQueue->value=Queue_available;
		if(Copy_STQueue->state==Queue_create)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	/*
	 * Give semaphore function
	 * return 1 if Push queue
	 * return 0 if can not Push queue
	 *
	 */

	u8 Queueu8Push(QUEUE_T * Copy_STQueue, u32* Copy_arrQueueBuffer)
	{
		if(Copy_STQueue->state==Queue_create)
		{
			Copy_STQueue->value=Queue_busy;
			Copy_STQueue->buffer=*Copy_arrQueueBuffer;
			return 1;
		}
		else
		{
			return 0;
		}
	}

	/*
	 *
	 * Take Queue function
	 * return 1 if Pop Queue
	 * return 0 if can not Pop Queue
	 *
	 */

	u8 Queueu8POP(QUEUE_T * Copy_STQueue,  u32* Copy_arrQueueBuffer)
	{
		if(Copy_STQueue->state==Queue_create)
		{
			if (Copy_STQueue->value==Queue_busy)
			{
				*Copy_arrQueueBuffer=Copy_STQueue->buffer;
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}

	}

	/*
	 * delete semaphore function
	 * return 1 if delete semaphore
	 * return 0 if can not delete semaphore
	 *
	 */

	u8 Queueu8Delete(QUEUE_T * Copy_STQueue)
	{
		if(Copy_STQueue->state==Queue_create)
		{
			Copy_STQueue->state=Queue_delete;
			return 1;
		}
		else
		{
			return 0;
		}
	}

	/******************************************/


	/*chose Preemptive or nonPreemptive*/
#if SCHEDULING_TYPE == nonpreemptive
	/*global variable to set the task number*/
#if MultiplepriorityNumber ==  one_task
	Task_T SystemTask [TASK_NUM]={{NULL}};/*RTOS system */
	void RTOS_voidStart(void)
	{
		TIMER0_u8SetCallback(&voidScheduler);
		GIF_voidEnable();
		TIMER0_voidInit();

	}

	/*function to create a new task*/
	u8 RTOS_voidCreateTask(u8 Copy_u8Priority , u16 Copy_u16Periodicity, void (*Copy_pvtaskfunc)(void),u16 Copy_u16FirstDelay)
	{
		u8 Local_u8ErrorState=OK;
		/*check if priority is empty or no*/
		if(SystemTask[Copy_u8Priority].TaskFunc==NULL)
		{
			SystemTask[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
			SystemTask[Copy_u8Priority].TaskFunc=Copy_pvtaskfunc;
			SystemTask[Copy_u8Priority].state=enable;
			SystemTask[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
		}
		else
		{
			/*priority is reserved / don`t create the task*/
			Local_u8ErrorState=NOK;
		}
		return Local_u8ErrorState;
	}

	/*function to disable task*/
	void RTOS_voidSuspendTask(void (*Copy_pvtaskfunc)(void))
	{
		u8 Local_u8counter=0;

		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask[Local_u8counter].state=disable;
			}

		}
	}

	/*function to return task enable */
	void RTOS_voidResumeTask(void (*Copy_pvtaskfunc)(void))
	{
		u8 Local_u8counter=0;
		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask[Local_u8counter].state=enable;
			}


		}
	}

	/*function to delete task*/
	void RTOS_voidDeleteTask(void (*Copy_pvtaskfunc)(void))
	{
		u8 Local_u8counter=0;
		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask[Local_u8counter].TaskFunc=NULL;
			}

		}
	}


	/*function to control all task*/
	static void voidScheduler (void)
	{
		u8 Local_u8TaskCounter;
		for (Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
		{

			if (SystemTask[Local_u8TaskCounter].state==enable)
			{

				if (((SystemTask[Local_u8TaskCounter].FirstDelay)==0))
				{
					/*invoke the task function*/
					if(SystemTask[Local_u8TaskCounter].TaskFunc!=NULL)
					{
						/*call task to run*/
						SystemTask[Local_u8TaskCounter].TaskFunc();

						/*set firstDelay assen Periodicity to continue */
						SystemTask[Local_u8TaskCounter].FirstDelay=SystemTask[Local_u8TaskCounter].Periodicity-1;
					}
					else
					{
						/* do nothing*/
					}
				}
				else
				{
					/*decrease FirstDelay to reach zero  */
					SystemTask[Local_u8TaskCounter].FirstDelay--;
				}
			}
		}
	}

#elif MultiplepriorityNumber ==  Two_task
	Task_T SystemTask1 [TASK_NUM]={{NULL}};
	Task_T SystemTask2 [TASK_NUM]={{NULL}};
	/*RTOS system */
	void RTOS_voidStart(void)
	{
		TIMER0_u8SetCallback(&voidScheduler);
		GIF_voidEnable();
		TIMER0_voidInit();

	}

	/*function to create a new task*/
	u8 RTOS_voidCreateTask(u8 Copy_u8Priority , u16 Copy_u16Periodicity, void (*Copy_pvtaskfunc)(void),u16 Copy_u16FirstDelay)
	{
		u8 Local_u8ErrorState=OK;
		/*check if priority is empty or no*/
		if(SystemTask1[Copy_u8Priority].TaskFunc==NULL)
		{
			SystemTask1[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
			SystemTask1[Copy_u8Priority].TaskFunc=Copy_pvtaskfunc;
			SystemTask1[Copy_u8Priority].state=enable;
			SystemTask1[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
		}
		else
		{
			if(SystemTask2[Copy_u8Priority].TaskFunc==NULL)
			{
				SystemTask2[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
				SystemTask2[Copy_u8Priority].TaskFunc=Copy_pvtaskfunc;
				SystemTask2[Copy_u8Priority].state=enable;
				SystemTask2[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
			}
			else
			{
				/*priority is reserved / don`t create the task*/
				Local_u8ErrorState=NOK;
			}
		}
		return Local_u8ErrorState;
	}


	/*function to disable task*/
	void RTOS_voidSuspendTask(void (*Copy_pvtaskfunc)(void) )
	{
		u8 Local_u8counter=0;
		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask1[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask1[Local_u8counter].state=disable;
			}

			if(SystemTask2[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask2[Local_u8counter].state=disable;
			}
		}

	}

	/*function to return task enable */
	void RTOS_voidResumeTask(void (*Copy_pvtaskfunc)(void))
	{
		u8 Local_u8counter=0;
		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask1[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask1[Local_u8counter].state=enable;
			}

			if(SystemTask2[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask2[Local_u8counter].state=enable;
			}
		}
	}

	/*function to delete task*/
	void RTOS_voidDeleteTask(void (*Copy_pvtaskfunc)(void))
	{
		u8 Local_u8counter=0;
		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask1[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask1[Local_u8counter].TaskFunc=NULL;
			}

			if(SystemTask2[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask2[Local_u8counter].TaskFunc=NULL;
			}
		}
	}


	/*function to control all task*/
	static void voidScheduler (void)
	{
		u8 Local_u8TaskCounter;


		for (Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
		{

			if (SystemTask1[Local_u8TaskCounter].state==enable)
			{

				if (((SystemTask1[Local_u8TaskCounter].FirstDelay)==0))
				{
					/*invoke the task function*/
					if(SystemTask1[Local_u8TaskCounter].TaskFunc!=NULL)
					{
						/*call task to run*/
						SystemTask1[Local_u8TaskCounter].TaskFunc();

						/*set firstDelay assen Periodicity to continue */
						SystemTask1[Local_u8TaskCounter].FirstDelay=SystemTask1[Local_u8TaskCounter].Periodicity-1;
					}
					else
					{
						/* do nothing*/
					}
				}
				else
				{
					/*decrease FirstDelay to reach zero  */
					SystemTask1[Local_u8TaskCounter].FirstDelay--;
				}
			}

			/*Priority face 2*/
			if (SystemTask2[Local_u8TaskCounter].state==enable)
			{

				if (((SystemTask2[Local_u8TaskCounter].FirstDelay)==0))
				{
					/*invoke the task function*/
					if(SystemTask2[Local_u8TaskCounter].TaskFunc!=NULL)
					{
						/*call task to run*/
						SystemTask2[Local_u8TaskCounter].TaskFunc();

						/*set firstDelay assen Periodicity to continue */
						SystemTask2[Local_u8TaskCounter].FirstDelay=SystemTask2[Local_u8TaskCounter].Periodicity-1;
					}
					else
					{
						/* do nothing*/
					}
				}
				else
				{
					/*decrease FirstDelay to reach zero  */
					SystemTask2[Local_u8TaskCounter].FirstDelay--;
				}
			}
		}

	}

#elif MultiplepriorityNumber ==  Three_task
	Task_T SystemTask1 [TASK_NUM]={{NULL}};
	Task_T SystemTask2 [TASK_NUM]={{NULL}};
	Task_T SystemTask3 [TASK_NUM]={{NULL}};
	/*RTOS system */
	void RTOS_voidStart(void)
	{
		TIMER0_u8SetCallback(&voidScheduler);
		GIF_voidEnable();
		TIMER0_voidInit();

	}

	/*function to create a new task*/
	u8 RTOS_voidCreateTask(u8 Copy_u8Priority , u16 Copy_u16Periodicity, void (*Copy_pvtaskfunc)(void),u16 Copy_u16FirstDelay)
	{
		u8 Local_u8ErrorState=OK;
		/*check if priority is empty or no*/
		if(SystemTask1[Copy_u8Priority].TaskFunc==NULL)
		{
			SystemTask1[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
			SystemTask1[Copy_u8Priority].TaskFunc=Copy_pvtaskfunc;
			SystemTask1[Copy_u8Priority].state=enable;
			SystemTask1[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
		}
		else
		{
			if(SystemTask2[Copy_u8Priority].TaskFunc==NULL)
			{
				SystemTask2[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
				SystemTask2[Copy_u8Priority].TaskFunc=Copy_pvtaskfunc;
				SystemTask2[Copy_u8Priority].state=enable;
				SystemTask2[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
			}
			else
			{
				if(SystemTask3[Copy_u8Priority].TaskFunc==NULL)
				{
					SystemTask3[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
					SystemTask3[Copy_u8Priority].TaskFunc=Copy_pvtaskfunc;
					SystemTask3[Copy_u8Priority].state=enable;
					SystemTask3[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
				}
				else
				{
					/*priority is reserved / don`t create the task*/
					Local_u8ErrorState=NOK;
				}
			}
		}
		return Local_u8ErrorState;
	}


	/*function to disable task*/
	void RTOS_voidSuspendTask(void (*Copy_pvtaskfunc)(void) )
	{
		u8 Local_u8counter=0;
		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask1[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask1[Local_u8counter].state=disable;
			}

			if(SystemTask2[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask2[Local_u8counter].state=disable;
			}
			if(SystemTask3[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask3[Local_u8counter].state=disable;
			}
		}

	}

	/*function to return task enable */
	void RTOS_voidResumeTask(void (*Copy_pvtaskfunc)(void))
	{
		u8 Local_u8counter=0;
		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask1[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask1[Local_u8counter].state=enable;
			}

			if(SystemTask2[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask2[Local_u8counter].state=enable;
			}
			if(SystemTask3[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask3[Local_u8counter].state=enable;
			}
		}
	}

	/*function to delete task*/
	void RTOS_voidDeleteTask(void (*Copy_pvtaskfunc)(void))
	{
		u8 Local_u8counter=0;
		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask1[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask1[Local_u8counter].TaskFunc=NULL;
			}

			if(SystemTask2[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask2[Local_u8counter].TaskFunc=NULL;
			}
			if(SystemTask3[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask3[Local_u8counter].TaskFunc=NULL;
			}
		}
	}


	/*function to control all task*/
	static void voidScheduler (void)
	{
		u8 Local_u8TaskCounter;


		for (Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
		{

			if (SystemTask1[Local_u8TaskCounter].state==enable)
			{

				if (((SystemTask1[Local_u8TaskCounter].FirstDelay)==0))
				{
					/*invoke the task function*/
					if(SystemTask1[Local_u8TaskCounter].TaskFunc!=NULL)
					{
						/*call task to run*/
						SystemTask1[Local_u8TaskCounter].TaskFunc();

						/*set firstDelay assen Periodicity to continue */
						SystemTask1[Local_u8TaskCounter].FirstDelay=SystemTask1[Local_u8TaskCounter].Periodicity-1;
					}
					else
					{
						/* do nothing*/
					}
				}
				else
				{
					/*decrease FirstDelay to reach zero  */
					SystemTask1[Local_u8TaskCounter].FirstDelay--;
				}
			}

			/*Priority face 2*/
			if (SystemTask2[Local_u8TaskCounter].state==enable)
			{

				if (((SystemTask2[Local_u8TaskCounter].FirstDelay)==0))
				{
					/*invoke the task function*/
					if(SystemTask2[Local_u8TaskCounter].TaskFunc!=NULL)
					{
						/*call task to run*/
						SystemTask2[Local_u8TaskCounter].TaskFunc();

						/*set firstDelay assen Periodicity to continue */
						SystemTask2[Local_u8TaskCounter].FirstDelay=SystemTask2[Local_u8TaskCounter].Periodicity-1;
					}
					else
					{
						/* do nothing*/
					}
				}
				else
				{
					/*decrease FirstDelay to reach zero  */
					SystemTask2[Local_u8TaskCounter].FirstDelay--;
				}
			}

			/*Priority face 3*/
			if (SystemTask3[Local_u8TaskCounter].state==enable)
			{

				if (((SystemTask3[Local_u8TaskCounter].FirstDelay)==0))
				{
					/*invoke the task function*/
					if(SystemTask3[Local_u8TaskCounter].TaskFunc!=NULL)
					{
						/*call task to run*/
						SystemTask3[Local_u8TaskCounter].TaskFunc();

						/*set firstDelay assen Periodicity to continue */
						SystemTask3[Local_u8TaskCounter].FirstDelay=SystemTask3[Local_u8TaskCounter].Periodicity-1;
					}
					else
					{
						/* do nothing*/
					}
				}
				else
				{
					/*decrease FirstDelay to reach zero  */
					SystemTask3[Local_u8TaskCounter].FirstDelay--;
				}
			}
		}

	}
#endif
	/****************************************************************************/

#elif SCHEDULING_TYPE == preemptive
	/*Scheduler_trigger*/
	static u8 Scheduler_trigger=0;
	static u8 nested=1;
	/*global variable to set the task number*/
#if MultiplepriorityNumber ==  one_task
	Task_T SystemTask [TASK_NUM]={{NULL}};/*RTOS system */

	void RTOS_voidStart(void)
	{

		TIMER0_u8SetCallback(&Scheduler_notification);
		GIF_voidEnable();
		TIMER0_voidInit();
		while(1)
		{
			while(Scheduler_trigger==0);
			Scheduler_trigger=0;
			voidScheduler();

		}
	}

	/*function to create a new task*/
	u8 RTOS_voidCreateTask(u8 Copy_u8Priority , u16 Copy_u16Periodicity, void (*Copy_pvtaskfunc)(void),u16 Copy_u16FirstDelay)
	{
		u8 Local_u8ErrorState=OK;
		/*check if priority is empty or no*/
		if(SystemTask[Copy_u8Priority].TaskFunc==NULL)
		{
			SystemTask[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
			SystemTask[Copy_u8Priority].TaskFunc=Copy_pvtaskfunc;
			SystemTask[Copy_u8Priority].state=enable;
			SystemTask[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
		}
		else
		{
			/*priority is reserved / don`t create the task*/
			Local_u8ErrorState=NOK;
		}
		return Local_u8ErrorState;
	}

	/*function to disable task*/
	void RTOS_voidSuspendTask(void (*Copy_pvtaskfunc)(void))
	{
		u8 Local_u8counter=0;

		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask[Local_u8counter].state=disable;
			}

		}
	}

	/*function to return task enable */
	void RTOS_voidResumeTask(void (*Copy_pvtaskfunc)(void))
	{
		u8 Local_u8counter=0;
		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask[Local_u8counter].state=enable;
			}


		}
	}

	/*function to delete task*/
	void RTOS_voidDeleteTask(void (*Copy_pvtaskfunc)(void))
	{
		u8 Local_u8counter=0;
		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask[Local_u8counter].TaskFunc=NULL;
			}

		}
	}


	/*function to control all task*/
	static void voidScheduler (void)
	{
		static u8 current_task_priority=255;
		u8 Local_u8TaskCounter;

		for (Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
		{

			if (SystemTask[Local_u8TaskCounter].state==enable)
			{

				if (((SystemTask[Local_u8TaskCounter].FirstDelay)==0))
				{
					/*invoke the task function*/
					if(SystemTask[Local_u8TaskCounter].TaskFunc!=NULL)
					{
						if(SystemTask[current_task_priority].TaskFunc!=SystemTask[Local_u8TaskCounter].TaskFunc)
						{
							if(Local_u8TaskCounter<current_task_priority)
							{
								/*store current priority task */
								current_task_priority=Local_u8TaskCounter;
								nested=0 ;
								/*call task to run*/
								SystemTask[Local_u8TaskCounter].TaskFunc();

								/*set firstDelay assen Periodicity to continue */
								SystemTask[Local_u8TaskCounter].FirstDelay=SystemTask[Local_u8TaskCounter].Periodicity-1;
								nested=1;
								current_task_priority=255;
							}
						}

					}
					else
					{
						/* do nothing*/
					}
				}
				else
				{
					/*decrease FirstDelay to reach zero  */
					SystemTask[Local_u8TaskCounter].FirstDelay--;
				}
			}
		}
	}

	static void Scheduler_notification (void)
	{
		Scheduler_trigger=1;
		if(nested==0)
		{
			voidScheduler();
		}
	}
#elif MultiplepriorityNumber ==  Two_task
	Task_T SystemTask1 [TASK_NUM]={{NULL}};
	Task_T SystemTask2 [TASK_NUM]={{NULL}};
	/*RTOS system */
	void RTOS_voidStart(void)
	{
		TIMER0_u8SetCallback(&voidScheduler);
		GIF_voidEnable();
		TIMER0_voidInit();

	}

	/*function to create a new task*/
	u8 RTOS_voidCreateTask(u8 Copy_u8Priority , u16 Copy_u16Periodicity, void (*Copy_pvtaskfunc)(void),u16 Copy_u16FirstDelay)
	{
		u8 Local_u8ErrorState=OK;
		/*check if priority is empty or no*/
		if(SystemTask1[Copy_u8Priority].TaskFunc==NULL)
		{
			SystemTask1[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
			SystemTask1[Copy_u8Priority].TaskFunc=Copy_pvtaskfunc;
			SystemTask1[Copy_u8Priority].state=enable;
			SystemTask1[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
		}
		else
		{
			if(SystemTask2[Copy_u8Priority].TaskFunc==NULL)
			{
				SystemTask2[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
				SystemTask2[Copy_u8Priority].TaskFunc=Copy_pvtaskfunc;
				SystemTask2[Copy_u8Priority].state=enable;
				SystemTask2[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
			}
			else
			{
				/*priority is reserved / don`t create the task*/
				Local_u8ErrorState=NOK;
			}
		}
		return Local_u8ErrorState;
	}


	/*function to disable task*/
	void RTOS_voidSuspendTask(void (*Copy_pvtaskfunc)(void) )
	{
		u8 Local_u8counter=0;
		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask1[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask1[Local_u8counter].state=disable;
			}

			if(SystemTask2[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask2[Local_u8counter].state=disable;
			}
		}

	}

	/*function to return task enable */
	void RTOS_voidResumeTask(void (*Copy_pvtaskfunc)(void))
	{
		u8 Local_u8counter=0;
		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask1[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask1[Local_u8counter].state=enable;
			}

			if(SystemTask2[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask2[Local_u8counter].state=enable;
			}
		}
	}

	/*function to delete task*/
	void RTOS_voidDeleteTask(void (*Copy_pvtaskfunc)(void))
	{
		u8 Local_u8counter=0;
		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask1[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask1[Local_u8counter].TaskFunc=NULL;
			}

			if(SystemTask2[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask2[Local_u8counter].TaskFunc=NULL;
			}
		}
	}


	/*function to control all task*/
	static void voidScheduler (void)
	{
		u8 Local_u8TaskCounter;


		for (Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
		{

			if (SystemTask1[Local_u8TaskCounter].state==enable)
			{

				if (((SystemTask1[Local_u8TaskCounter].FirstDelay)==0))
				{
					/*invoke the task function*/
					if(SystemTask1[Local_u8TaskCounter].TaskFunc!=NULL)
					{
						/*call task to run*/
						SystemTask1[Local_u8TaskCounter].TaskFunc();

						/*set firstDelay assen Periodicity to continue */
						SystemTask1[Local_u8TaskCounter].FirstDelay=SystemTask1[Local_u8TaskCounter].Periodicity-1;
					}
					else
					{
						/* do nothing*/
					}
				}
				else
				{
					/*decrease FirstDelay to reach zero  */
					SystemTask1[Local_u8TaskCounter].FirstDelay--;
				}
			}

			/*Priority face 2*/
			if (SystemTask2[Local_u8TaskCounter].state==enable)
			{

				if (((SystemTask2[Local_u8TaskCounter].FirstDelay)==0))
				{
					/*invoke the task function*/
					if(SystemTask2[Local_u8TaskCounter].TaskFunc!=NULL)
					{
						/*call task to run*/
						SystemTask2[Local_u8TaskCounter].TaskFunc();

						/*set firstDelay assen Periodicity to continue */
						SystemTask2[Local_u8TaskCounter].FirstDelay=SystemTask2[Local_u8TaskCounter].Periodicity-1;
					}
					else
					{
						/* do nothing*/
					}
				}
				else
				{
					/*decrease FirstDelay to reach zero  */
					SystemTask2[Local_u8TaskCounter].FirstDelay--;
				}
			}
		}

	}

#elif MultiplepriorityNumber ==  Three_task
	Task_T SystemTask1 [TASK_NUM]={{NULL}};
	Task_T SystemTask2 [TASK_NUM]={{NULL}};
	Task_T SystemTask3 [TASK_NUM]={{NULL}};
	/*RTOS system */
	void RTOS_voidStart(void)
	{
		TIMER0_u8SetCallback(&voidScheduler);
		GIF_voidEnable();
		TIMER0_voidInit();

	}

	/*function to create a new task*/
	u8 RTOS_voidCreateTask(u8 Copy_u8Priority , u16 Copy_u16Periodicity, void (*Copy_pvtaskfunc)(void),u16 Copy_u16FirstDelay)
	{
		u8 Local_u8ErrorState=OK;
		/*check if priority is empty or no*/
		if(SystemTask1[Copy_u8Priority].TaskFunc==NULL)
		{
			SystemTask1[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
			SystemTask1[Copy_u8Priority].TaskFunc=Copy_pvtaskfunc;
			SystemTask1[Copy_u8Priority].state=enable;
			SystemTask1[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
		}
		else
		{
			if(SystemTask2[Copy_u8Priority].TaskFunc==NULL)
			{
				SystemTask2[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
				SystemTask2[Copy_u8Priority].TaskFunc=Copy_pvtaskfunc;
				SystemTask2[Copy_u8Priority].state=enable;
				SystemTask2[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
			}
			else
			{
				if(SystemTask3[Copy_u8Priority].TaskFunc==NULL)
				{
					SystemTask3[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
					SystemTask3[Copy_u8Priority].TaskFunc=Copy_pvtaskfunc;
					SystemTask3[Copy_u8Priority].state=enable;
					SystemTask3[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
				}
				else
				{
					/*priority is reserved / don`t create the task*/
					Local_u8ErrorState=NOK;
				}
			}
		}
		return Local_u8ErrorState;
	}


	/*function to disable task*/
	void RTOS_voidSuspendTask(void (*Copy_pvtaskfunc)(void) )
	{
		u8 Local_u8counter=0;
		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask1[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask1[Local_u8counter].state=disable;
			}

			if(SystemTask2[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask2[Local_u8counter].state=disable;
			}
			if(SystemTask3[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask3[Local_u8counter].state=disable;
			}
		}

	}

	/*function to return task enable */
	void RTOS_voidResumeTask(void (*Copy_pvtaskfunc)(void))
	{
		u8 Local_u8counter=0;
		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask1[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask1[Local_u8counter].state=enable;
			}

			if(SystemTask2[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask2[Local_u8counter].state=enable;
			}
			if(SystemTask3[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask3[Local_u8counter].state=enable;
			}
		}
	}

	/*function to delete task*/
	void RTOS_voidDeleteTask(void (*Copy_pvtaskfunc)(void))
	{
		u8 Local_u8counter=0;
		for(Local_u8counter=0;Local_u8counter<TASK_NUM;Local_u8counter++)
		{
			if(SystemTask1[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask1[Local_u8counter].TaskFunc=NULL;
			}

			if(SystemTask2[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask2[Local_u8counter].TaskFunc=NULL;
			}
			if(SystemTask3[Local_u8counter].TaskFunc==Copy_pvtaskfunc)
			{
				SystemTask3[Local_u8counter].TaskFunc=NULL;
			}
		}
	}


	/*function to control all task*/
	static void voidScheduler (void)
	{
		u8 Local_u8TaskCounter;


		for (Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
		{

			if (SystemTask1[Local_u8TaskCounter].state==enable)
			{

				if (((SystemTask1[Local_u8TaskCounter].FirstDelay)==0))
				{
					/*invoke the task function*/
					if(SystemTask1[Local_u8TaskCounter].TaskFunc!=NULL)
					{
						/*call task to run*/
						SystemTask1[Local_u8TaskCounter].TaskFunc();

						/*set firstDelay assen Periodicity to continue */
						SystemTask1[Local_u8TaskCounter].FirstDelay=SystemTask1[Local_u8TaskCounter].Periodicity-1;
					}
					else
					{
						/* do nothing*/
					}
				}
				else
				{
					/*decrease FirstDelay to reach zero  */
					SystemTask1[Local_u8TaskCounter].FirstDelay--;
				}
			}

			/*Priority face 2*/
			if (SystemTask2[Local_u8TaskCounter].state==enable)
			{

				if (((SystemTask2[Local_u8TaskCounter].FirstDelay)==0))
				{
					/*invoke the task function*/
					if(SystemTask2[Local_u8TaskCounter].TaskFunc!=NULL)
					{
						/*call task to run*/
						SystemTask2[Local_u8TaskCounter].TaskFunc();

						/*set firstDelay assen Periodicity to continue */
						SystemTask2[Local_u8TaskCounter].FirstDelay=SystemTask2[Local_u8TaskCounter].Periodicity-1;
					}
					else
					{
						/* do nothing*/
					}
				}
				else
				{
					/*decrease FirstDelay to reach zero  */
					SystemTask2[Local_u8TaskCounter].FirstDelay--;
				}
			}

			/*Priority face 3*/
			if (SystemTask3[Local_u8TaskCounter].state==enable)
			{

				if (((SystemTask3[Local_u8TaskCounter].FirstDelay)==0))
				{
					/*invoke the task function*/
					if(SystemTask3[Local_u8TaskCounter].TaskFunc!=NULL)
					{
						/*call task to run*/
						SystemTask3[Local_u8TaskCounter].TaskFunc();

						/*set firstDelay assen Periodicity to continue */
						SystemTask3[Local_u8TaskCounter].FirstDelay=SystemTask3[Local_u8TaskCounter].Periodicity-1;
					}
					else
					{
						/* do nothing*/
					}
				}
				else
				{
					/*decrease FirstDelay to reach zero  */
					SystemTask3[Local_u8TaskCounter].FirstDelay--;
				}
			}
		}

	}
#endif
#endif
