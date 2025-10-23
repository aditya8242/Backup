#include<stdio.h>

int main()
{
	int frames[10], pages[20];
	int pg = 0, fr = 0;
	int i = 0, j = 0, k = 0;
	int flag = 0, fault = 0, hit = 0, pos = 0;

	printf("Enter number of pages: ");
	scanf("%d", &pg);

	printf("Enter number of frames: ");
	scanf("%d", &fr);

	printf("Enter pages: ");
	for(int i = 0; i < pg; i++)
	{
		scanf("%d", &pages[i]);
	}

	for(i = 0; i < fr; i++)
	{
		frames[i] = -1;
	}

	for(i = 0; i < pg; i++)
	{
		flag = 0;

		for(j = 0; j < fr; j++)
		{
			if(pages[i] == frames[j])
			{
				flag = 1;
				printf("\n\tHit:\t");
				hit++;
				break;
			}
		}

		if(flag == 0)
		{
			frames[pos] = pages[i];
			pos++;
			printf("\n\tFault:\t");
			fault++;

			if(pos>=fr)
			{
				pos = 0;
			}
		}

		for(k = 0; k < fr; k++)
		{
			printf("\t%d", frames[k]);
		}
	}

	printf("\nFaults: %d\nHits: %d\n", fault, hit);

	return 0;
}