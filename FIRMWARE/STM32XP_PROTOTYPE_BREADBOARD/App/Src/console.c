/*
 * console.c
 *
 *  Created on: May 12, 2024
 *      Author: Eng. André A. M. Araújo
 */

#include "console.h"

static char console_buffer[96] = {0};

void CONSOLE_Init(void)
{
	// ascii-art-generator.org/
	CLI_NewLine();
	CLI_Write("                         ,lddddddddddddddddddddddddddl, \r\n");
	CLI_Write("                        :KWMMMMMMMMMMMMMMMMMMMMMMMMMMWK: \r\n");
	CLI_Write("                        .oNWX0000000000000000000000XWNo. \r\n");
	CLI_Write("                         ;XX:                      :XX; \r\n");
	CLI_Write("                         ;XX;                      ;XX; \r\n");
	CLI_Write("                         ;XX;                      ;XX; \r\n");
	CLI_Write("                         ;XX;                      ;XX; \r\n");
	CLI_Write("                         ;XX;                      ;XX; \r\n");
	CLI_Write("                         ;XX;                      ;XX; \r\n");
	CLI_Write("                        .oKx.                      .xKo. \r\n");
	CLI_Write("                       :0Nx.                        .kXo. \r\n");
	CLI_Write("                      :KWk.                          .kNk; \r\n");
	CLI_Write("                     :KWk'            ....            'kWK: \r\n");
	CLI_Write("                    ;KXx'     .;.   .c0NN0c.   .;.     'xXK; \r\n");
	CLI_Write("                   ;K0:      .xX0l;l0WMMMMW0l;l0Xx.      :0K; \r\n");
	CLI_Write("                 .c00:    'c, .lXWWWMMMMMMMMWWWXl. ,c'    :00c. \r\n");
	CLI_Write("                .xN0:    .lKXxcoXMMMWMMMMMMWMMMXocxXKl.    :0Nk. \r\n");
	CLI_Write("               .xXK:  'lc..;0MMMMMXdckNMMNkcdXMMMMM0;..cl'  ;KXx. \r\n");
	CLI_Write("              'xKd.  .:ON0ooKWNNWWo  .xNNx.  oWWNNWKoo0NO:.  ;KNx' \r\n");
	CLI_Write("             'kXo..od,..xWMMWx';dx,   ....   ,xo;'xWMMWx..,do,;dXk. \r\n");
	CLI_Write("           .lKNo. 'dXXkd0WMMWd.       .;oodl.    .dWMMW0dkXXd' .oNk. \r\n");
	CLI_Write("          .lXWo.    lXMMMMWWWk,    .;lkNMMMX;    ,kWWWMMMMXl    .oX0c. \r\n");
	CLI_Write("         .lNNo.    ,OWMMM0:,,.   .c0WMMMMMMW0c.   .,,:0MMMW0c.   .oNNl. \r\n");
	CLI_Write("         lXKo.     lWMMMMKd:.   .dWMMMMMMMMMMWd.   .:dKMMMMMW0c.  .oKXl. \r\n");
	CLI_Write("        lXO,       lWMMMMMMX;   .xMMMMMMMMMMMMx.   ;XMMMMMMMMMXl.   ,OXl. \r\n");
	CLI_Write("      .oKO,        lWMMMM0l;.    ,OWMMMMMMMMWO,    .;l0MMMMMNk;.     ,OKo. \r\n");
	CLI_Write("     ,ONk'         ,OWMMM0l::.    'kNWWWWWWNk'    .::l0MMMWO:.        'kNO, \r\n");
	CLI_Write("    ,0Nk'         .c0NXNMMMMWO,    .';,,,,;'.    ,OWMMMMNXN0c.         'kN0, \r\n");
	CLI_Write("   ;O0c.         .lX0c.:0WMMWo.                  .oWMMW0:.c0Xl.         'OWO; \r\n");
	CLI_Write("  .xMx.           ... ,dXX0NWk;:xO;   .,,.   ;Ox:;kWN0XXd, ...           'OMx. \r\n");
	CLI_Write(" .lKO,               .dKx,.lKWWWMWd. .kWWk. .dWMWWWKl.,xKd.              .oNXl. \r\n");
	CLI_Write(" .OWl                 .. .cON0ONMMNkdOWMMWOdkNMMNO0NOc. ..                .dWO' \r\n");
	CLI_Write(" .OWl                    'xOc..dNMMMMMMMMMMMMMMNd..cOx'                    lWO. \r\n");
	CLI_Write(" .kNo.                       'dXXxkNMMMMMMMMNkxXXd'                       .oNk. \r\n");
	CLI_Write("  'OXl                       ,xd, .;kNMMMMNk;. ,dx,                       lXO' \r\n");
	CLI_Write("  .oNKo.                            .:kKKk:.                            .oKNo. \r\n");
	CLI_Write("   .;kXKo.                            ....                            .oKXk;. \r\n");
	CLI_Write("     .:kNKko;......................................................;okKNk:. \r\n");
	CLI_Write("       .;lxKKKKKKKKKKKKKKKKKKKKKK0KKKKKKKKKKKK0KKKKKKKKKKKKKKKKKKKKKKxl;. \r\n");
	CLI_Write("          .,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,. \r\n");
	CLI_NewLine();



	CLI_NewLine();
	CLI_Write("   --------------------------------------------  \r\n");
	CLI_Write("  |                                            | \r\n");
	CLI_Write("  |  STM32 EXPLORER BOARD                      | \r\n");
	CLI_Write("  |  STM32XP Rev.00                            | \r\n");
	sprintf(console_buffer,
			  "  |  Firmware Version: %d.%d.%d                   | \r\n",
			        				  V_MAJOR, V_MINOR, V_PATCH);
	CLI_Write(console_buffer);												// Version
	sprintf(console_buffer,
			  "  |  %4d.%02d.%02d                                | \r\n",
			        V_YEAR, V_MONTH, V_DAY);
	CLI_Write(console_buffer);												// Date
	CLI_Write("  |                                            | \r\n");
	CLI_Write("  |  Developed by Eng. Andre A. M. Araujo      | \r\n");
	CLI_Write("  |  https://github.com/MechatronixLab/        | \r\n");
	CLI_Write("  |                                            | \r\n");
	CLI_Write("   --------------------------------------------  \r\n");
	CLI_NewLine();
}
