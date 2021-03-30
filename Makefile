# ~/Library/Arduino15/packages/Croduino_Boards/hardware/Inkplate/1.0.1/boards.txt
SKETCH=.

all: compile upload

compile:
	arduino-cli compile -v \
	  --fqbn Croduino_Boards:Inkplate:Inkplate6 \
	  --build-property "build.extra_flags=\"-DMY_SSID=\"$$SSID\"\" \"-DMY_SSID_PASS=\"$$SSID_PASS\"\"" \
	  $(SKETCH)
upload:
	arduino-cli upload -v -p /dev/cu.usbserial-110 --fqbn Croduino_Boards:Inkplate:Inkplate6 $(SKETCH)
