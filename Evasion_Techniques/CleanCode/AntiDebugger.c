#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <string.h>
#include <winternl.h>

#pragma optimize("", off)

/*
 Anti-debugging techniques are methods used by software developers to prevent or hinder the analysis of their code by debuggers. 
 These techniques can be used to protect intellectual property, prevent reverse engineering, or enhance security. 
 Let's explore some common anti-debugging techniques and how they work.

 "Every obstacle yields to stern resolve" - Leonardo da Vinci
*/

int WindowsApiCheck() {
    printf("Checking for debugger With Windows API...\n");
    if (IsDebuggerPresent()) {
        printf("Debugger detected with IsDebuggerPresent!\n");
        return 1;
    } 
    BOOL debugger = FALSE;

    CheckRemoteDebuggerPresent(
        GetCurrentProcess(),
        &debugger
    );
    
     if (debugger) {
        printf("Debugger detected with CheckRemoteDebuggerPresent!\n");
        return 2;
    }

    SetLastError(0);

    OutputDebugStringA("Testing debugger");

    if (GetLastError() != 0) {
        printf("Debugger detected with OutputDebugStringA!\n");
        return 3;
    }else {
        printf("No debugger detected using Windows API calls.\n");
        return 0;
    }

}

int DebuggerProcessCheck() {
    const char *debuggers[] = {
        "x64dbg.exe",
        "x32dbg.exe",
        "ollydbg.exe",
        "windbg.exe",
        "ida.exe",
        "ida64.exe",
        "ghidra.exe",
        "immunitydebugger.exe"
    };

    int num = sizeof(debuggers) / sizeof(debuggers[0]);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (snapshot == INVALID_HANDLE_VALUE) {
        return 0;
    }

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(snapshot, &pe)) {
        do {
            for (int i = 0; i < num; i++) {
                if (_stricmp(pe.szExeFile, debuggers[i]) == 0) {
                    CloseHandle(snapshot);
                    printf("Debugger detected by process name: %s\n", debuggers[i]);
                    return 1;
                }
            }
        } while (Process32Next(snapshot, &pe));
    }

    CloseHandle(snapshot);
    printf("No debugger detected by process name.\n");
    return 0;
}
unsigned int checksum(unsigned char *data, size_t size) {

    unsigned int sum = 0;

    for (size_t i = 0; i < size; i++) {
        sum ^= data[i];
    }

    return sum;
}

BOOL NtQueryDebugCheck() {
    typedef LONG NTSTATUS;
    typedef NTSTATUS (NTAPI *NtQueryInformationProcessFn)(
        HANDLE,
        ULONG,
        PVOID,
        ULONG,
        PULONG
    );

    const ULONG ProcessDebugPortClass = 7;
    const ULONG ProcessDebugFlagsClass = 31;

    HMODULE hNtdll = GetModuleHandleW(L"ntdll.dll");
    if (!hNtdll) {
        printf("Unable to resolve ntdll.dll for NtQuery-debugging check.\n");
        return FALSE;
    }

    NtQueryInformationProcessFn NtQueryInformationProcess =
        (NtQueryInformationProcessFn)GetProcAddress(hNtdll, "NtQueryInformationProcess");
    if (!NtQueryInformationProcess) {
        printf("Unable to resolve NtQueryInformationProcess.\n");
        return FALSE;
    }

    ULONG debugPort = 0;
    NTSTATUS status = NtQueryInformationProcess(
        GetCurrentProcess(),
        ProcessDebugPortClass,
        &debugPort,
        sizeof(debugPort),
        NULL
    );

    if (status >= 0 && debugPort != 0) {
        printf("Debugger detected by process debug port.\n");
        return TRUE;
    }

    ULONG debugFlags = 0;
    status = NtQueryInformationProcess(
        GetCurrentProcess(),
        ProcessDebugFlagsClass,
        &debugFlags,
        sizeof(debugFlags),
        NULL
    );

    if (status >= 0 && debugFlags == 0) {
        printf("Debugger detected by process debug flags.\n");
        return TRUE;
    }

    printf("No debugger detected by NtQuery debug check.\n");
    return FALSE;
}

int SoftwareBreakpointCheck(void *func, size_t len) {

    unsigned char *p = (unsigned char *)func;

    for (size_t i = 0; i < len; i++) {
        if (p[i] == 0xCC) {
            return 1; 
        }
    }

    return 0;
}


int main() {
    unsigned char *func = (unsigned char *)WindowsApiCheck;
    unsigned int original_checksum = checksum(func, 1024); 
    
    if(WindowsApiCheck() != 0) {
        return 1;
    }

    if (DebuggerProcessCheck() != 0) {
        return 2;
    }

    unsigned int current_checksum = checksum(func, 1024); 

    if (original_checksum != current_checksum) {
        printf("Debugger detected by code integrity check (Checksum Mismatch)!\n");
        return 3;
    }else {
        printf("No debugger detected by code integrity check.\n");
    }

    
    if (NtQueryDebugCheck()) {
        return 4;
    }
    

    if (SoftwareBreakpointCheck(WindowsApiCheck, 1024)) {
        printf("Debugger detected by software breakpoint check!\n");
        return 5;
    } else {
        printf("No debugger detected by software breakpoint check.\n");
    }

    printf("Congratulations! We have successfully evaded all debugger detection techniques.\n");
    
    return 0;
}