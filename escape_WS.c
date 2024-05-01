/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

int escapeWS(char *argstr, int loc)
{
int jj;

   jj = strlen(argstr);

   while ((isspace(argstr[loc])) && (loc < jj)) {
      loc++;
   }

   return(loc);
}
