#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>

int ls_l(){

  struct dirent *d;
  DIR *dir;


  if((dir = opendir("."))==NULL)
    return 0;
//read all the directories and their files in the current directory
  while((d =readdir(dir))){
    printf("%s\n", d -> d_name);
  struct stat file ; 
  stat(d->d_name, &file);
 time_t t = file.st_ctime;



  printf(" File type of  %s\n",d->d_name);
  //checking if the file is a link
  if(S_ISLNK(file.st_mode))
     printf("%s is a symbolic link\n", d->d_name);
     else
 printf("%s is not a symbolic link\n", d->d_name);

  //checking if the file is a named pipe
  if(S_ISFIFO(file.st_mode))
     printf("%s is a named pipe\n", d->d_name);
     else
 printf("%s is not a named pipe\n", d->d_name);

 //checking if the file is a socket
  if(S_ISSOCK(file.st_mode))
     printf("%s is a socket\n", d->d_name);
     else
 printf("%s is not a socket\n", d->d_name);

  printf("\n");
  printf("File permission  of  %s\n",d->d_name);
  //cheking if the file is a directory
  if(S_ISDIR(file.st_mode))
    printf("d");
  else
    printf("-");
  //checking if the user has the read permission
 if(file.st_mode & S_IRUSR)
    printf("r");
  else
    printf("-");

//checking if the user has the write permission
 if(file.st_mode & S_IWUSR)
    printf("w");
  else
    printf("-");

//checking if the user has the execute permission
 if(file.st_mode & S_IXUSR)
    printf("x");
  else
    printf("-");

//checking if the group  has the read permission
 if(file.st_mode & S_IRGRP)
    printf("r");
  else
    printf("-");

//checking if the group  has the write permission
 if(file.st_mode & S_IWGRP)
    printf("w");
  else
    printf("-");

//checking if the group  has the execute permission
 if(file.st_mode & S_IXGRP)
    printf("x");
  else
    printf("-");

//checking if the other  has the read permission
 if(file.st_mode & S_IROTH)
    printf("r");
  else
    printf("-");

//checking if the other  has the write permission
 if(file.st_mode & S_IWOTH)
    printf("w");
  else
    printf("-");

//checking if the other  has the execute permission
 if(file.st_mode & S_IXOTH)
    printf("x\n\n");
  else
    printf("-\n");
printf("Time of last status changed is %s\n", ctime(&t));
  printf("\n\n");
}

}

int main(int argc, char **argv){
 
  ls_l();
 

}
