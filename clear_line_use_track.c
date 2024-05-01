#include "defs.h"

void clearLineUseTrack(int count)
{
int i;

   for (i = 0; i < count; i++) {
      free(mymess[i]);
   }

   free(mymess);
}
