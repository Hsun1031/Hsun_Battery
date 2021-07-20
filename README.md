# Hsun Battery

**This library is foe ESP32**

## How to use?

* begin
  * maxVolt          input Volt   => 3V (max: 3.3V)
  * maxBatteryVolt   Battery Volt => 12V
  * return           0 -> Battery_ERROR, 1 -> Battery_OK.

```cpp
begin(float maxVolt, float maxBatteryVolt);
```

* getBatteryVolt
  * Get Battery Volt => (ex: 7V)
  * return Battery Volt

```cpp
getBatteryVolt();
```

* getBatteryPercentage
  * Get Battery Percentage => (ex: 56%)
  * return Battery Percentage

```cpp
getBatteryPercentage();
```

* getBatteryValue

```cpp
getBatteryValue();
```
