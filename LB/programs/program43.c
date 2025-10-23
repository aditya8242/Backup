// input: 12	2	Output: true
// input: 12	3	Output: true
// input: 12	5	Output: false
// input: 12	2	Output: true
// input: 12	7	Output: false

#include<stdio.h>

int main()
{
	int iValue1 = 0, iValue2 = 0;

	printf("Enter first number: ");
	scanf("%d", &iValue1);

	printf("Enter second number: ");
	scanf("%d", &iValue2);

	if(iValue1 % iValue2 == 0)
	{
		printf("It is completely divisible\n");
	}
	else
	{
		printf("It is not completely divisible\n");
	}

	return 0;
}