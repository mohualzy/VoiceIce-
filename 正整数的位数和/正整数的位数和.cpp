#include<stdio.h>
int main() {
	int num;
	int sum=0;
	int digit;
	printf("������һ��������:");
	scanf_s("%d", &num);
	while (num > 0) {
		digit = num % 10;
		num = num / 10;
		sum = sum + digit;
	}
	printf("λ��֮����%d\n", sum);
	return 0;
}