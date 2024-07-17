#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"
#include "keymap_croatian.h"
#include "keymap_turkish_q.h"
#include "keymap_slovak.h"
#include "keymap_steno.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)

enum custom_keycodes {
	RGB_SLD = EZ_SAFE_RANGE,
	HSV_0_0_255,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] =
	    LAYOUT_ergodox_pretty(KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5,
				  KC_LBRACKET, KC_RBRACKET, KC_6, KC_7, KC_8,
				  KC_9, KC_0, KC_SCOLON,
				  KC_TAB, KC_Q, KC_D, KC_R, KC_W, KC_B,
				  KC_TRANSPARENT, KC_NO, KC_J, KC_F, KC_U, KC_P,
				  KC_QUOTE, KC_BSLASH,
				  KC_BSPACE, KC_A, KC_S, KC_H, KC_T, KC_G, KC_Y,
				  KC_N, KC_E, KC_O, KC_I, KC_MINUS,
				  KC_LSPO, KC_Z, KC_X, KC_M, KC_C, KC_V,
				  KC_GRAVE, TO(1), KC_K, KC_L, KC_COMMA, KC_DOT,
				  KC_SLASH, KC_RSPC,
				  KC_LCTRL, KC_MEH, KC_HYPR, KC_LGUI, KC_LALT,
				  KC_EQUAL, TG(2), TT(3), KC_PLUS, KC_GRAVE,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_CAPSLOCK,
				  KC_TRANSPARENT, KC_RGUI,
				  KC_SPACE, MO(4), TG(4), KC_RALT, KC_RCTRL,
				  KC_ENTER),
	[1] =
	    LAYOUT_ergodox_pretty(KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_Q, KC_W, KC_E, KC_R, KC_T,
				  KC_TRANSPARENT, TO(0), KC_Y, KC_U, KC_I, KC_O,
				  KC_P, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_A, KC_S, KC_D, KC_F, KC_G,
				  KC_H, KC_J, KC_K, KC_L, KC_QUOTE,
				  KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_Z, KC_X, KC_C, KC_V, KC_B,
				  KC_TRANSPARENT, KC_TRANSPARENT, KC_N, KC_M,
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
				  KC_TRANSPARENT, KC_TRANSPARENT),
	[2] =
	    LAYOUT_ergodox_pretty(KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, STN_N1, STN_N2, STN_N3,
				  STN_N4, STN_N5, KC_TRANSPARENT, TO(0), STN_N6,
				  STN_N7, STN_N8, STN_N9, STN_NA, STN_NB,
				  KC_TRANSPARENT, STN_S1, STN_TL, STN_PL,
				  STN_HL, STN_ST1, STN_ST3, STN_FR, STN_PR,
				  STN_LR, STN_TR, STN_DR,
				  KC_TRANSPARENT, STN_S2, STN_KL, STN_WL,
				  STN_RL, STN_ST2, KC_TRANSPARENT,
				  KC_TRANSPARENT, STN_ST4, STN_RR, STN_BR,
				  STN_GR, STN_SR, STN_ZR,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_ENTER,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  STN_A, STN_O, KC_TRANSPARENT, KC_TRANSPARENT,
				  STN_E, STN_U),
	[3] =
	    LAYOUT_ergodox_pretty(KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4,
				  KC_F5, KC_TRANSPARENT, KC_TRANSPARENT, KC_F6,
				  KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
				  KC_TRANSPARENT, KC_PSCREEN, KC_SCROLLLOCK,
				  KC_PAUSE, KC_INSERT, KC_TRANSPARENT,
				  KC_TRANSPARENT, TO(0), KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT, KC_F12,
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
				  RGB_SLD, RGB_MOD, TOGGLE_LAYER_COLOR,
				  HSV_0_0_255,
				  RGB_SPI, RGB_SAI,
				  RGB_VAD, RGB_VAI, RGB_SPD, RGB_SAD, RGB_HUI,
				  RGB_HUD),
	[4] =
	    LAYOUT_ergodox_pretty(KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,
				  KC_MS_BTN3, KC_MS_WH_DOWN, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_MS_BTN4, KC_MS_BTN1,
				  KC_MS_UP, KC_MS_BTN2, KC_MS_BTN5,
				  KC_TRANSPARENT, TO(0), KC_PGUP, KC_INSERT,
				  KC_HOME, KC_END, KC_DELETE, KC_TRANSPARENT,
				  KC_TRANSPARENT, KC_MS_WH_LEFT, KC_MS_LEFT,
				  KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_RIGHT,
				  KC_PGDOWN, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
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
			rgblight_sethsv_noeeprom(0, 0, rgblight_get_val());
		}
		break;
	case 1:
		if (!disable_layer_color) {
			rgblight_enable_noeeprom();
			rgblight_mode_noeeprom(1);
			rgblight_sethsv_noeeprom(0, 0, rgblight_get_val());
		}
		break;
	case 2:
		if (!disable_layer_color) {
			rgblight_enable_noeeprom();
			rgblight_mode_noeeprom(1);
			rgblight_sethsv_noeeprom(172, 255, rgblight_get_val());
		}
		break;
	case 3:
		if (!disable_layer_color) {
			rgblight_enable_noeeprom();
			rgblight_mode_noeeprom(1);
			rgblight_sethsv_noeeprom(215, 255, rgblight_get_val());
		}
		break;
	case 4:
		if (!disable_layer_color) {
			rgblight_enable_noeeprom();
			rgblight_mode_noeeprom(1);
			rgblight_sethsv_noeeprom(0, 255, rgblight_get_val());
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
