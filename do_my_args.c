/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

/**************************************************************/
/*   Break a commandline into its individual arguments and
 *   set them up appropriately for use by execvp.
 */
char **domyargs(char *argstr)
{
char **myargs;
int i, j, jj, cmstart, argcnt;
char *tmpstr;

   cmstart = testLims(argstr);

   jj = strlen(&argstr[cmstart]);

   argcnt = 1;
   for (j = cmstart; j < (jj + cmstart); j++) {
      if (argstr[j] == ' ') {
         argcnt++;
      }
   }

   myargs = (char **)malloc(sizeof(char **) * (argcnt + 1));

   i = 0;
   myargs[i] = &argstr[cmstart];
   i = 1;


   for (j = cmstart; j < (jj + cmstart); j++) {
      if (argstr[j] == ' ') {
         tmpstr = &argstr[j];
         *tmpstr = '\0';
         tmpstr++;
         myargs[i] = tmpstr;
         i++;
      }
   }
   myargs[i] = NULL;

   /*************************************************/
   /*   Since we could have been reading the argument
    *   from a file, the last character could be a newline.
    *   This gets rid of it.
    */
   i = 0;
   while (myargs[i] != NULL) {
      jj = strlen(myargs[i]);
      for (j = 0; j < jj; j++) {
         if (myargs[i][j] == '\n') {
            myargs[i][j] = '\0';
         }
         if (myargs[i][j] == '\r') {
            myargs[i][j] = '\0';
         }
      }
      i++;
   }

#ifdef DEBUG
   i = 0;
   while (myargs[i] != NULL) {
      printf("Argurment %d:   %s\n", i, myargs[i]);
      i++;
   }
#endif


   return(myargs);

}
