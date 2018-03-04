#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>           
#include <sys/stat.h>

#include "umber_utils.h"

size_t get_file_size(const char* path){
   struct stat s;
   if(stat(path, &s) != 0){
      return 0;
   }

   return s.st_size;
}

