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

#define V_YEAR	 2024
#define V_MONTH    05
#define V_DAY      11

extern char * build_date;
extern char * build_time;

void VERSION_Print(void);

#endif /* INC_VERSION_H_ */
