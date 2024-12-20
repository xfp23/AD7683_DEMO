#ifndef AD7683_H
#define AD7683_H

/**
 * @file AD7683.h
 * @author TTT
 * @brief AD7683的配置，此硬件芯片SPI最大速率不能超过2.9MHZ，采用SPI模式为：高极性，第二边沿采集
 * @version 0.1
 * @date 2024-12-12
 * 
 * @copyright TTT (c) 2024
 */

#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 硬件资源配置
 */
#define AD7683_SPI      &hspi1           // 选择使用的硬件SPI
#define AD7683_CS_PIN   GPIO_PIN_4      // 片选引脚
#define AD7683_CS_PORT  GPIOA           // 片选引脚端口
#define DMA_ENABLE      (0)             // DMA的使能与禁用：0禁用 1使能

// 片选控制定义
#define CS_LOW()  HAL_GPIO_WritePin(AD7683_CS_PORT, AD7683_CS_PIN, GPIO_PIN_RESET)
#define CS_HIGH() HAL_GPIO_WritePin(AD7683_CS_PORT, AD7683_CS_PIN, GPIO_PIN_SET)

#if !DMA_ENABLE
// 转换超时时间，单位为ms
#define TIMEOUT HAL_MAX_DELAY
#endif

/**
 * @brief 获取AD7683的ADC值
 * @return uint16_t 转换结果
 */
extern uint16_t AD7683_getADC(void);

#ifdef __cplusplus
}
#endif

#endif // AD7683_H
