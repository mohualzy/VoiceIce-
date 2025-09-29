#include<stdio.h>
int main() {
	int num;
	int sum=0;
	int digit;
	printf("请输入一个正整数:");
	scanf_s("%d", &num);
	while (num > 0) {
		digit = num % 10;
		num = num / 10;
		sum = sum + digit;
	}
	printf("位数之和是%d\n", sum);
	return 0;
}