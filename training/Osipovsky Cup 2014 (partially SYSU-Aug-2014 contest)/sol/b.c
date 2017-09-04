#include <stdio.h>

int cmp_int (int *a, int *b)
{
return (*a - *b);
}

main()
{
int faces[6],i;

for (i=0;i<6;i++) scanf ("%d",faces+i);

qsort (faces,6,sizeof (int),cmp_int);

//fprintf (stderr,"%d %d %d %d %d %d\n",faces[0],faces[1],faces[2],faces[3],faces[4],faces[5]);

if (((faces[0]+faces[5])==(faces[1]+faces[4]))&&((faces[0]+faces[5])==(faces[2]+faces[3]))) printf ("Yes\n");
else printf ("No\n");

return (0);
}