/*
 * Original version written by Test_User <hax@andrewyu.org>
 * This version was modified by Runxi Yu <https://runxiyu.org>
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/mount.h>

int main(void)
{
	puts("rxinit");
	mount(0, "/", 0, MS_REMOUNT | MS_NOATIME | MS_NODEV,
	      "errors=remount-ro");
	mount("devtmpfs", "/dev", "devtmpfs", MS_NOSUID | MS_NOEXEC, 0);
	mount("sysfs", "/sys", "sysfs", MS_NOSUID | MS_NOEXEC | MS_NODEV, 0);
	mount("proc", "/proc", "proc", MS_NOSUID | MS_NOEXEC | MS_NODEV, 0);
	mount("devpts", "/dev/pts", "devpts", MS_NOSUID | MS_NOEXEC, 0);
	mount("tmpfs", "/tmp", "tmpfs", MS_NODEV, "size=4G");
	execl("/sbin/init", "init", (char *)0);
	return 0;
}
