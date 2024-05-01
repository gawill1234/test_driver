/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

int matchmode(char *copything, char *copyto)
{
struct stat buf;

   if (stat(copything, &buf) == 0) {
      chmod(copyto, buf.st_mode);
   } else {
      return(-1);
   }
   return(0);
}
