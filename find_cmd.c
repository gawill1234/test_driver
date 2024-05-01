/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

/********************************************************/
/*  This sets the proper environment for the driver to 
 *  run the tests.  Updates the PATH, creates the test 
 *  directory, changes to that directory, and resets the
 *  standard (in, out, err) files to be actual files.
 */

/**************************************************************************/
/*   Find the first occurence of "cmd".  This would be a test to this
 *   program.  Return the full path to the cmd.
 */
char *findcmd(char *cmd)
{
char *dirbuf, *testpath, *tcmd;
int dirlen;

   tcmd = cmd;
   if ((tcmd[0] == '.') && (tcmd[1] == '/')) {
      tcmd = &cmd[2];
   }
   dirbuf = NULL;
   dirlen = strlen(getenv("TEST_ROOT"));

   if (dirlen > 0) {
      dirbuf = calloc(dirlen + 1, 1);
      strcpy(dirbuf, getenv("TEST_ROOT"));
   } else {
      if (dirbuf == NULL) {
         dirbuf = getcwd(dirbuf, 0);
      }
   }

   testpath = searchdir(dirbuf, tcmd);
   free(dirbuf);

   return(testpath);
}
