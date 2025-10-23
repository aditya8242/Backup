#include<stdio.h>

int main()
{
    int frame[10], page[20];
    int i = 0, j = 0, k = 0; // counters
    
    int pg = 0, nframe = 0; // storing pages and frames
    int pos = 0, pfault = 0, flag = 0, hit = 0;

    printf("How many frames? ");
    scanf("%d", &nframe);

    // initialise frames to -1
    for(i = 0; i < nframe; i++)
    {
        frame[i] = -1;
    }

    printf("How many pages? ");
    scanf("%d", &pg);

    printf("Enter pages: ");
    for(i = 0; i < pg; i++)
    {
        scanf("%d", &page[i]);
    }

    for(i = 0; i < pg; i++)
    {
        flag = 0;

        for(j = 0; j < nframe; j++)
        {
            // if frame present
            if(frame[j] == page[i])
            {
                printf("\n  Hit:\t");
                hit++;
                flag = 1;
                break;
            }
        }

        // insert if not present
            if(flag == 0)
            {
                frame[pos] = page[i];
                pos++;
                printf("\n  Fault:");
                pfault++;

                // if frame is full
                if(pos>=nframe)
                {
                    pos = 0;
                }
            }

            for(k = 0; k < nframe; k++)
            {
                printf("%d\t", frame[k]);
            }
    }

    printf("\nNumber of page faults is %d\n", pfault);
    printf("Number of page hits is %d\n", hit);

    return 0;
}