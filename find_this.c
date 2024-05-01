/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

int findThis(char *argstr, int cmstart, char c)
{
int jj;

   jj = strlen(&argstr[cmstart]) + cmstart;

   while ((argstr[cmstart] != c) && (argstr[cmstart] != '\0')) {
      cmstart++;
      if (cmstart > jj)
         break;
   }

   if (argstr[cmstart] != c) {
      cmstart = -1;
   }

   return(cmstart);
}
