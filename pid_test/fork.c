#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
  pid_t child_pid;

  child_pid = fork();
  fprintf(stdout, "pid is %d \n", child_pid);
  if (0 != child_pid ) {
    int exit_status;
    if (waitpid(child_pid, &exit_status, WUNTRACED | WCONTINUED) == -1) {
      perror("waitpid error");
      exit(1);
    }
    while (1) {
      if (WIFEXITED(exit_status)) {
        fprintf(stdout, "child process exit success\n");
      }
      if (WIFSIGNALED(exit_status)) {
        fprintf(stdout, "child process exit by signal\n",
               WTERMSIG(exit_status));
      }

      sleep(1);
    }
  } else {
    // 子プロセスは即座に正常終了する
    exit;
  }
}


