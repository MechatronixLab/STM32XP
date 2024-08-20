/*
 * rgb.c
 *
 *  Created on: Sep 17, 2023
 *      Author: André A. M. Araújo
 */

#include "rgb.h"


enum RGB_colors RGB_state = off;

uint16_t RGB_R = 0;
uint16_t RGB_G = 0;
uint16_t RGB_B = 0;

void RGB_sweep(void)
{
	switch (RGB_state)
	{
		case off:		// Shutdown

			RGB_R = 0;
			RGB_G = 0;
			RGB_B = 0;

			break;

		case red:		// Red

			RGB_B--;
			if (RGB_B == 0)
			{
				RGB_state = yellow;
			}
			break;

		case yellow:	// Yellow

			RGB_G++;
			if (RGB_G == 0x10)
			{
				RGB_state = green;
			}
			break;

		case green:		// Green

			RGB_R--;
			if (RGB_R == 0)
			{
				RGB_state = cyan;
			}
			break;

		case cyan:		// Cyan

			RGB_B++;
			if (RGB_B == 0x10)
			{
				RGB_state = blue;
			}
			break;

		case blue:		// Blue

			RGB_G--;
			if (RGB_G == 0)
			{
				RGB_state = purple;
			}
			break;

		case purple:	// Purple

			RGB_R++;
			if (RGB_R == 0x10)
			{
				RGB_state = red;
			}
			break;

		case white:		// White

			RGB_R = 0x10;
			RGB_G = 0x10;
			RGB_B = 0x10;

			break;

		default:		// Default: Shutdown

			RGB_R = 0;
			RGB_G = 0;
			RGB_B = 0;

			break;
	}
}
