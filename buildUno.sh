if [ -z "$1" ]; then
	echo "usage $0 <sketch>"
else
    echo "building $1"
    arduino-cli compile -b arduino:avr:uno $1
    exit_code=$?
    if [ $exit_code -eq 0 ]; then
        arduino-cli upload -b arduino:avr:uno $1 -p /dev/ttyACM0
    fi
fi
