#include <stdio.h>
#include <string.h>

int main() {
	char binary[1000000];
	scanf("%s", binary);

	int len = strlen(binary);

	// 2진수를 3자리씩 그룹화하여 8진수로 변환
	int i = 0;
	if (len % 3 == 1) {
		printf("%c", binary[i]);
		i++;
	}
	else if (len % 3 == 2) {
		printf("%c", (binary[i] - '0') * 2 + (binary[i + 1] - '0') + '0');
		i += 2;
	}

	while (i < len) {
		printf("%c", (binary[i] - '0') * 4 + (binary[i + 1] - '0') * 2 + (binary[i + 2] - '0') + '0');
		i += 3;
	}

	return 0;
}