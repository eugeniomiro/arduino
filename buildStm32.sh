if [ -z "$1" ]; then
	echo "usage $0 <sketch>"
else
    echo "building $1"
    arduino-cli compile -b stm32duino:STM32F1:genericSTM32F103C $1
    exit_code=$?
    if [ $exit_code -eq 0 ]; then
        arduino-cli upload -b stm32duino:STM32F1:genericSTM32F103C $1 -p /dev/ttyUSB0
    fi
fi
