#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct {
	int a;
	int b;
}pii;
int recursion(const char* s, int l, int r) {
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}
int recursion1(const char* s, int l, int r,int cnt) {
	if (l >= r) return cnt;
	else if (s[l] != s[r]) return cnt;
	else return recursion1(s, l + 1, r - 1,cnt + 1);
}
int isPalindrome(const char* s) {
	return recursion(s, 0, strlen(s) - 1);
}


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char buf[1001];
		scanf("%s", buf);
		printf("%d %d\n", isPalindrome(buf), recursion1(buf, 0, strlen(buf) - 1 , 1));

	}


	return 0;
}