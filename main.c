#include <stdlib.h>
#include <stdio.h>
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
    fileNum++;
    printf("File %d: %s is ", fileNum, currentFile->d_name);
    if(currentFile->d_type == 4){
      printf("a directory.\n");
    }
    else{
      printf("not a directory.\n");
      stat(currentFile->d_name, &x);
      totalSize += x.st_size;
    }
  }
  int i = 0;
  char * byteSize[] = {"B", "KB", "MB", "GB"};
  while(totalSize >= 1024){
    totalSize /= 1024;
    i++;
  }
  // Print out the size in a more readable format (like using KB, MB, GB for -byte prefixes)
  printf("The size of all the regular files of this directory is %ld%s\n\n", totalSize, byteSize[i]);
}

int main(){
  DIR *toad;
  toad = opendir("./");
  if(toad == NULL){
    printf("Unable to read directory.");
    closedir(toad);
  }else{
    // list all the files in the directory
    // specify which files are directories (if any)
    // show the total size of all the regular files the directory
    list(toad);
  }
  closedir(toad);
// Have the program scan the current directory
}
