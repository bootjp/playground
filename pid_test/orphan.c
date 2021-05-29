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
    sleep(1);
    // 親プロセスは一秒待ったあとにすぐに死ぬ
    // 子プロセスは孤児となる
    exit;
  } else {
    while (1) {
      sleep(1);
    }
    // systemd 環境では systemd --user の子となる
  }
}


