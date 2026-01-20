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
#define MXT_INVERT_X
#define MXT_INVERT_Y
/* Original PROCYON_57_80
#    define MXT_SENSOR_WIDTH_MM 57
#    define MXT_SENSOR_HEIGHT_MM 80
#    define MXT_MATRIX_X_SIZE 14
#    define MXT_MATRIX_Y_SIZE 20
#    define MXT_MESALLOW 3
*/
// #define PROCYON_57_80

/* Modified PROCYON_57_80 */
#define MXT_SENSOR_WIDTH_MM 128
#define MXT_SENSOR_HEIGHT_MM 92
#define MXT_MATRIX_X_SIZE 14
#define MXT_MATRIX_Y_SIZE 20
#define MXT_MESALLOW 3

#    ifndef MXT_GAIN
#        define MXT_GAIN 10
#    endif
#    ifndef MXT_TOUCH_THRESHOLD
#        define MXT_TOUCH_THRESHOLD 20
#    endif
#    ifndef MXT_TOUCH_HYST
#        define MXT_TOUCH_HYST 10
#    endif
#    ifndef MXT_INTERNAL_TOUCH_THRESHOLD
#        define MXT_INTERNAL_TOUCH_THRESHOLD 10
#    endif
#    ifndef MXT_INTERNAL_TOUCH_HYST
#        define MXT_INTERNAL_TOUCH_HYST 5
#    endif
#    define MXT_T56_SHIELDLESS_ENABLE
#    define MXT_RETRANSMISSION_COMPENSATION_ENABLE 0
#    define MXT_X_PITCH 38 // Procyon boards have a standard 3.8mm pitch
#    define MXT_Y_PITCH 38
#    define MXT_ACTIVE_ACQUISITION_INTERVAL 255 // Free run while active - this enables us to reach a polling rate of around 300Hz
#    define MXT_CONFTHR 5 // Increase debounce time
#    define MXT_MOVE_HYSTERESIS_NEXT 16





// #define SPLIT_DIGITIZER_ENABLE
// #define DIGITIZER_RIGHT
// #define DIGITIZER_LEFT

