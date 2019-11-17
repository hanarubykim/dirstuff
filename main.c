#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

// list all the files in the directory
// specify which files are directories (if any)
void list(DIR *directory){
  struct dirent *currentFile;
  struct stat x;
  int fileNum = 0;
  int totalSize = 0;

  while(currentFile = readdir(directory)){
    files++;
    printf("File %d: %s is ", fileNum, currentFile->d_name)

    if(currentFile->d_type == 4){
      printf("a directory.\n");
    }
    else{
      printf("not a directory.\n");
      stat(currentFile->d_name, &x);
      totalSize += x.st_size;
    }
  }
}

int main(){
  DIR *toad;
  toad = openddir(".");
  if(toad == NULL){
    printf("Unable to read directory.");
    closeddir(toad);
  }else{
    // list all the files in the directory
    // specify which files are directories (if any)
    // show the total size of all the regular files the directory
    list(toad);
  }


// Have the program scan the current directory


}
// Possible enhancements:
// Recursively list the files in any subdirectories, update the total to include the total size of subdirectories
// Print out the size in a more readable format (like using KB, MB, GB for -byte prefixes)
// Make it look more like $ ls -l
