#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

// list all the files in the directory
// specify which files are directories (if any)
// show the total size of all the regular files the directory
void list(DIR *directory){
  struct dirent *currentFile;
  struct stat x;
  int fileNum = 0;
  long totalSize = 0;

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
  char * byteSize[] = {"B, KB, MB, GB"};
  while(totalSize >= 1024){
    totalSize /= 1024;
    i++;
  }
  // Print out the size in a more readable format (like using KB, MB, GB for -byte prefixes)
  printf("The size of all the regular files of this directory is %ld%s\n\n", tmp, byteSize[i]);
}

int main(){
  DIR *toad;
  toad = openddir("dirstuff");
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
// Make it look more like $ ls -l
