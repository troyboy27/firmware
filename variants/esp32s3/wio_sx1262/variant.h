/*
  _______               _____       _           _   _____  _     _    _
 |__   __|             / ____|     (_)         | | |  __ \(_)   | |  | |
    | | _____      __ | (___  _ __   _  ___  ___| |_| |  | |_  __| |  | |
    | |/ _ \ \ /\ / /  \___ \| '_ \ | |/ _ \/ __| __| |  | | |/ _` |  | |
    | | (_) \ V  V /   ____) | | | || |  __/ (__| |_| |__| | | (_| |  | |
    |_|\___/ \_/\_/   |_____/|_| |_|/ |\___|\___|\__|_____/|_|\__,_|  |_|
                                  _/ |
                                 |__/

Board Information: https://www.seeedstudio.com/Wio-SX1262-with-XIAO-ESP32S3-p-5982.html
*/

#define WIO_SX1262

// Wio SX1262 LED pin configuration
#define LED_PIN 48
#define LED_STATE_ON 1 // State when LED is lit

// Button pin
#define BUTTON_PIN 21 // User button on the Wio SX1262 board
#define BUTTON_NEED_PULLUP

// Battery pin
#define BATTERY_PIN -1
#define ADC_CHANNEL ADC1_GPIO1_CHANNEL
#define BATTERY_SENSE_RESOLUTION_BITS 12

// GPS configuration (if needed)
// #define GPS_RX_PIN 44
// #define GPS_TX_PIN 43
// #define HAS_GPS 1
// #define GPS_BAUDRATE 9600
// #define GPS_THREAD_INTERVAL 50
// #define PIN_SERIAL1_RX PIN_GPS_TX
// #define PIN_SERIAL1_TX PIN_GPS_RX
// #define PIN_GPS_STANDBY 1

// OLED Screen (if needed)
// #define USCREEN_SSD1306
// #define I2C_SDA 5
// #define I2C_SCL 6

// Wio SX1262 LORA module
#define USE_SX1262

#define LORA_MISO 8
#define LORA_SCK 7
#define LORA_MOSI 9
#define LORA_CS 41

#define LORA_RESET 42
#define LORA_DIO1 39

#define LORA_DIO2 38

#ifdef USE_SX1262
#define SX126X_CS LORA_CS
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY 40
#define SX126X_RESET LORA_RESET

// DIO2 controls an antenna switch and the TCXO voltage is controlled by DIO3
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_RXEN 38
#define SX126X_TXEN RADIOLIB_NC
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
#endif