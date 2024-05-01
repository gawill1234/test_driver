/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include <string.h>

int streq(char *one, char *two)
{

   if (one == NULL)
      return(0);

   if (two == NULL)
      return(0);

   if (strcmp(one, two) == 0) {
      return(1);
   } else {
      return(0);
   }

   return(0);
}
