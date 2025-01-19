/*
 * version.h
 *
 *  Created on: May 11, 2024
 *      Author: Eng. André A. M. Araújo
 */

#ifndef INC_VERSION_H_
#define INC_VERSION_H_

#include "main.h"

#include "cli.h"

#define V_MAJOR		0
#define	V_MINOR		0
#define V_PATCH		1

#define V_YEAR	 2025
#define V_MONTH    01
#define V_DAY      17

extern char * build_date;
extern char * build_time;

extern uint16_t version_year;
extern uint8_t  version_month;
extern uint8_t  version_day;
extern uint8_t  version_hour;
extern uint8_t  version_minute;
extern uint8_t  version_second;

void VERSION_Get(void);

#endif /* INC_VERSION_H_ */
