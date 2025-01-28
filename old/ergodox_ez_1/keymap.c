#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
	RGB_SLD = EZ_SAFE_RANGE,
	HSV_0_0_255,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] =
	    LAYOUT_ergodox_pretty(KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5,
				  KC_LBRC, KC_RBRC, KC_6, KC_7, KC_8, KC_9,
				  KC_0, KC_SCLN,
				  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
				  KC_TRANSPARENT, KC_TRANSPARENT, KC_Y, KC_U,
				  KC_I, KC_O, KC_P, KC_BSLS,
				  KC_BSPC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H,
				  KC_J, KC_K, KC_L, KC_QUOTE, KC_MINUS,
				  SC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B,
				  KC_GRAVE, KC_TRANSPARENT, KC_N, KC_M,
				  KC_COMMA, KC_DOT, KC_SLASH, KC_TRANSPARENT,
				  KC_LEFT_CTRL, KC_MEH, KC_HYPR, KC_LEFT_GUI,
				  KC_LEFT_ALT, KC_EQUAL, KC_TRANSPARENT, TT(1),
				  KC_PLUS, KC_GRAVE,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_CAPS,
				  KC_TRANSPARENT, KC_RIGHT_GUI,
				  KC_SPACE, MO(2), TG(2), KC_RIGHT_ALT,
				  KC_RIGHT_CTRL, KC_ENTER),
	[1] =
	    LAYOUT_ergodox_pretty(KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4,
				  KC_F5, KC_TRANSPARENT, KC_TRANSPARENT, KC_F6,
				  KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
				  KC_TRANSPARENT, KC_PSCR, KC_SCRL, KC_PAUSE,
				  KC_INSERT, KC_TRANSPARENT, KC_TRANSPARENT,
				  TO(0), KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_F12,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  RGB_SLD, RGB_MODE_FORWARD, TOGGLE_LAYER_COLOR,
				  HSV_0_0_255,
				  RGB_SPI, RGB_SAI,
				  RGB_VAD, RGB_VAI, RGB_SPD, RGB_SAD, RGB_HUI,
				  RGB_HUD),
	[2] =
	    LAYOUT_ergodox_pretty(KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,
				  KC_MS_BTN3, KC_MS_WH_DOWN, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_MS_BTN4, KC_MS_BTN1,
				  KC_MS_UP, KC_MS_BTN2, KC_MS_BTN5,
				  KC_TRANSPARENT, TO(0), KC_INSERT, KC_HOME,
				  KC_END, KC_DELETE, KC_PAGE_UP, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_MS_WH_LEFT, KC_MS_LEFT,
				  KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_RIGHT,
				  KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGDN,
				  KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL0,
				  KC_MS_ACCEL1, KC_MS_ACCEL2, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_SPACE, KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT, KC_ENTER),
};

rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

bool suspended = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	switch (keycode) {

	case RGB_SLD:
		if (record->event.pressed) {
			rgblight_mode(1);
		}
		return false;
	case TOGGLE_LAYER_COLOR:
		if (record->event.pressed) {
			disable_layer_color ^= 1;
		}
		return false;
	case HSV_0_0_255:
		if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
			rgblight_enable();
			rgblight_mode(1);
			rgblight_sethsv(0, 0, 255);
#endif
		}
		return false;
	}
	return true;
}

uint8_t layer_state_set_user(uint8_t state)
{
	uint8_t layer = biton(state);
	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();
	switch (layer) {
	case 1:
		ergodox_right_led_1_on();
		break;
	case 2:
		ergodox_right_led_2_on();
		break;
	case 3:
		ergodox_right_led_3_on();
		break;
	case 4:
		ergodox_right_led_1_on();
		ergodox_right_led_2_on();
		break;
	case 5:
		ergodox_right_led_1_on();
		ergodox_right_led_3_on();
		break;
	case 6:
		ergodox_right_led_2_on();
		ergodox_right_led_3_on();
		break;
	case 7:
		ergodox_right_led_1_on();
		ergodox_right_led_2_on();
		ergodox_right_led_3_on();
		break;
	default:
		break;
	}
	switch (layer) {
	case 0:
		if (!disable_layer_color) {
			rgblight_enable_noeeprom();
			rgblight_mode_noeeprom(1);
			rgblight_sethsv_noeeprom(0, 0, rgblight_config.val);
		}
		break;
	case 1:
		if (!disable_layer_color) {
			rgblight_enable_noeeprom();
			rgblight_mode_noeeprom(1);
			rgblight_sethsv_noeeprom(215, 255, rgblight_config.val);
		}
		break;
	case 2:
		if (!disable_layer_color) {
			rgblight_enable_noeeprom();
			rgblight_mode_noeeprom(1);
			rgblight_sethsv_noeeprom(0, 255, rgblight_config.val);
		}
		break;
	default:
		if (!disable_layer_color) {
			rgblight_config.raw = eeconfig_read_rgblight();
			if (rgblight_config.enable == true) {
				rgblight_enable();
				rgblight_mode(rgblight_config.mode);
				rgblight_sethsv(rgblight_config.hue,
						rgblight_config.sat,
						rgblight_config.val);
			} else {
				rgblight_disable();
			}
		}
		break;
	}
	return state;
};

void keyboard_post_init_user(void)
{
	layer_state_set_user(layer_state);
}
