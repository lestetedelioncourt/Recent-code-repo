#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

/* mmap() has multiple purposes, this is an example where a program does dynamic memory allocation 
using mmap() instead of malloc(). There is no external data source or memory mapping involved. This 
example simply shows how mmap()/munmap() can be used as substitution for malloc()/free() */

/* Function prototypes
void mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

int munmap(void *addr, size_t length);
*/

int main(int argc, char **argv) {
	int N=5;
	int *ptr = mmap(NULL, /* Let OS choose the starting virtual address of the 
	memory, just as there is no control to define the address malloc returns*/
					N*sizeof(int), //memory size in bytes to be allocated
					PROT_READ| //Memory is readable
					PROT_WRITE, //Memory is writable
					MAP_PRIVATE| //Memory not share with other processes, use MAP_SHARED instead
					MAP_ANONYMOUS, //mem not mapped to external data source, only RAM by default
					0, //FD (file descriptor) 0 since no external data source specified
					0); //offset value is zero, since no external data source specified
	//flags + macros concatenated with logical or operator

	if (ptr == MAP_FAILED) {
		printf("Mapping failed\n");
		exit(1);
	}

	for (int i = 0; i < N; i++) {
		ptr[i] = i * 10;
	}

	for (int i = 0; i < N; i++) {
		printf("[%d] ", ptr[i]);
	}

	printf("\n");
	
	int err = munmap(ptr, N*sizeof(int));

	if (err != 0) {
		printf("Unmapping failed\n");
		exit(1);
	}

	return 0;
}
