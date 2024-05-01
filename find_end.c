/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

int findend(char *argstr, int start)
{
int end, found;

   found = 0;
   end = start + 1;

   while (!found) {
      switch (argstr[end]) {
         case '\0':
         case '\n':
         case ' ':
         case ')':
         case '(':
         case ':':
         case '\t':
         case '/':
         case '$':
                    found = 1;
                    break;
         default:
                    end++;
                    break;
      }
   }

   return(end);
}
