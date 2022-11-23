#include <stdio.h>
#include "killer.h"

int main() {
    char *name_of_process_to_kill = malloc(12);
    name_of_process_to_kill[0] = '\0';
    strcat(name_of_process_to_kill, "mines");
    KillProcessByPid( 11266);
    if (putenv ("PROC_TO_KILL=firefox,telegram") != 0) {
    perror("putenv");
    return 1;
}
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        KillProcessByName(name_of_process_to_kill);
        KillAllFromEnviramentVariable();
        printf("%s", "Child: I am child. I killed all your enemies");
        fflush(stdout);
        clearenv();
        sleep(2);
    } else {
        clearenv();
        printf("%s", "Parent: I am waiting my child");
        fflush(stdout);
        int child_status = 0;
        if (waitpid(pid,&child_status, 0) == -1) {
            perror("wait");
            return 1;
        }
        if (WIFEXITED(child_status) && WEXITSTATUS(child_status) != 0) {
            return 1;
        }
        if (WIFSIGNALED(child_status)) {
            return 1;
        }
    }
    return 0;
}

