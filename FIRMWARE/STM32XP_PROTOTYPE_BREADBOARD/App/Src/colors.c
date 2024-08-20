/*
 * colors.c
 *
 *  Created on: Aug 19, 2024
 *      Author: Eng. André A. M. Araújo
 */

#include "colors.h"

enum COLORS_colors COLORS_state = off;

uint16_t COLORS_R = 0;
uint16_t COLORS_G = 0;
uint16_t COLORS_B = 0;

void COLORS_Sweep(void)
{
	switch (COLORS_state)
	{
		case off:		// Shutdown

			COLORS_R = 0;
			COLORS_G = 0;
			COLORS_B = 0;

			break;

		case red:		// Red

			COLORS_B--;
			if (COLORS_B == 0)
			{
				COLORS_state = yellow;
			}
			break;

		case yellow:	// Yellow

			COLORS_G++;
			if (COLORS_G == 0x10)
			{
				COLORS_state = green;
			}
			break;

		case green:		// Green

			COLORS_R--;
			if (COLORS_R == 0)
			{
				COLORS_state = cyan;
			}
			break;

		case cyan:		// Cyan

			COLORS_B++;
			if (COLORS_B == 0x10)
			{
				COLORS_state = blue;
			}
			break;

		case blue:		// Blue

			COLORS_G--;
			if (COLORS_G == 0)
			{
				COLORS_state = purple;
			}
			break;

		case purple:	// Purple

			COLORS_R++;
			if (COLORS_R == 0x10)
			{
				COLORS_state = red;
			}
			break;

		case white:		// White

			COLORS_R = 0x10;
			COLORS_G = 0x10;
			COLORS_B = 0x10;

			break;

		default:		// Default: Shutdown

			COLORS_R = 0;
			COLORS_G = 0;
			COLORS_B = 0;

			break;
	}
}
