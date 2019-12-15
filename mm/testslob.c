//test program for slob modification
//to compile:
//          gcc -o testslob testslob.c
#include <stdio.h>
#include <linux/unistd.h>

#define GET_SLOB_AMT_FREE 544
#define GET_SLOB_AMT_CLAIMED 543

int main() {

    printf("Before massive memory allocation:\n");

	printf("Free: %d (bytes)\n", syscall(GET_SLOB_AMT_FREE));
	printf("Claimed: %d (bytes)\n", syscall(GET_SLOB_AMT_CLAIMED));


    printf("Allocating memory...\n");
    int* a = malloc(sizeof(int) * 100000);
    int* b = malloc(sizeof(int) * 100000);
    int* c = malloc(sizeof(int) * 100000);

    printf("After massive memory allocation:\n");
    printf("Free: %d (bytes)\n", syscall(GET_SLOB_AMT_FREE));
	printf("Claimed: %d (bytes)\n", syscall(GET_SLOB_AMT_CLAIMED));

    free(a);
    free(b);
    free(c);


	return 0;
}
