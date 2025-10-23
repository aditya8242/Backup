// 5	4	3	2	1	0
#include<stdio.h>

void Display(int iNo)
{
	// logic
	int iCnt = 0;

	/*
	for(iCnt = 1; iCnt <= iNo; iCnt++)
	{
		if(iCnt % 2 == 0)
			printf("%d\t", iCnt);
	}*/

	for(iCnt = 2; iCnt <= iNo; iCnt += 2)
	{
		printf("%d\t", iCnt);
	}

	printf("\n");
} // time complexity: O(N/2)

int main()
{
	int iValue = 0;

	printf("Please enter frequency: ");
	scanf("%d", &iValue);
	
	Display(iValue);

	return 0;
}