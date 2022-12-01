#include <iostream>
#include <csignal>
#include <sys/wait.h>
#include <fcntl.h>
#include <vector>

int main() {
    std::string processes[]{"../../processM/cmake-build-debug/processM",
                            "../../processA/cmake-build-debug/processA",
                            "../../processP/cmake-build-debug/processP",
                            "../../processS/cmake-build-debug/processS"
    };
    int pipefd[3][2];
    std::vector<pid_t> pids;
    if (pipe(pipefd[0]) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    if (pipe(pipefd[1]) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    if (pipe(pipefd[2]) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 4; ++i) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            for (int j = i + 1; j < 4; ++j) {
                    close(pipefd[j - 1][0]);
                    if (j < 3) {
                        close(pipefd[j][1]);
                    }
            }
            if (i < 3) {
                dup2(pipefd[i][1], 1);
            }
            if (i > 0) {
                dup2(pipefd[i - 1][0], 0);
            }
            execl(processes[i].c_str(), processes[i].c_str(), nullptr);
        } else {
            pids.push_back(pid);
            if (i > 0) {
                close(pipefd[i - 1][0]);
            }
            if (i < 3) {
                close(pipefd[i][1]);
            }
        }
    }
    for (pid_t i : pids) {
        waitpid(i, nullptr, 0);
    }
}
