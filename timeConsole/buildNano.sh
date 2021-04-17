arduino-cli compile -b arduino:avr:nano:cpu=atmega328old timeConsole
exit_code=$?
if [ $exit_code -eq 0 ]; then
    arduino-cli upload -b arduino:avr:nano:cpu=atmega328old timeConsole -p /dev/ttyUSB0
fi
