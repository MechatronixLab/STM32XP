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

uint16_t version_year   = 0;
uint8_t  version_month  = 0;
uint8_t  version_day    = 0;
uint8_t  version_hour   = 0;
uint8_t  version_minute = 0;
uint8_t  version_second = 0;

void VERSION_Get(void)
{
	char aux[20]      = {0};
	char aux_month[4] = {0};

	strncpy(aux, build_date + 7, 4);

	version_year = (uint16_t)(((uint8_t)(aux[0]) - '0') * 1000
					+ ((uint8_t)(aux[1]) - '0') *  100
					+ ((uint8_t)(aux[2]) - '0') *   10
					+ ((uint8_t)(aux[3]) - '0'));

	strncpy(aux_month, build_date, 3);
	aux_month[3] = '\0';

	if 		(strcmp(aux_month, "Jan") == 0)
	{
		version_month =  1;
	}
	else if (strcmp(aux_month, "Feb") == 0)
	{
		version_month =  2;
	}
	else if (strcmp(aux_month, "Mar") == 0)
	{
		version_month =  3;
	}
	else if (strcmp(aux_month, "Apr") == 0)
	{
		version_month =  4;
	}
	else if (strcmp(aux_month, "May") == 0)
	{
		version_month =  5;
	}
	else if (strcmp(aux_month, "Jun") == 0)
	{
		version_month =  6;
	}
	else if (strcmp(aux_month, "Jul") == 0)
	{
		version_month =  7;
	}
	else if (strcmp(aux_month, "Aug") == 0)
	{
		version_month =  8;
	}
	else if (strcmp(aux_month, "Sep") == 0)
	{
		version_month =  9;
	}
	else if (strcmp(aux_month, "Oct") == 0)
	{
		version_month = 10;
	}
	else if (strcmp(aux_month, "Nov") == 0)
	{
		version_month = 11;
	}
	else if (strcmp(aux_month, "Dec") == 0)
	{
		version_month = 12;
	}
	else
	{
		version_month = 99;
	}

	strncpy(aux, build_date + 4, 2);

	if (aux[0] == ' ')
	{
		version_day =                                              (uint8_t)(aux[1]) - '0';
	}
	else
	{
		version_day = (uint16_t)(((uint8_t)(aux[0]) - '0') * 10 + ((uint8_t)(aux[1]) - '0'));
	}

	strncpy(aux, build_time, strlen(build_time));

	version_hour   = (uint16_t)(((uint8_t)(aux[0]) - '0') * 10 + ((uint8_t)(aux[1]) - '0'));
	version_minute = (uint16_t)(((uint8_t)(aux[3]) - '0') * 10 + ((uint8_t)(aux[4]) - '0'));
	version_second = (uint16_t)(((uint8_t)(aux[6]) - '0') * 10 + ((uint8_t)(aux[7]) - '0'));

	build_code_date = (uint32_t)(version_year   * 10000
			              	   + version_month  *   100
							   + version_day           );

	build_code_time = (uint32_t)(version_hour   * 10000
							   + version_minute *   100
							   + version_second        );

	CLI_Print("Build Code: %lu%lu \r\n", build_code_date, build_code_time);

	CLI_Write("Build Date: ");
	CLI_Write(build_date);
	CLI_Write(" ; Time: ");
	CLI_Write(build_time);
	CLI_NewLine();
}
