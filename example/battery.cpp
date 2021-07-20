#include <Arduino.h>
#include <HsunBattery.h>

#define BATTERY 18

HsunBattery hsunBattery(BATTERY);

void setup() {
    /** 
     * set input Volt and Battery Volt.
     * input Volt => 3V (max: 3.3V)
     * Battery Volt => 12V 
     * 0 -> Battery_ERRO, 1 -> Battery_OK. */
    hsunBattery.begin();
}

void loop() {
    //      Battery: 50%
    printf("Battery: %d%%\n",  hsunBattery.getBatteryPercentage());

    //      Battery: 3.47V
    printf("Battery: %.2fV\n", hsunBattery.getBatteryVolt());
}