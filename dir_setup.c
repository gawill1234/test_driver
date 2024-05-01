/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

/********************************************************************/
/*   Set up the DRIVERS working directory and move into it.
 *   This becomes the DRIVER root.  All test directories
 *   will be under this one.
 */
void dirsetup()
{
char *locHome;

   locHome = (char *)calloc(DIRLEN, 1);

   if (optDir == NULL) {
      getcwd(locHome, DIRLEN - 1);
      sprintf(locHome, "%s/GTD_%d", locHome, getpid());
   } else {
      sprintf(locHome, "%s", optDir);
   }

   thome = newdir(locHome);
   free(locHome);

   if (create_nested_directories(thome, stdout, 1) == 0) {
      printf("GTD:  Could not create driver directory\n");
      fflush(stdout);
      exit(0);
   }

   if (chmod(thome, 00777) != 0) {
      printf("GTD:  Unable to chmod() directory (%s)\n", thome);
      fflush(stdout);
      exit(0);
   }

   if (chdir(thome) != 0) {
      printf("GTD:  Could not enter driver directory\n");
      fflush(stdout);
      exit(0); 
   }

   return;

}
