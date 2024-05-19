/*
 * version.c
 *
 *  Created on: May 19, 2024
 *      Author: Eng. André A. M. Araújo
 */

#include "version.h"

char * build_date = __DATE__;
char * build_time = __TIME__;
uint32_t build_code_date;
uint32_t build_code_time;

void VERSION_Print(void)
{
	char aux[20]      = {0};
	char aux_month[4] = {0};

	uint16_t year   = 0;
	uint8_t  month  = 0;
	uint8_t  day    = 0;
	uint8_t  hour   = 0;
	uint8_t  minute = 0;
	uint8_t  second = 0;

	strncpy(aux, build_date + 7, 4);

	year = (uint16_t)(((uint8_t)(aux[0]) - '0') * 1000
					+ ((uint8_t)(aux[1]) - '0') *  100
					+ ((uint8_t)(aux[2]) - '0') *   10
					+ ((uint8_t)(aux[3]) - '0'));

	strncpy(aux_month, build_date, 3);
	aux_month[3] = '\0';

	if 		(strcmp(aux_month, "Jan") == 0)
	{
		month =  1;
	}
	else if (strcmp(aux_month, "Feb") == 0)
	{
		month =  2;
	}
	else if (strcmp(aux_month, "Mar") == 0)
	{
		month =  3;
	}
	else if (strcmp(aux_month, "Apr") == 0)
	{
		month =  4;
	}
	else if (strcmp(aux_month, "May") == 0)
	{
		month =  5;
	}
	else if (strcmp(aux_month, "Jun") == 0)
	{
		month =  6;
	}
	else if (strcmp(aux_month, "Jul") == 0)
	{
		month =  7;
	}
	else if (strcmp(aux_month, "Aug") == 0)
	{
		month =  8;
	}
	else if (strcmp(aux_month, "Sep") == 0)
	{
		month =  9;
	}
	else if (strcmp(aux_month, "Oct") == 0)
	{
		month = 10;
	}
	else if (strcmp(aux_month, "Nov") == 0)
	{
		month = 11;
	}
	else if (strcmp(aux_month, "Dec") == 0)
	{
		month = 12;
	}
	else
	{
		month = 99;
	}

	strncpy(aux, build_date + 4, 2);

	day = (uint16_t)(((uint8_t)(aux[0]) - '0') * 10 + ((uint8_t)(aux[1]) - '0'));

	strncpy(aux, build_time, strlen(build_time));

	hour   = (uint16_t)(((uint8_t)(aux[0]) - '0') * 10 + ((uint8_t)(aux[1]) - '0'));
	minute = (uint16_t)(((uint8_t)(aux[3]) - '0') * 10 + ((uint8_t)(aux[4]) - '0'));
	second = (uint16_t)(((uint8_t)(aux[6]) - '0') * 10 + ((uint8_t)(aux[7]) - '0'));

	build_code_date = (uint32_t)(year   * 10000
			              	   + month  *   100
							   + day           );

	build_code_time = (uint32_t)(hour   * 10000
							   + minute *   100
							   + second        );

	CLI_Print("Build Code: %lu%lu \r\n", build_code_date, build_code_time);

	CLI_Write("Date: ");
	CLI_Write(build_date);
	CLI_Write(" ; Time: ");
	CLI_Write(build_time);
	CLI_NewLine();
}
