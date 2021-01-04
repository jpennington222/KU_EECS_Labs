/*
  pipe-sync.c: Use Pipe for Process Synchronization
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Question: Update this program to synchronize execution of the parent and
// child processes using pipes, so that we are guaranteed the following
// sequence of print messages:
// Child line 1
// Parent line 1
// Child line 2
// Parent line 2


int main()
{
  char *s, buf[1024];
  int ret, stat;
  s  = "Use Pipe for Process Synchronization\n";

  /* create pipe */
  int pipe1[2];
  pipe(pipe1);
  int pipe2[2];
  pipe(pipe2);
  
  ret = fork();
  if (ret == 0) {

    /* child process. */
    
    printf("Child line 1\n");
    
    close(pipe1[0]);
    write(pipe1[1],buf,strlen(s));
    close(pipe2[1]);
    read(pipe2[0],buf,strlen(s));
    
    printf("Child line 2\n");
    
    close(pipe1[0]);
    write(pipe1[1],buf,strlen(s));
    
  } else {

    /* parent process */

    close(pipe1[1]);
    read(pipe1[0],buf,strlen(s));
        
    printf("Parent line 1\n");
    
    close(pipe2[0]);
    write(pipe2[1],buf,strlen(s));
    close(pipe1[1]);
    read(pipe1[0],buf,strlen(s));
    
    printf("Parent line 2\n");
    
  
    wait(&stat);
  }
}
