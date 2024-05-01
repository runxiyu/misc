umask 022
cat > /usr/share/X11/xkb/symbols/gbcaps << EOF
default partial alphanumeric_keys
xkb_symbols "basic" {
    include "gb"
    name[Group1] = "English (UK) Customized";
    key <CAPS> { [ Shift_L, Shift_L, Shift_L, Shift_L ] };
};
EOF
cat > /usr/share/X11/xkb/symbols/uscaps << EOF
default partial alphanumeric_keys
xkb_symbols "basic" {
    include "us"
    name[Group1] = "English (US) Customized";
    key <CAPS> { [ Shift_L, Shift_L, Shift_L, Shift_L ] };
};
EOF
cat << EOF
# Add something like the following to your .config/sway/config
input "identifier from swaymsg -t get_inputs" {
    # xkb_layout "gbcaps" # for UK
    xkb_layout "uscaps" # for US
}
EOF
