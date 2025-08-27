// gcc -o main main.c

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void initialize() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

void win() {
	system("/bin/sh");
}

int main() {
	initialize();

	char inp[80] = {0};
	char buf[1000] = {0};

	puts("Welcome to the Repeat Service!");
	puts("Please put your string and length.");

	while (1) {
		printf("Pattern: ");
		int len = read(STDIN_FILENO, inp, 80);
		if (len == 0)
			break;
		if (inp[len - 1] == '\n') {
			inp[len - 1] = 0;
			len--;
		}

		int target_len = 0;
		printf("Target length: ");
		scanf("%d", &target_len);

		if (target_len > 1000) {
			puts("Too long :(");
			break;
		}

		int count = 0;
		while (count < target_len) {
			memcpy(buf + count, inp, len);
			count += len;
		}

		// 덮어쓰기
		// 목표 : 1001 = 7*13*11
		// if (target_len == 7)
		// memcpy(buf,a*7,7)
		// memcpy(buf+7,a*7,,7)
		// memcpy(buf+14,a*7,,7)
		// ....
		// memcpy(buf+994,a*7,,7)
		// 

		// 목표 : 1046 = 8*131
		// if (target_len == 52)
		// memcpy(buf,a*52,52)
		// memcpy(buf+52,a*52,52)
		// memcpy(buf+104,aaaaaaa,52)
		// ....
		// memcpy(buf+988,a*52,52)
	
		// 목표 : 1032 = 8*43*3
		// if (target_len == 43)
		// memcpy(buf,a*43,7)
		// memcpy(buf+43,a*52,7)
		// memcpy(buf+86,aaaaaaa,7)
		// ....
		// memcpy(buf+989,a*43,7)


		// 목표 : 1012 = 8*43*3
		// if (target_len == 46)
		// memcpy(buf,a*46,7)
		// memcpy(buf+46,a*52,7)
		// memcpy(buf+92,aaaaaaa,7)
		// ....
		// memcpy(buf+966,a*43,7)


		printf("%s\n", buf);
	}
	return 0;
}