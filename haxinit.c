#include <stdio.h>									       
#include <unistd.h>									      
#include <sys/mount.h>									   
int main(void) {										 
	puts("Yay fake init!\n");								
	mount(0, "/", 0, MS_REMOUNT | MS_NOATIME | MS_NODEV, "errors=remount-ro");	       
	mount("devtmpfs", "/dev", "devtmpfs", MS_NOSUID | MS_NOEXEC, 0);			 
	mount("sysfs", "/sys", "sysfs", MS_NOSUID | MS_NOEXEC | MS_NODEV, 0);		    
	mount("proc", "/proc", "proc", MS_NOSUID | MS_NOEXEC | MS_NODEV, 0);		     
	mount("devpts", "/dev/pts", "devpts", MS_NOSUID | MS_NOEXEC, 0);			 
	mount("tmpfs", "/tmp", "tmpfs", MS_NODEV, "size=4G");				    
	mount("tmpfs", "/home/me/.cache", "tmpfs", MS_NODEV | MS_NOSUID | MS_NOEXEC, "size=2G"); 
	execl("/sbin/init", "init", (char *)0);						  
	return 0;										
}												
