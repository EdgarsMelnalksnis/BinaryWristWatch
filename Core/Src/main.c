/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define LED_BLINK_DELAY 10
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC_Init(void);
static void MX_RTC_Init(void);
static void set_LED(uint32_t, uint32_t); //set LEDs (Anode,Cathode)
static void reset_LED(void); //all leds off (sets all GPIO ports as inputs)
static void blink_LED(uint32_t, uint32_t, uint32_t); //blink led (anode,cathode,delay)
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */

	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

	/* System interrupt init*/

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	//MX_GPIO_Init();
	LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA); //enable clock for GPIOA
	MX_DMA_Init();
	MX_ADC_Init();
	MX_RTC_Init();
	/* USER CODE BEGIN 2 */

	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {
		blink_LED(LL_GPIO_PIN_7, LL_GPIO_PIN_8, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_7, LL_GPIO_PIN_9, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_7, LL_GPIO_PIN_10, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_7, LL_GPIO_PIN_11, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_7, LL_GPIO_PIN_12, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_8, LL_GPIO_PIN_9, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_8, LL_GPIO_PIN_10, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_8, LL_GPIO_PIN_11, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_8, LL_GPIO_PIN_12, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_9, LL_GPIO_PIN_10, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_9, LL_GPIO_PIN_11, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_9, LL_GPIO_PIN_12, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_10, LL_GPIO_PIN_11, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_10, LL_GPIO_PIN_12, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_11, LL_GPIO_PIN_12, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_8, LL_GPIO_PIN_7, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_9, LL_GPIO_PIN_7, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_10, LL_GPIO_PIN_7, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_9, LL_GPIO_PIN_8, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_12, LL_GPIO_PIN_7, LED_BLINK_DELAY);
		blink_LED(LL_GPIO_PIN_11, LL_GPIO_PIN_7, LED_BLINK_DELAY);

		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);

	if (LL_FLASH_GetLatency() != LL_FLASH_LATENCY_0) {
		Error_Handler();
	}
	LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);
	LL_RCC_LSI_Enable();

	/* Wait till LSI is ready */
	while (LL_RCC_LSI_IsReady() != 1) {

	}
	LL_RCC_MSI_Enable();

	/* Wait till MSI is ready */
	while (LL_RCC_MSI_IsReady() != 1) {

	}
	LL_RCC_MSI_SetRange(LL_RCC_MSIRANGE_5);
	LL_RCC_MSI_SetCalibTrimming(0);
	LL_PWR_EnableBkUpAccess();
	LL_RCC_ForceBackupDomainReset();
	LL_RCC_ReleaseBackupDomainReset();
	LL_RCC_SetRTCClockSource(LL_RCC_RTC_CLKSOURCE_LSI);
	LL_RCC_EnableRTC();
	LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
	LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
	LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
	LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_MSI);

	/* Wait till System clock is ready */
	while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_MSI) {

	}

	LL_Init1msTick(2097000);

	LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK);
	LL_SetSystemCoreClock(2097000);
}

/**
 * @brief ADC Initialization Function
 * @param None
 * @retval None
 */
static void MX_ADC_Init(void) {

	/* USER CODE BEGIN ADC_Init 0 */

	/* USER CODE END ADC_Init 0 */

	LL_ADC_REG_InitTypeDef ADC_REG_InitStruct = { 0 };
	LL_ADC_InitTypeDef ADC_InitStruct = { 0 };

	LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* Peripheral clock enable */
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_ADC1);

	LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);
	/**ADC GPIO Configuration
	 PA0-CK_IN   ------> ADC_IN0
	 */
	GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/* ADC DMA Init */

	/* ADC Init */
	LL_DMA_SetPeriphRequest(DMA1, LL_DMA_CHANNEL_1, LL_DMA_REQUEST_0);

	LL_DMA_SetDataTransferDirection(DMA1, LL_DMA_CHANNEL_1,
	LL_DMA_DIRECTION_PERIPH_TO_MEMORY);

	LL_DMA_SetChannelPriorityLevel(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PRIORITY_LOW);

	LL_DMA_SetMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MODE_NORMAL);

	LL_DMA_SetPeriphIncMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PERIPH_NOINCREMENT);

	LL_DMA_SetMemoryIncMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MEMORY_INCREMENT);

	LL_DMA_SetPeriphSize(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PDATAALIGN_HALFWORD);

	LL_DMA_SetMemorySize(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MDATAALIGN_HALFWORD);

	/* USER CODE BEGIN ADC_Init 1 */

	/* USER CODE END ADC_Init 1 */
	/** Configure Regular Channel
	 */
	LL_ADC_REG_SetSequencerChAdd(ADC1, LL_ADC_CHANNEL_0);
	/** Common config
	 */
	ADC_REG_InitStruct.TriggerSource = LL_ADC_REG_TRIG_SOFTWARE;
	ADC_REG_InitStruct.SequencerDiscont = LL_ADC_REG_SEQ_DISCONT_DISABLE;
	ADC_REG_InitStruct.ContinuousMode = LL_ADC_REG_CONV_SINGLE;
	ADC_REG_InitStruct.DMATransfer = LL_ADC_REG_DMA_TRANSFER_LIMITED;
	ADC_REG_InitStruct.Overrun = LL_ADC_REG_OVR_DATA_PRESERVED;
	LL_ADC_REG_Init(ADC1, &ADC_REG_InitStruct);
	LL_ADC_SetSamplingTimeCommonChannels(ADC1, LL_ADC_SAMPLINGTIME_1CYCLE_5);
	LL_ADC_SetOverSamplingScope(ADC1, LL_ADC_OVS_DISABLE);
	LL_ADC_REG_SetSequencerScanDirection(ADC1, LL_ADC_REG_SEQ_SCAN_DIR_FORWARD);
	LL_ADC_SetCommonFrequencyMode(__LL_ADC_COMMON_INSTANCE(ADC1),
	LL_ADC_CLOCK_FREQ_MODE_HIGH);
	LL_ADC_DisableIT_EOC(ADC1);
	LL_ADC_DisableIT_EOS(ADC1);
	LL_ADC_EnableInternalRegulator(ADC1);
	ADC_InitStruct.Clock = LL_ADC_CLOCK_SYNC_PCLK_DIV1;
	ADC_InitStruct.Resolution = LL_ADC_RESOLUTION_12B;
	ADC_InitStruct.DataAlignment = LL_ADC_DATA_ALIGN_RIGHT;
	ADC_InitStruct.LowPowerMode = LL_ADC_LP_MODE_NONE;
	LL_ADC_Init(ADC1, &ADC_InitStruct);
	/* USER CODE BEGIN ADC_Init 2 */

	/* USER CODE END ADC_Init 2 */

}

