#pragma once
// ====================================================================w
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 400U // Timeout window in ms in which the double tap can occur.
// ======= Solenoid =====
#define SOLENOID_COUNT 1
#define SOLENOID_PIN GP25
#define SOLENOID_DEFAULT_DWELL 15
#define SOLENOID_MIN_DWELL 15
#define SOLENOID_MAX_DWELL 20
// #define SOLENOID_DWELL_STEP_SIZE 1
#define NO_HAPTIC_MOD
// ==============================
/* I²C config */
#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP12
#define I2C1_SCL_PIN GP13

#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP0     // USART TX pin
#define SERIAL_USART_RX_PIN GP1     // USART RX pin
// ======= PROCYON =======
#define I2C1_CLOCK_SPEED 1000000
#define DIGITIZER_MOTION_PIN GP18
#define DIGITIZER_MOTION_PIN_ACTIVE_LOW yes
#define PROCYON_57_80
// #define SPLIT_DIGITIZER_ENABLE
// #define DIGITIZER_RIGHT
// #define DIGITIZER_LEFT

