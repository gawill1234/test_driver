/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

/******************************************************************/
/*   Read a line of data from the specified file.
 */
int readline(FILE *fp, char *mystr)
{
int readres;

   readres = 1;
   if (fgets(mystr, READLEN, fp) == NULL) {
      readres = 0;
   }

   return(readres);
}
