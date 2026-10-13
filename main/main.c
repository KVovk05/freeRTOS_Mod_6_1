#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"
#include "freertos/idf_additions.h"
#include "freertos/projdefs.h"
#include "hal/gpio_types.h"
#include "freertos/FreeRTOS.h"
#include "soc/gpio_num.h"
#include "freertos/task.h"

void task_led1(void *pvParameters);
void task_led2(void *pvParameters);
void task_led3(void *pvParameters);

void app_main(void)
{

	gpio_reset_pin(GPIO_NUM_4);
	gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT);
	gpio_reset_pin(GPIO_NUM_5);
	gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);
	gpio_reset_pin(GPIO_NUM_7);
	gpio_set_direction(GPIO_NUM_7, GPIO_MODE_OUTPUT);
	xTaskCreatePinnedToCore(task_led1, "Led1", 2048, NULL, 5, NULL, 1);
	xTaskCreatePinnedToCore(task_led2, "Led2", 2048, NULL, 5, NULL, 1);
	xTaskCreatePinnedToCore(task_led3, "Led3", 2048, NULL, 5, NULL, 1);

}
void task_led1(void *pvParameters){
	
	for(;;){
		gpio_set_level(GPIO_NUM_4, 1);
		vTaskDelay(pdMS_TO_TICKS(50));
		gpio_set_level(GPIO_NUM_4, 0);
		vTaskDelay(pdMS_TO_TICKS(150));
	}
}
void task_led2(void *pvParameters){
	for(;;){
			gpio_set_level(GPIO_NUM_5, 1);
			vTaskDelay(pdMS_TO_TICKS(50));
			gpio_set_level(GPIO_NUM_5, 0);
			vTaskDelay(pdMS_TO_TICKS(450));
		}
}

void task_led3(void *pvParameters){
	for(;;){
		gpio_set_level(GPIO_NUM_7, 1);
		vTaskDelay(pdMS_TO_TICKS(50));
		gpio_set_level(GPIO_NUM_7, 0);
		vTaskDelay(pdMS_TO_TICKS(950));

	}
}