/**
 * @brief RTC Initialization Function
 * @param None
 * @retval None
 */
static void MX_RTC_Init(void) {

	/* USER CODE BEGIN RTC_Init 0 */

	/* USER CODE END RTC_Init 0 */

	LL_RTC_InitTypeDef RTC_InitStruct = { 0 };
	LL_RTC_TimeTypeDef RTC_TimeStruct = { 0 };
	LL_RTC_DateTypeDef RTC_DateStruct = { 0 };

	/* Peripheral clock enable */
	LL_RCC_EnableRTC();

	/* USER CODE BEGIN RTC_Init 1 */

	/* USER CODE END RTC_Init 1 */
	/** Initialize RTC and set the Time and Date
	 */
	RTC_InitStruct.HourFormat = LL_RTC_HOURFORMAT_24HOUR;
	RTC_InitStruct.AsynchPrescaler = 127;
	RTC_InitStruct.SynchPrescaler = 255;
	LL_RTC_Init(RTC, &RTC_InitStruct);
	/** Initialize RTC and set the Time and Date
	 */
	RTC_TimeStruct.Hours = 0;
	RTC_TimeStruct.Minutes = 0;
	RTC_TimeStruct.Seconds = 0;
	LL_RTC_TIME_Init(RTC, LL_RTC_FORMAT_BCD, &RTC_TimeStruct);
	RTC_DateStruct.WeekDay = LL_RTC_WEEKDAY_MONDAY;
	RTC_DateStruct.Month = LL_RTC_MONTH_JANUARY;
	RTC_DateStruct.Year = 0;
	LL_RTC_DATE_Init(RTC, LL_RTC_FORMAT_BCD, &RTC_DateStruct);
	/* USER CODE BEGIN RTC_Init 2 */

	/* USER CODE END RTC_Init 2 */

}

/** 
 * Enable DMA controller clock
 */
static void MX_DMA_Init(void) {

	/* Init with LL driver */
	/* DMA controller clock enable */
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);

	/* DMA interrupt init */
	/* DMA1_Channel1_IRQn interrupt configuration */
	NVIC_SetPriority(DMA1_Channel1_IRQn, 0);
	NVIC_EnableIRQ(DMA1_Channel1_IRQn);

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* GPIO Ports Clock Enable */
	LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);

	/**/
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_7);

	/**/
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_8);

	/**/
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_9);

	/**/
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_10);

	/**/
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_11);

	/**/
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_12);

	/**/
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_15);

	/**/
	GPIO_InitStruct.Pin = LL_GPIO_PIN_7;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/**/
	GPIO_InitStruct.Pin = LL_GPIO_PIN_8;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/**/
	GPIO_InitStruct.Pin = LL_GPIO_PIN_9;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/**/
	GPIO_InitStruct.Pin = LL_GPIO_PIN_10;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/**/
	GPIO_InitStruct.Pin = LL_GPIO_PIN_11;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/**/
	GPIO_InitStruct.Pin = LL_GPIO_PIN_12;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/**/
	GPIO_InitStruct.Pin = LL_GPIO_PIN_15;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
static void set_LED(uint32_t LED_anode, uint32_t LED_cathode) //function to set LED
{
	//maybe start with reset?
	reset_LED();
	LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* GPIO Ports Clock Enable */

	/**/
	//LL_GPIO_ResetOutputPin(GPIOA, LED_anode);
	/**/
	//LL_GPIO_ResetOutputPin(GPIOA, LED_cathode);
	GPIO_InitStruct.Pin = LED_anode | LED_cathode; //GPIO pins as outputs
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	LL_GPIO_SetOutputPin(GPIOA, LED_anode);
	LL_GPIO_ResetOutputPin(GPIOA, LED_cathode);

}
static void reset_LED(void) //all leds off (sets all GPIO ports as inputs)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.Pin = LL_GPIO_PIN_7 | LL_GPIO_PIN_8 | LL_GPIO_PIN_9
			| LL_GPIO_PIN_10 | LL_GPIO_PIN_11 | LL_GPIO_PIN_12 | LL_GPIO_PIN_15; //GPIO pins as outputs
	GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
	//GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	//GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
static void blink_LED(uint32_t Anode, uint32_t Cathode, uint32_t delay)	//blink led (anode,cathode,delay)
{
	set_LED(Anode, Cathode);
//	LL_mDelay(delay);
	reset_LED();
}
/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
