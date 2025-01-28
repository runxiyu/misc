// SPDX-License-Identifier: CC0-1.0

#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc != 2)
		return EINVAL;
	struct dirent *d;
	DIR *dir = opendir(argv[1]);
	if (dir == NULL)
		return ENOENT;
	while (d = readdir(dir)) {
		if (d->d_name[0] == '.') continue;
		write(1, d->d_name, strlen(d->d_name) + 1);
	}
	closedir(dir);
	return 0;
}
