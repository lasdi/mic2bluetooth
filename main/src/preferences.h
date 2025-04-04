#ifndef PREFERENCES_H
#define PREFERENCES_H

// BLUETOOTH
#define TARGET_DEVICE_NAME "JBL Go 3"
#define LOCAL_DEVICE_NAME "Mic 2 Bluetooth"

// I2S PINS
#define WS_IO_PORT GPIO_NUM_22
#define SD_PORT GPIO_NUM_25
#define SCK_PORT GPIO_NUM_23
#define I2S_NUM I2S_NUM_0

// I2S CONFIG
#define FRAME_RATE 44100
#define N_WINDOW_ELEMENTS 1024

// QUEUE
#define MAX_SIZE_QUEUE 1024

#endif