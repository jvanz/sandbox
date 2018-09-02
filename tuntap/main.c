#include <fcntl.h>
#include <linux/if_tun.h>
#include <net/if.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define TUN_DEV_NAME "tun0"

int open_tun(char* tun_device)
{
	struct ifreq ifr;
	int fd, err;

	if ((fd = open("/dev/net/tun", O_RDWR)) == -1) {
		perror("Could not open /dev/net/tun");
		exit(1);
	}
	memset(&ifr, 0, sizeof(ifr));
	ifr.ifr_flags = IFF_TUN;
	strncpy(ifr.ifr_name, tun_device, IFNAMSIZ);

	if ((err = ioctl(fd, TUNSETIFF, (void*) &ifr)) == -1) {
		perror("ioctl TUNSETIFF");
		close(fd);
		exit(1);
	}
	return fd;
}

int main(int argc, char** argv) {

	int tunfd = open_tun(TUN_DEV_NAME);
	printf("tun0 opened\n");

	char buffer[BUFFER_SIZE];

	while(1) {
		int nbytes = read(tunfd, buffer, sizeof(buffer));
		printf("Read %d from %s\n", nbytes, TUN_DEV_NAME);
	}
	
}
