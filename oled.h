/**
  ******************************************************************************
  * @file    oled.h
  * @brief   SSD1306 0.96 寸 OLED（128x64，4 针 I2C）驱动头文件
  *          接线：VCC->3.3V  GND->GND  SCL->PB8  SDA->PB9（I2C1 重映射）
  ******************************************************************************
  */

#ifndef __OLED_H
#define __OLED_H

#include "main.h"

#define OLED_I2C_ADDR   0x78    /* SSD1306 的 I2C 从机地址：7 位地址 0x3C 左移 1 位 */
#define OLED_I2C        hi2c1   /* 使用的 I2C 外设（I2C1 重映射：PB8=SCL，PB9=SDA） */

void OLED_Init(void);
void OLED_Clear(void);
void OLED_ClearLine(uint8_t page);
int16_t OLED_ShowMixString(int16_t x, uint8_t page, const char *str);
void OLED_ShowNum(uint8_t x, uint8_t page, int64_t num, uint8_t len);
void OLED_ShowFloat(uint8_t x, uint8_t page, float val, uint8_t int_len, uint8_t dec_len);

void OLED_ScrollSetup(void);
void OLED_ScrollStart(void);
void OLED_ScrollStop(void);
void OLED_ScrollBandDraw(const char *str, uint16_t offset_px, uint8_t page);

#endif /* __OLED_H */
