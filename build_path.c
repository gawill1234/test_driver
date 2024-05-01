/***************************************************************************/
/*  
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

/********************************************************************/
/*   Build a complete path from a directory and a filename.
 */
char *buildPath(const char *filePath, char *fileName)
{
char *fullPath;

   if (filePath == NULL)
      return(NULL);

   if (fileName == NULL)
      return(NULL);

   /*
    *   "+ 2" is to contain the added "/" and "\0" in the new string.
    */
   fullPath = (char *)calloc(strlen(filePath) + strlen(fileName) + 2, 1);

   /*
    *   If the filePath is "/", just create the new full path as
    *      "/<fileName>"
    *   otherwise
    *      "/<filePath>/<fileName>"
    */
   if (strlen(filePath) == 1)
      sprintf(fullPath, "/%s", fileName);
   else
      sprintf(fullPath, "%s/%s", filePath, fileName);

   return(fullPath);
}
