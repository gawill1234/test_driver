/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

char *newTestListFile(char *oldfile)
{
char *filefullname;

   filefullname = NULL;

   do {
      if (filefullname != NULL) {
         free(filefullname);
      }
      filefullname = tempnam(thome, "DRVLS");
   } while (access(filefullname, F_OK) == 0);

   if (filefullname != NULL) {
      if (oldfile != NULL) {
         if (access(oldfile, F_OK) == 0) {
            unlink(oldfile);
         }
      }
   } else {
      filefullname = oldfile;
   }
   
   return(filefullname);
}
