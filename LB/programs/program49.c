#include<stdio.h>

void NonFactors(int iNo)
{
	int iCnt = 0;
	if(iNo < 0)
	{
		iNo = -iNo;
	}
	for(iCnt = 1; iCnt < iNo; iCnt++)
	{
		if((iNo % iCnt) != 0)
		{
			printf("%d\n", iCnt);
		}
	}
}//	time complexity: O(N)

int main()
{
	int iValue = 0;

	printf("Enter number: ");
	scanf("%d", &iValue);

	NonFactors(iValue);

	return 0;
}