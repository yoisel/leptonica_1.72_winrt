#pragma once

#include "windows.h"

int system(const char* command);

DWORD GetFileAttributes(LPCSTR lpFileName );

BOOL CreateDirectory(LPCSTR lpPathName, void * notUsed);

BOOL RemoveDirectory(LPCSTR lpPathName);

BOOL CopyFile(
	LPCSTR lpExistingFileName,
	LPCSTR lpNewFileName,
	BOOL    bFailIfExists
	);

DWORD GetTempPathA(
	DWORD  nBufferLength,
	LPSTR lpBuffer
	);

BOOL GetProcessTimes(
	HANDLE     hProcess,
	LPFILETIME lpCreationTime,
	LPFILETIME lpExitTime,
	LPFILETIME lpKernelTime,
	LPFILETIME lpUserTime
	);

#define getcwd _getcwd

#define getpid GetCurrentProcessId