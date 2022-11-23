#ifndef UNTITLED8_KILLER_H
#define UNTITLED8_KILLER_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void KillProcessByPid(pid_t pid) {
    kill(pid, SIGKILL);
}

void KillProcessByName(const char *process_name) {
    char buf[512];
    char *command = malloc(7 + strlen(process_name));
    command[0] = '\0';
    strcat(command, "pgrep ");
    strcat(command, process_name);
    FILE *cmd_pipe = popen(command, "r");
    fgets(buf, 512, cmd_pipe);
    pid_t pid = strtoul(buf, NULL, 10);
    pclose(cmd_pipe);
    KillProcessByPid(pid);
}

void KillAllFromEnviramentVariable(void) {
    char *var = getenv("PROC_TO_KILL");
    int i = 0;
    char *str_to_kill = "";
    size_t size = strlen(var);
    while (i <= size) {
        if (var[i] == ',' || i == size) {
            KillProcessByName(str_to_kill);
            str_to_kill = "";
            ++i;
            continue;
        }
        char *to_append = malloc(2);
        to_append[0] = var[i];
        to_append[1] = '\0';
        char *buffer = (char *) malloc(1 + strlen(to_append) + strlen(str_to_kill));
        strcpy(buffer, str_to_kill);
        strcat(buffer, to_append);
        str_to_kill = buffer;
        ++i;
    }
}

#endif //UNTITLED8_KILLER_H
