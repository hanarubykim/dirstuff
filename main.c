#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

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

int main(int argc, char *argv[]){
  char dirname [1000];
  if (argc <= 1){
    printf("Enter directory to scan: ");
    fgets(dirname, 1000, stdin);
    dirname[strlen(dirname) - 1] = '\0';
  }else{
    strcpy(dirname, argv[1]);
  }

  DIR *toad;
  toad = opendir(dirname);
  if(toad == NULL){
    printf("Oopsies! You've made a mistake, dude: %d.\nDirectory is invalid.\n", strerror(errno));
    closedir(toad);
    return 0;
  }else{
    // list all the files in the directory
    // specify which files are directories (if any)
    // show the total size of all the regular files the directory
    list(toad);
  }
  closedir(toad);
  return 0;
}
