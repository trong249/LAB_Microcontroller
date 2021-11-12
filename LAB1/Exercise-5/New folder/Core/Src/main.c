/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#define A_1B() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET)
#define B_1B() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET)
#define C_1B() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET)
#define D_1B() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET)
#define E_1B() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET)
#define F_1B() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_SET)
#define G_1B() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET)

#define A_0B() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET)
#define B_0B() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET)
#define C_0B() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET)
#define D_0B() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET)
#define E_0B() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET)
#define F_0B() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET)
#define G_0B() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET)
/*****************************************************************/
#define A_1A() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET)
#define B_1A() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET)
#define C_1A() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET)
#define D_1A() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET)
#define E_1A() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET)
#define F_1A() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET)
#define G_1A() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET)

#define A_0A() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET)
#define B_0A() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET)
#define C_0A() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET)
#define D_0A() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET)
#define E_0A() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET)
#define F_0A() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET)
#define G_0A() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET)
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
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
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  	  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);  // Xanh-ngang
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);  // Vang-ngang
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);  // Do-ngang
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0); // Do-doc
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1); //Vang-doc
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1); //Xanh-doc

	  	 	  display7SEG_A(3); display7SEG_B(5);HAL_Delay(1000);
	  	 	  display7SEG_A(2); display7SEG_B(4);HAL_Delay(1000);
	  	 	  display7SEG_A(1); display7SEG_B(3);HAL_Delay(1000);


	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);  // Xanh-ngang
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);  // Vang-ngang
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);  // Do-ngang
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0); // Do-doc
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1); //Vang-doc
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1); //Xanh-doc

	  	 	  display7SEG_A(2); display7SEG_B(2);HAL_Delay(1000);
	  	 	  display7SEG_A(1); display7SEG_B(1);HAL_Delay(1000);

	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);  // Xanh-ngang
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);  // Vang-ngang
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);  // Do-ngang
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1); // Do-doc
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1); //Vang-doc
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0); //Xanh-doc

	  	 	  display7SEG_A(5); display7SEG_B(3);HAL_Delay(1000);
	  	 	  display7SEG_A(4); display7SEG_B(2);HAL_Delay(1000);
	  	 	  display7SEG_A(3); display7SEG_B(1);HAL_Delay(1000);

	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);  // Xanh-ngang
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);  // Vang-ngang
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);  // Do-ngang
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1); // Do-doc
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0); //Vang-doc
	  	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1); //XAnh-doc

	  	 	  display7SEG_A(2); display7SEG_B(2);HAL_Delay(1000);
	  	 	  display7SEG_A(1); display7SEG_B(1);HAL_Delay(1000);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

void display7SEG_A(int a){
	if (a==0){
		A_0A();B_0A();C_0A();D_0A();E_0A();F_0A();G_1A();
	}
	if (a==1){
		A_1A();B_0A();C_0A();D_1A();E_1A();F_1A();G_1A();
	}
	if (a==2){
		A_0A();B_0A();C_1A();D_0A();E_0A();F_1A();G_0A();
	}
	if (a==3){
		A_0A();B_0A();C_0A();D_0A();E_1A();F_1A();G_0A();
	}
	if (a==4){
		A_1A();B_0A();C_0A();D_1A();E_1A();F_0A();G_0A();
	}
	if (a==5){
		A_0A();B_1A();C_0A();D_0A();E_1A();F_0A();G_0A();
	}
}
void display7SEG_B(int a){
	if (a==0){
		A_0B();B_0B();C_0B();D_0B();E_0B();F_0B();G_1B();
	}
	if (a==1){
		A_1B();B_0B();C_0B();D_1B();E_1B();F_1B();G_1B();
	}
	if (a==2){
		A_0B();B_0B();C_1B();D_0B();E_0B();F_1B();G_0B();
	}
	if (a==3){
		A_0B();B_0B();C_0B();D_0B();E_1B();F_1B();G_0B();
	}
	if (a==4){
		A_1B();B_0B();C_0B();D_1B();E_1B();F_0B();G_0B();
	}
	if (a==5){
		A_0B();B_1B();C_0B();D_0B();E_1B();F_0B();G_0B();
	}
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA1 PA2 PA3 PA4
                           PA5 PA6 PA14 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB10
                           PB11 PB3 PB4 PB5
                           PB6 PB7 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
