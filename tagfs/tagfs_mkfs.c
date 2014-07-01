#include "tagfs.h"

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int fd;
	ssize_t ret;
	struct tagfs_super_block sb;

	if (argc != 2) {
		printf("Usage: tagfs_mkfs <device>\n");
		return -1;
	}

	fd = open(argv[1], O_RDWR);
	if (fd == -1) {
		perror("Error opening the device");
		return -1;
	}

	sb.version = 1;
	sb.magic = TAGFS_MAGIC_NUMBER;
	sb.block_size = TAGFS_DEFAULT_BLOCK_SIZE;
	sb.free_blocks = ~0;

	ret = write(fd, (char *)&sb, sizeof(sb));

	/* Just a redundant check. Not required ideally. */
	if (ret != TAGFS_DEFAULT_BLOCK_SIZE)
		printf("bytes written [%d] are not equal to the default block size",	(int)ret);
	else
		printf("Super block written succesfully");

	close(fd);

	return 0;
}