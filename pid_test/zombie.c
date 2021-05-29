#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
  pid_t pid;

  pid = fork();
  fprintf(stdout, "pid is %d \n", pid);
  if (0 != pid ) {
    // 親プロセスは子プロセスをwait せずにビジーループする
    while (1) {
      sleep(1);
    }
  } else {
    // 子プロセスはこの場合ゾンビプロセスとなる
    exit;
  }
  // ps aux | grep defunct で子プロセスがソンビとして確認できる
}


