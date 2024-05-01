/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

int mkTestDir(int slotid)
{
   free(running_tests[slotid].directory);
   running_tests[slotid].directory = newdir(running_tests[slotid].directory_base);

   if (mkdir(running_tests[slotid].directory, 0777) != 0) {
      sleep(1);
      if (mkdir(running_tests[slotid].directory, 0777) != 0) {
         printf("GTD:  Could not create test directory:  %s\n",
                 running_tests[slotid].directory);
         fflush(stdout);
         return(-1);
      }
   }

   return(0);
}
