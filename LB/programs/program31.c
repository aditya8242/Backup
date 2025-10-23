// *	*	*	*	*
#include<stdio.h>

void Display()
{
	// logic
	int iCnt = 0;

	for(iCnt = 1; iCnt <= 5; iCnt++)
	{
		printf("*\t", iCnt);
	}

	printf("\n");
}

int main()
{
	Display();

	return 0;
}