#include <stdio.h>
int main()
{
  int n, frames, pages[50], frame[10], i, j, k, avail,
  count = 0;
  printf("Enter the number of pages: ");
  scanf("%d", &n);
  printf("Enter the page numbers: ");
  for (i = 0; i < n; i++)
    scanf("%d", &pages[i]);
  printf("Enter the number of frames: ");
  scanf("%d", &frames);
  for (i = 0; i < frames; i++)
    frame[i] = -1;
  j = 0;
  printf("\nFIFO Page Replacement\n");
  printf("Page\tFrames\n");
  for (i = 0; i < n; i++)
  {
    avail = 0;
    for (k = 0; k < frames; k++)
    {
        if (frame[k] == pages[i])
        {
            avail = 1;
        }
        if (avail == 0)
        {
            frame[j] = pages[i];
            j = (j + 1) % frames;
            count++;
        }  
        printf("%d\t", pages[i]);
        for (k = 0; k < frames; k++)
        {
            if (frame[k] != -1)
              printf("%d ", frame[k]);
            else
              printf("- ");
         }
          printf("\n");
    }  
    printf("\nTotal Page Faults: %d\n", count);
    return 0;
}
