/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: RTOSstack		**************/
/********************		SWC: RTOS				**************/
/********************		Version: 2.00			**************/
/********************		Date: 17-11-2023		**************/
/*****************************************************************/
/*****************************************************************/
#ifndef RTOS_CONFIG_H_
#define RTOS_CONFIG_H_

/*set the max number of task*/
#define TASK_NUM                                  3

/* SCHEDULING_TYPE OPTIONS
 * 1- preemptive                  //just with one_task
 * 2- nonpreemptive
 * */

#define SCHEDULING_TYPE               preemptive

/*number of Tasks that has the same priority
 * Options
 * 1-one_task
 * 2-Two_task
 * 3-Three_task
 * */
#define MultiplepriorityNumber         one_task
#endif
