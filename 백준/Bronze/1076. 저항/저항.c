#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	char first[7], second[7], third[7];
	unsigned long long num = 0;

	scanf("%s", first);
	if (strcmp(first, "black") == 0) num += 0;
	else if (strcmp(first, "brown") == 0) num += 10;
	else if (strcmp(first, "red") == 0) num += 20;
	else if (strcmp(first, "orange") == 0) num += 30;
	else if (strcmp(first, "yellow") == 0) num += 40;
	else if (strcmp(first, "green") == 0) num += 50;
	else if (strcmp(first, "blue") == 0) num += 60;
	else if (strcmp(first, "violet") == 0) num += 70;
	else if (strcmp(first, "grey") == 0) num += 80;
	else if (strcmp(first, "white") == 0) num += 90;



	scanf("%s", second);
	if (strcmp(second,"black")==0) num += 0;
	else if (strcmp(second, "brown")==0) num += 1;
	else if (strcmp(second, "red")==0) num += 2;
	else if (strcmp(second, "orange")==0) num += 3;
	else if (strcmp(second, "yellow")==0) num += 4;
	else if (strcmp(second, "green")==0) num += 5;
	else if (strcmp(second, "blue")==0) num += 6;
	else if (strcmp(second, "violet")==0) num += 7;
	else if (strcmp(second, "grey")==0) num += 8;
	else if (strcmp(second, "white")==0) num += 9;


	scanf("%s", third);
	if (strcmp(third, "black")==0) num *= 1;
	else if (strcmp(third, "brown")==0) num *= 10;
	else if (strcmp(third, "red")==0) num *= 100;
	else if (strcmp(third, "orange")==0) num *= 1000;
	else if (strcmp(third, "yellow")==0) num *= 10000;
	else if (strcmp(third, "green")==0) num *= 100000;
	else if (strcmp(third, "blue")==0) num *= 1000000;
	else if (strcmp(third, "violet")==0) num *= 10000000;
	else if (strcmp(third, "grey")==0) num *= 100000000;
	else if (strcmp(third, "white")==0) num *= 1000000000;


	printf("%lld", num);

}