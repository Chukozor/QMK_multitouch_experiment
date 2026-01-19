#include QMK_KEYBOARD_H
#include "timer.h"
#include "drivers/haptic/solenoid.h"
#include "keymap.h"
#include "keymap_french.h"


static void solenoid_helper(void){
  static uint16_t last_fire = 0;
  if (timer_elapsed(last_fire) > 80) {  // 80 ms entre deux activations
    solenoid_fire(0);
    last_fire = timer_read();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
      solenoid_helper();
    }
    return true;
    }

// -----------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // _DEBUGLAYER
    [_DEBUGLAYER] = LAYOUT_2_7_regular(
  //--------------------------------------.                                           -----------------------------------------------------.
       FR_A, KC_B, KC_C, KC_D, KC_E, KC_F,                                            S(FR_A), S(KC_B), S(KC_C), S(KC_D), S(KC_E), S(KC_F), 
  //|------+-----+-----+-----+-----+------|                                          |-------+--------+--------+--------+--------+---------|
    DB_TOGG, KC_H, KC_I, KC_J, KC_K, KC_L,                                            S(KC_G), S(KC_H), S(KC_I), S(KC_J), S(KC_K), S(KC_L), 
  //|------+-----+-----+-----+-----+------|                                          |-------+--------+--------+--------+--------+---------|
       KC_M, KC_N, KC_O, KC_P, FR_Q, KC_R,                                            S(KC_M), S(KC_N), S(KC_O), S(KC_P), S(FR_Q), S(KC_R), 
  //|------+-----+-----+-----+-----+------|                                          |-------+--------+--------+--------+--------+---------|
       KC_U, KC_V, FR_W, KC_X, KC_Y, FR_Z,                                            S(KC_U), S(KC_V), S(FR_W), S(KC_X), S(KC_Y), S(FR_Z), 
  //|------+-----+-----+-----+-----+------|                                          |-------+--------+--------+--------+--------+---------|
                  KC_P1,KC_P2,KC_P3,                                                             KC_P7,   KC_P8,   KC_P9,
                                    KC_P4,KC_P5,KC_P6,           KC_LEFT, KC_DOWN, KC_RIGHT
  //|---------------------------------------------------|           |----------------------------------------------------------------------|
  )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
}

// // // ==============================================
// void render_layer_status(void) {
//   switch (get_highest_layer(layer_state)){
//     case _DEBUGLAYER :
//       // -------|"-----00000-----00000-----00000-----00000-----"
//       //         "                                             "
//       // -------|"-----00000-----00000-----00000-----00000-----"
//       oled_write("DEBUGLAYER                                   ", false);
//       break;
//     }
//   }


// void render_logo(void) {
//   static const char PROGMEM logo[] = {
//     // 'cornia', 32x32px
//   0, 0, 0, 0, 0, 0, 0, 0, 192, 32, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 32, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 192, 224, 255, 255, 240, 224, 200, 132, 132, 6, 6, 6, 6, 132, 132, 204, 224, 240, 255, 255, 224, 192, 192, 128, 0, 0, 0, 0, 12, 7, 3, 1, 0, 0, 28, 112, 192, 1, 1, 3, 3, 1, 224, 224, 17, 3, 3, 1, 1, 192, 112, 28, 0, 0, 1, 3, 7, 12, 0, 0, 0, 0, 0, 0, 0, 0, 64, 64, 64, 97, 98, 114, 56, 60, 31, 31, 60, 56, 114, 98, 97, 64, 64, 64, 0, 0, 0, 0, 0, 0, 0
//   };
//   oled_write_raw_P(logo, sizeof(logo));
// }

// oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

// // Draw to OLED
// bool oled_task_user() {
//   oled_set_cursor(0, 0);
//   render_logo();
//   oled_set_cursor(0, 7);
//   render_layer_status();
//   return false;
// }

// void oled_render_boot(bool bootloader) {
//   oled_clear();
//   oled_set_cursor(0, 2);
//   if (bootloader) {
//     oled_write_P(PSTR("FLASH"), false);
//   } else {
//     oled_write_P(PSTR("RESET"), false);
//   }
//   oled_render_dirty(true);
// }

// bool shutdown_user(bool jump_to_bootloader) {
//   oled_render_boot(jump_to_bootloader);
//   return false;
// }