/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

void makeLineUseTrack(int count)
{
int i;

   mymess = (struct thing **)malloc(sizeof(struct thing *) * (count + 1));

   for (i = 0; i < count; i++) {
      mymess[i] = (struct thing *)malloc(sizeof(struct thing));
      mymess[i]->used = 0;
      mymess[i]->line = i;
   }

   mymess[count] = NULL;
}
