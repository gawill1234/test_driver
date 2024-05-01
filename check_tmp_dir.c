/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

/*******************************************************************/
/*  Check the TMP dir.  If a test has destroyed it, recreate it.
 */
void checktmpdir(char *path, char *tdel)
{

   if (direxist(path) != 0) {
      if (tdel != NULL) {
         printf("GTD:  tmpdir (%s) possibly removed by %s\n", path, tdel);
         fflush(stdout);
      }
      if (mkdir(path, 0777) != 0) {
         printf("GTD:  Unable to mkdir() tmpdir (%s)\n", path);
         fflush(stdout);
      } else {
         if (chmod(path, 00777) != 0) {
            printf("GTD:  Unable to chmod() tmpdir (%s)\n", path);
            fflush(stdout);
         }
      }
   }

   return;
}
/*
 *   END OF TEST DATA ROUTINES
 */
/****************************************************************/
