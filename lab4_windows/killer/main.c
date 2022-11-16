#include <windows.h>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


 void KillProcessByName(const char *filename) {
  HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
  PROCESSENTRY32 pEntry;
  pEntry.dwSize = sizeof (pEntry);
  BOOL hRes = Process32First(hSnapShot, &pEntry);
   while (hRes) {
     if (strcmp(pEntry.szExeFile, filename) == 0) {
       HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0, (DWORD) pEntry.th32ProcessID);
       if (hProcess != NULL) {
         TerminateProcess(hProcess, 9);
         CloseHandle(hProcess);
       }
     }
     hRes = Process32Next(hSnapShot, &pEntry);
   }
CloseHandle(hSnapShot);
}

void KillProcessByPid(unsigned int pid) {
  HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0, pid);
  if (hProcess != NULL) {
    TerminateProcess(hProcess, 9);
    CloseHandle(hProcess);
  }
}

void KillAllFromEnviramentVariable(void) {
  char* var = getenv("PROC_TO_KILL");
  int i = 0;
  char* str_to_kill = "";
  size_t size = strlen(var);
  while(i <= size) {
    if (var[i] == ',' || i == size) {
      KillProcessByName(str_to_kill);
      str_to_kill = "";
      ++i;
      continue;
    }
    char* to_append = malloc(2);
    to_append[0] = var[i];
    to_append[1] = '\0';
    char* buffer = (char *) malloc(1 + strlen(to_append)+ strlen(str_to_kill));
    strcpy(buffer, str_to_kill);
    strcat(buffer, to_append);
    str_to_kill = buffer;
    ++i;
  }
}

int main() {
   KillProcessByName("Telegram.exe");
   KillProcessByPid(8132);
  if (putenv ("PROC_TO_KILL=Telegram.exe,Calculator.exe") != 0) {
  perror("a");
  }
  KillAllFromEnviramentVariable();
  return 0;
}
