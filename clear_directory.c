/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

/******************************************************************/
/*   Remove the contents of a directory.
 */
int clearDirectory(const char *directory_name)
{
DIR *dirp, *opendir();
struct dirent *dp, *readdir();
char *rmthing, *buildPath();

   if (directory_name == NULL)
      return(0);

   /*
    *   Open the directory if the directory_name exists as
    *   a directory.
    */
   if (direxist(directory_name) == 0) {
      dirp = opendir(directory_name);
   } else {
      return(0);
   }

   /*
    *   Recursively clear the passed in directory name.
    */
   if (dirp != NULL) {
      /*   Read a directory item  */
      while ((dp = readdir(dirp)) != NULL) {
         /*   If it is not the direectory itself  */
         if (strcmp(dp->d_name, ".") != 0) {
            /*   And it is not the parent direectory */
            if (strcmp(dp->d_name, "..") != 0) {
               /*  build the full path */
               rmthing = buildPath(directory_name, dp->d_name);
               if (rmthing != NULL) {
                  /*  Attempt to unlink the path as a file */
                  if (unlink(rmthing) < 0) {
                     /*  If the unlink fails, it is a directory  */
                     if (direxist(rmthing) == 0) {
                        /*  so clear the directory  */
                        clearDirectory(rmthing);
                        /*  Once the directory is empty, delete it */
                        if (rmdir(rmthing) != 0) {
                           printf("GTD:  Could not remove directory %s\n", rmthing);
                        }
                     } else {
                        printf("GTD:  Could not remove file %s\n", rmthing);
                     }
                  }
                  free(rmthing);
               }
            }
         }
      }
      closedir(dirp);
   }

   return(0);
}
