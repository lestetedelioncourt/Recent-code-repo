#include <stdio.h>

int main() {
	long long input1 = 0x0BAC;
	long long input2 = 0x2BDC;
	long long mask = 0xFCC1;
	long long template = 0x0880;

	if ((unsigned int)(input1 & mask) == (unsigned int)template)
		printf("match for input 1 0x%.4x\n", (unsigned int)(input1 & mask));
	else
		printf("no match for input 1 0x%.4x 0x%.4x\n", (unsigned int)(input1 & mask), (unsigned int)template);


	if ((unsigned int)(input2 & mask) == (unsigned int)template)
		printf("match for input 2 0x%.4x\n", (unsigned int)(input2 & mask));
	else
		printf("no match for input 2 0x%.4x\n", (unsigned int)(input2 & mask));

	return 0;
}
