#include <stdio.h>
int findOptimal(int pages[], int frame[], int frames, int index, int n)
{
int farthest = index, pos = -1;
for (int i = 0; i < frames; i++)
{
int j;
for (j = index; j < n; j++)
{
if (pages[j] == frame[i])
{
if (j > farthest)
{
farthest = j;
pos = i;
}
break;
}
}
if (j == n)
return i;
}
return (pos == -1) ? 0 : pos;
}
int main()
{
int n, frames, pages[50], frame[10], i, j, avail,
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
printf("\nOptimal Page Replacement\n");
printf("Page\tFrames\n");
for (i = 0; i < n; i++)
{
avail = 0;
for (j = 0; j < frames; j++)
{
if (frame[j] == pages[i])
{
avail = 1;
break;
}
}
if (avail == 0)
{
if (i < frames)
{
frame[i] = pages[i];
}
else
{
int pos = findOptimal(pages, frame,
frames, i, n);
frame[pos] = pages[i];
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
