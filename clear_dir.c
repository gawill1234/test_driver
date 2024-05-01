/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

/**************************************************************/
/*   Clear a tests execution directory.  Destroy the files and
 *   remove the directory.  It is generally only employed if
 *   the test passes.
 */
void cleardir(int slotid)
{
   if (GL_keepall == 0) {
      clearDirectory(running_tests[slotid].directory);

      if (rmdir(running_tests[slotid].directory) != 0) {
         printf("GTD:  Unable to remove directory %s\n", 
                         running_tests[slotid].directory);
         fflush(stdout);
      }
   }
   return;
}
