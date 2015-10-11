#include "allheaders.h"

#include "winrtutils.h"


#ifdef LEPTONICA_WINRT

int system(const char* command)
{
	// This cannot be supported in WinRT at all...
	return 0;
}

DWORD GetFileAttributes(
	LPCSTR lpFileName
	)
{
	// TODO: Implement using StorageFile class
	return 0;
}

BOOL CreateDirectory(
	LPCSTR lpPathName,
	void * notUsed
	)
{
	// TODO: Implement using StorageFolder class
	return FALSE;
}

BOOL RemoveDirectory(
	LPCSTR lpPathName
	)
{
	// TODO: Implement using StorageFolder class
	return FALSE;
}

BOOL CopyFile(
	LPCSTR lpExistingFileName,
	LPCSTR lpNewFileName,
	BOOL    bFailIfExists
	)
{
	// TODO: Implement using StorageFolder or StorageFile class
	return FALSE;
}

DWORD GetTempPathA(
	DWORD  nBufferLength,
	LPSTR lpBuffer
	)
{
	//TODO: Implement using GetTempPathW and MultiByteToWideChar/WideCharToMultiByte functions
	return 0;
}

BOOL GetProcessTimes(
	HANDLE     hProcess,
	LPFILETIME lpCreationTime,
	LPFILETIME lpExitTime,
	LPFILETIME lpKernelTime,
	LPFILETIME lpUserTime
	)
{
	return FALSE;
}

#endif
