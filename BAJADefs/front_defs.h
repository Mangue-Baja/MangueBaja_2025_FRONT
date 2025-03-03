#ifndef FRONT_DEFS_H
#define FRONT_DEFS_H

#include "mbed.h"
#include "FIR.h"
#include "defs.h"

#define CAN_BPS_1000K       1000000

/* IMU convertions */
#define PI                  3.1416
#define RAD_TO_DEGREE       180.0/PI
#define TO_G                2.0/32768.0
#define TO_DPS              245.0/32768.0
#define IMU_TRIES           10

/* SERVO state */ 
#define MID_MODE            0x00
#define RUN_MODE            0x01
#define CHOKE_MODE          0x02
#define SERVO_RESET         0x03
#define SERVOR_ERROR        0x04

typedef enum {
    IDLE_ST,        // wait
    IMU_ST,         // Process the acceleration and angular velocity 
    RPM_ST,         // Process the RPM of Motor
    //RADIO_ST,
    //VERIFY_4x4_ST,  // Verify if the 4x4 is enable
    THROTTLE_ST,    // Write throttle position (PWM)
    FLAGS_ST,       // Enable the bit if the condition is true, emergency and logging bits
    DISPLAY_ST,     // Send the data to panel
    DEBUG_ST        // Send data to Debug

} state_t;

typedef struct {
  uint16_t speed;     // 2by
  uint16_t rpm;       // 2by
  uint8_t temp_motor; // 1by
  uint16_t level;     // 2by
  uint8_t battery;    // 1by
  uint8_t temp_cvt;   // 1by
  uint8_t sot;        // 1by
  
} Txtmng;

typedef struct
{
    // MPU_Bluetooth (sent by physical serial connection)
    //  String config_bluetooth_enabled;
    //  String config_bluedroid_enabled;
    //  String config_bt_spp_enabled;

    // MPU
    uint8_t lora_init;

    // SCU
    uint8_t internet_modem;
    uint8_t mqtt_client_connection;
    uint8_t sd_start;
    uint8_t check_sd;

    // FRONT
    uint8_t accel_begin;    // 0

    // REAR
    uint8_t termistor;
    uint8_t cvt_temperature;
    uint8_t measure_volt;
    uint8_t speed_pulse_counter;
    uint16_t servo_state;

} bluetooth;

#endif
