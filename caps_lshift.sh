cat > /usr/share/X11/xkb/symbols/customsymbol << EOF
// Remap caps to Shift_L
partial modifier_keys
xkb_symbols "caps_lshift" {
    replace key  {
        type[group1] = "ONE_LEVEL",
        symbols[group1] = [ Shift_L ],
        actions[group1] = [ SetMods(modifiers=Shift) ]
    };
};
EOF
cat > /usr/share/X11/xkb/rules/evdev << EOF
! option = symbols
  custom:caps_lshift = +customsymbol(caps_lshift)

! include %S/evdev
EOF
cat << EOF
input "1:1:AT_Translated_Set_2_keyboard" {
    xkb_layout "gb"
    xkb_options "custom:caps_lshift"
}
EOF
