LTO_ENABLE = yes
VIA_ENABLE = yes
VIAL_ENABLE = yes
VIALRGB_ENABLE = yes


# VIALRGB_ENABLE=yes requires RGB_MATRIX_ENABLE=yes
# Do not enable RGB_MATRIX_ENABLE together with RGBLIGHT_ENABLE


QMK_SETTINGS = yes
MAGIC_ENABLE = yes
GRAVE_ESC_ENABLE = yes
TAP_DANCE_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes


SERIAL_DRIVER = vendor      # RP2040用に追加
#BOARD = GENERIC_RP_RP2040   # RP2040用に追加 いろんな定義を全部自分でやらないといけなくなるので無指定