/**
 * @file      HsunBattery.h
 * @author    Hsun
 * @brief 
 * @version   0.1
 * @date      2021-07-06
 * 
 * @copyright Copyright © 2021
 * 
 */
#include <Arduino.h>

#ifndef __HSUN_BATTERY_H__
#define __HSUN_BATTERY_H__

    #define Hsun_Battery_ERROR  0x00
    #define Hsun_Battery_OK     0x01

    #define ESP32_ADC_MAX_VALUE 4060
    #define ESP32_ADC_MAX_VOLT  3.3
    #define AVERAGE_TIMES       100

    #define MAX_VOLT            3
    #define MAX_BATTERY_VOLT    12

    class HsunBattery {
        private:
            float   _coefficient;
            float   _maxBatteryVolt;
            uint8_t _pin;

        public:
            /** 
             * @brief     Set Battery input pin. 
             * 
             * @param pin input pin */
            HsunBattery(uint8_t pin);
            
            /** 
             * @brief Set input Volt and Battery Volt.
             *
             * @param  maxVolt          input Volt => 3V (max: 3.3V)
             * @param  maxBatteryVolt   Battery Volt => 12V
             * @return                  0 -> Battery_ERROR, 1 -> Battery_OK. */
            uint8_t begin(float maxVolt = MAX_VOLT, float maxBatteryVolt = MAX_BATTERY_VOLT);

            /** 
             * @brief  Get Battery Volt => (ex: 7V)
             * 
             * @return Battery Volt */
            float getBatteryVolt();

            /** 
             * @brief  Get Battery Percentage => (ex: 56%)
             * 
             * @return Battery Percentage */
            uint8_t getBatteryPercentage();

            float getBatteryValue();
    };

#endif

