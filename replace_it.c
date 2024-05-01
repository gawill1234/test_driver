/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

void replaceit(char *argstr, int start)
{
int end, envlen;
char *tmpstr, *envname, *envstr, *trac;

   tmpstr = (char *)calloc(READLEN, 1);
   sprintf(tmpstr, "%s", argstr);

   end = findend(tmpstr, start);

   envlen = end - (start + 1);

   trac = &tmpstr[end];

   envname = (char *)calloc(envlen + 1, 1);
   strncpy(envname, &tmpstr[start + 1], envlen);
   envstr = getenv(envname);

   if (envstr != NULL) {
      sprintf(&argstr[start], "%s", envstr);
      start = start + strlen(envstr);
      sprintf(&argstr[start], "%s", trac);
   } else {
      sprintf(argstr, "%s", tmpstr);
   }

   free(envname);
   free(tmpstr);

   return;
}
