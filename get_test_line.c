/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

char *getTestLine(FILE *localfp, int which, char *mystr)
{
int count = 0;

   fseek(localfp, 0, SEEK_SET);

   do {
      if (readline(localfp, mystr)) {
         if (strlen(mystr) > 1) {
            count++;
         }
      }
   } while (count < which);

   return(mystr);
}
