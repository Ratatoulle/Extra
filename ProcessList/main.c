#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tlhelp32.h>

void PrintProcessList(HANDLE const hStdOut)
{
    PROCESSENTRY32 peProcessEntry;
    DWORD dwTemp;
    HANDLE const hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); // get handle of a snapshot of a system process
    if (INVALID_HANDLE_VALUE == hSnapshot)
    {
        printf("ERROR");
        return 0;
    }
    peProcessEntry.dwSize = sizeof(PROCESSENTRY32);
    Process32First(hSnapshot, &peProcessEntry); // get first process
    while (Process32Next(hSnapshot, &peProcessEntry))
    {
        wprintf(L" %d %s\n", peProcessEntry.th32ProcessID, peProcessEntry.szExeFile); //print identifier and the name
    }
    CloseHandle(hSnapshot);
}

int main()
{
    HANDLE const hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    PrintProcessList(hStdOut);
    ExitProcess(0);
}