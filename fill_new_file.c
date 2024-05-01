/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

void fillNewFile(FILE *basefp, FILE *newfp)
{
int i, j;
char *mystr;

   i = j = 0;
   mystr = (char *)malloc(READLEN);

   while (mymess[i] != NULL) {
      for (j = 0; j < READLEN; j++) {
         mystr[j] = '\0';
      }
      mystr = getTestLine(basefp, mymess[i]->line, mystr);
      if (mystr != NULL) {
         fprintf(newfp, "%s", mystr);
      }
      i++;
   }

   free(mystr);
}
