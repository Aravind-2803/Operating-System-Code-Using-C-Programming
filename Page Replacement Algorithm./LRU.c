#include <stdio.h>
int findLRU(int time[], int frames)
{
int i, min = time[0], pos = 0;
for (i = 1; i < frames; i++)
{
if (time[i] < min)
{
min = time[i];
pos = i;
}
}
return pos;
}
int main()
{
int n, frames, pages[50], frame[10], counter = 0,
time[10], i, j, avail, count = 0;
printf("Enter the number of pages: ");
scanf("%d", &n);
printf("Enter the page numbers: ");
for (i = 0; i < n; i++)
scanf("%d", &pages[i]);
printf("Enter the number of frames: ");
scanf("%d", &frames);
for (i = 0; i < frames; i++)
frame[i] = -1;
printf("\nLRU Page Replacement\n");
printf("Page\tFrames\n");
for (i = 0; i < n; i++)
{
avail = 0;
for (j = 0; j < frames; j++)
{
if (frame[j] == pages[i])
{
avail = 1;
counter++;
time[j] = counter;break;
}
}
if (avail == 0)
{
if (i < frames)
{
frame[i] = pages[i];
counter++;
time[i] = counter;
}
else
{
int pos = findLRU(time, frames);
frame[pos] = pages[i];
counter++;
time[pos] = counter;
}
count++;
}
printf("%d\t", pages[i]);
for (j = 0; j < frames; j++)
{
if (frame[j] != -1)
printf("%d ", frame[j]);
else
printf("- ");
}
printf("\n");
}
printf("\nTotal Page Faults: %d\n", count);
return 0;
}
