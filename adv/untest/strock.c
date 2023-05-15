#include <string.h>

#include <stdio.h>

int main () {

   char string[] = "my new project,my strtok project";

   const char del[] = ",";

   char *mytoken;

   mytoken = strtok(string, del);

   while( mytoken != NULL ) {

      printf( " %s\n", mytoken );

      mytoken = strtok(NULL, del);

   }

   return(0);

}
