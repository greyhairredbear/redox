# greyhairredbear personal Keymap Layout for the Redox Keyboard

To make use of this file you will need follow the following steps:

* Download or Clone QMK Firmware: <https://github.com/qmk/qmk_firmware/>
* Extract QMK Firmware to a location on your hard drive
* Copy the content of this folder into `$QMK_HOME/keyboards/redox/keymaps/plaggner`. Generally, running `./deploy.sh` with `$QMK_HOME` set should also suffice. 
* You are now ready to compile or use your keymap with the source

To flash, run `make redox/rev1:plaggner:dfu` (amongst other options, like `qmk flash -kb redox/rev1 -km plaggner`)

More information can be found in the QMK docs: <https://docs.qmk.fm>
