#include<stdio.h>

int main()
{
    int frame[10], page[20], freq[10];
    int i = 0, j = 0, k = 0;
    
    int pg = 0, nframe = 0;
    int pfault = 0, hit = 0;

    printf("How many frames? ");
    scanf("%d", &nframe);

    // initialise frames and frequencies
    for(i = 0; i < nframe; i++)
    {
        frame[i] = -1;
        freq[i] = 0;
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
        int flag = 0;

        // check if page already in frame (hit)
        for(j = 0; j < nframe; j++)
        {
            if(frame[j] == page[i])
            {
                printf("\n  Hit:\t");
                hit++;
                freq[j]++; // increase frequency
                flag = 1;
                break;
            }
        }

        // page fault
        if(flag == 0)
        {
            int minFreqIndex = 0;
            int foundEmpty = 0;

            // check if there is empty frame
            for(j = 0; j < nframe; j++)
            {
                if(frame[j] == -1)
                {
                    minFreqIndex = j;
                    foundEmpty = 1;
                    break;
                }
            }

            // if no empty frame, find LFU
            if(!foundEmpty)
            {
                int minFreq = freq[0];
                minFreqIndex = 0;
                for(j = 1; j < nframe; j++)
                {
                    if(freq[j] < minFreq)
                    {
                        minFreq = freq[j];
                        minFreqIndex = j;
                    }
                }
            }

            // replace page
            frame[minFreqIndex] = page[i];
            freq[minFreqIndex] = 1; // reset frequency
            pfault++;

            printf("\n  Fault:");
        }

        // print frames
        for(k = 0; k < nframe; k++)
        {
            printf("%d\t", frame[k]);
        }
    }

    printf("\nNumber of page faults is %d\n", pfault);
    printf("Number of page hits is %d\n", hit);

    return 0;
}
