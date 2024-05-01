/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

char *searchdir(char *testdir, char *testname)
{
struct stat buf;
DIR *dirp;
char fullpath[DIRLEN], *testpath;
struct dirent *dp;
int err = 0;

   testpath = NULL;

   dirp = opendir(testdir);

   if (dirp != NULL) {
      while (((dp = readdir(dirp)) != NULL) &&
             (testpath == NULL)) {
         if ((strcmp(dp->d_name, ".") != 0) &&
             (strcmp(dp->d_name, "..") != 0)) {
            sprintf(fullpath, "%s/%s", testdir, dp->d_name);
            stat(fullpath, &buf);
            if (S_ISDIR(buf.st_mode)) {
               testpath = searchdir(fullpath, testname);
            } else {
               if (streq(testname, dp->d_name)) {
                  testpath = (char *)calloc(strlen(testdir) + 1, 1);
                  strcpy(testpath, testdir);
               }
            }
         }
      }
      closedir(dirp);
   } else {
      printf("%s could not be opened\n", testdir);
      fflush(stdout);
      err = -1;
   }

   return(testpath);
}
