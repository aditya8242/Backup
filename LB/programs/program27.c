#include<stdio.h>

void Display(int iFrequency)
{
	int iCnt = 0;

	// filter
	if(iFrequency < 0)
	{
		printf("Invalid input\n");
		return;
	}

	for(iCnt = 1; iCnt <= iFrequency; iCnt++)
	{
		printf("Jay Ganesh...\n");
	}
}

// dynamic function

int main()
{
	int iCount = 0;

	printf("Enter the frequency: ");
	scanf("%d", &iCount);

	Display(iCount);

	return 0;
}