/*
 * rtcc.c
 *
 *  Created on: Aug 23, 2024
 *      Author: Eng. André A. M. Araújo
 */

#include "rtcc.h"

void RTCC_Init(void)
{
	// https://stackoverflow.com/questions/60755326/stm32h7-rtc-resets-after-power-down-vbat-is-connected

	RTC_TimeTypeDef sTime = {0};
	RTC_DateTypeDef sDate = {0};

	//Initialize RTC Only
	hrtc.Instance = RTC;
	hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
	hrtc.Init.AsynchPrediv = 127;
	hrtc.Init.SynchPrediv = 255;
	hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
	hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
	hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;

	if (HAL_RTC_Init(&hrtc) != HAL_OK)
	{
		Error_Handler();
	}

	//##-1- Check if Data stored in BackUp register1: No Need to reconfigure RTC#*/
	// Read the Back Up Register 1 Data */
	if (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) != RTC_BKUP_DEFINE_CODE)
	{
	// Clear Backup registor : recover to current RTC information

	// Set to Time/Date from current Time/Date

		sTime.Hours = 22;
		sTime.Minutes = 45;
		sTime.Seconds = 0;
		sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
		sTime.StoreOperation = RTC_STOREOPERATION_SET;
		if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
		{
			Error_Handler();
		}

		sDate.WeekDay = RTC_WEEKDAY_SATURDAY;
		sDate.Month = RTC_MONTH_JANUARY;
		sDate.Date = 17;
		sDate.Year = 25;
		if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
		{
			Error_Handler();
		}

	// Write a data in ad RTC Backup data register
	HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, RTC_BKUP_DEFINE_CODE);
	}
	else
	{
		// Only read time and date
		HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
	}
}
