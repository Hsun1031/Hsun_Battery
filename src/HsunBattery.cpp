#include <HsunBattery.h>

HsunBattery::HsunBattery(uint8_t pin) {
    _pin = pin;
}

uint8_t HsunBattery::begin(float maxVolt, float maxBatteryVolt){
    if(maxVolt > 3.3){
        printf("Error! The Esp32 Max Volt In is 3.3V!\n");
        return Hsun_Battery_ERROR;
    }

    if(maxVolt <= 0 || maxBatteryVolt  <= 0){
        printf("Error! The Volt is loss\n");
        return Hsun_Battery_ERROR;
    }
    
    _coefficient = ESP32_ADC_MAX_VOLT / ESP32_ADC_MAX_VALUE / maxVolt;
    _maxBatteryVolt = maxBatteryVolt;

    pinMode(_pin, INPUT);
    return Hsun_Battery_OK;
}

float HsunBattery::getBatteryVolt() {
    float volt = (_maxBatteryVolt * getBatteryPercentage() / 100);
    return volt;
}

uint8_t HsunBattery::getBatteryPercentage() {
    uint8_t percentage = ((getBatteryValue() * _coefficient) * 100);
    return (percentage > 100)? 100 : ((percentage < 0)? 0 : percentage);
}

float HsunBattery::getBatteryValue() {
    int i     = 0;
    int total = 0;

    while(i < AVERAGE_TIMES) {
        total += analogRead(_pin);
        i++;
    }
    return (total / i);
}

