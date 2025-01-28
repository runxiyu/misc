// SPDX-License-Identifier: CC0-1.0

#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
		write(1, argv[i], strlen(argv[i]) + 1);
	return 0;
}
