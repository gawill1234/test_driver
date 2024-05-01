/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

void envvarreplace(char *argstr)
{
int i, len;

   len = strlen(argstr);

   for (i = 0; i < len; i++) {
      if (argstr[i] == '$') {
         replaceit(argstr, i);
         len = strlen(argstr);
      }
   }

   return;
}
