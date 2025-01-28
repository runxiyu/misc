#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>

#define EVENT_DEVICE "/dev/input/by-path/platform-23510c000.spi-cs-0-event-kbd"
#define EVENT_TYPE_EV_KEY 0x01

const char *KEY_MAP[] = {
	"UNKNOWN", "ESC", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
	"BACKSPACE", "TAB", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]",
	"ENTER", "LEFT CTRL", "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", "`",
	"LEFT SHIFT", "\\", "Z", "X", "C", "V", "B", "N", "M", ",", ".", "/", "RIGHT SHIFT",
	"KEYPAD *", "LEFT ALT", "SPACE", "CAPS LOCK"
};

int main()
{
	int fd = open(EVENT_DEVICE, O_RDONLY);
	if (fd == -1) {
		perror("Error opening event device");
		return EXIT_FAILURE;
	}

	struct input_event event;

	while (1) {
		ssize_t bytes_read = read(fd, &event, sizeof(event));
		if (bytes_read == -1) {
			perror("Error reading event");
			close(fd);
			return EXIT_FAILURE;
		}
		if (event.type == EVENT_TYPE_EV_KEY) {
			const char *key_name = (event.code < sizeof(KEY_MAP) / sizeof(KEY_MAP[0])) ? KEY_MAP[event.code] : "UNKNOWN";
			const char *action = (event.value == 1) ? "PRESS" : (event.value == 0) ? "RELEASE" : "HOLD";
			printf("%ld.%06ld\t%d\t%s\t%s\n", event.time.tv_sec, event.time.tv_usec, event.code, key_name, action);
		}
	}

	close(fd);
	return EXIT_SUCCESS;
}
