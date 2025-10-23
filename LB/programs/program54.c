#include<stdio.h>
#include<stdbool.h>

bool CheckPrime(int iNo)
{
	int iCnt = 0, iFrequency = 0;

	if(iNo < 0)
	{
		iNo = -iNo;
	}

	for(iCnt = 2; iCnt <= (iNo/2); iCnt++)
	{
		if((iNo % iCnt) == 0)
		{
			iFrequency++;
		}
	}

	if(iFrequency == 0)	// no factors
	{
		return true;
	}
	else				// at least one factor
	{
		return false;
	}
}

int main()
{
	int iValue = 0;
	bool bRet = false;

	printf("Enter the number: ");
	scanf("%d", &iValue);

	bRet = CheckPrime(iValue);

	if(bRet == true)
	{
		printf("%d is a prime number\n", iValue);
	}
	else
	{
		printf("%d is not a prime number\n", iValue);
	}

	return 0;
}