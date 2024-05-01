/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

/***************************************************************/
/*   Make sure a given directory name is unique.
 *   Update the name if it is not and check again.
 */
char *newdir(char *base)
{
char *tmpdir;
int i;

   tmpdir = (char *)calloc(DIRLEN, 1);
   sprintf(tmpdir, "%s", base);

   i = 0;

   if (direxist(tmpdir) == 0) {
      do {
         sprintf(tmpdir, "%s_%d", base, i);
         i++;
      } while (direxist(tmpdir) == 0);
   }

   return(tmpdir);

}

