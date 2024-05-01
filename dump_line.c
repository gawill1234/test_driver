/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

void dumpline(int slotid)
{
  

   if (failfp != NULL) {
      fprintf(failfp, "%s\n", running_tests[slotid].cmdline);
      fflush(failfp);
   }

   return;
}
