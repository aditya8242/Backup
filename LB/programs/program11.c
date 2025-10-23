/*
	Algorithm

	START
		Accept first number as no1
		Accept second number as no2
		If the input is negative then convert it into positive
		Perform Addition of no1 and no2
		Display the Addition on screen
	STOP

*/

///////////////////////////////////////////////////////////////
//
//	Required header files
//
///////////////////////////////////////////////////////////////

#include<stdio.h>

///////////////////////////////////////////////////////////////
//
//	Function Name:	AdditionTwoNumbers	
//	Description:	It is used to perform addition
//	Input:			Float, Float
//	Output:			Float
//	Author: 		Aditya Harishchandra Chavan
//	Date:			09/10/2025
//
///////////////////////////////////////////////////////////////

float AdditionTwoNumbers(
							float fNo1,			// First input
							float fNo2			// Second input
						)
{
	float fSum = 0;								// To store the result
	
												// Updater
	if(fNo1 < 0.0f)
	{
		fNo1 = -fNo1;
	}

												// Updater
	if(fNo2 < 0.0f)
	{
		fNo2 = -fNo2;
	}

	fSum = fNo1 + fNo2;							// business logic
	return fSum;
}	//End of AdditionTwoNumbers

///////////////////////////////////////////////////////////////
//
//	Entry point function for the application
//
///////////////////////////////////////////////////////////////

int main()
{
	float fValue1 = 0.0f, fValue2 = 0.0f;		// To accept user input
	float fRet = 0.0f;							// To store the result

	printf("Enter first number: ");
	scanf("%f", &fValue1);

	printf("Enter second number: ");
	scanf("%f", &fValue2);

	fRet = AdditionTwoNumbers(fValue1,fValue2);	// Method call

	printf("Addition is %f\n", fRet);

	return 0;
}	// End of main

///////////////////////////////////////////////////////////////
//
//	Testcases successfully handled by the application	
//
//	Input1: 10.5	Input2: 3.2		Output: 13.7
//	Input1: -10.5	Input2: 3.2		Output: 13.7
//	Input1: 10.5	Input2: -3.2	Output: 13.7
//	Input1: -10.5	Input2: -3.2	Output: 13.7
//	Input1: 10.5	Input2: 0		Output: 13.7
//
///////////////////////////////////////////////////////////////