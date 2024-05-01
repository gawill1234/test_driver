/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

int doTestCount(FILE *localfp)
{
char *mystr;
int i;
int testCount = 0;
int done = 0;

   mystr = (char *)malloc(READLEN);

   do {
      for (i = 0; i < READLEN; i++)
         mystr[i] = '\0';
      if (readline(localfp, mystr)) {
         if (strlen(mystr) > 1) {
            testCount++;
         }
      } else {
         done = 1;
      }
   } while (!done);

   free(mystr);

   return(testCount);
}
