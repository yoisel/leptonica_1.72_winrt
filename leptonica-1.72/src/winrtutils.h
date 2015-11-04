#pragma once

#include "windows.h"
#include "sdkddkver.h"
#include <assert.h>

#if defined(WINAPI_FAMILY) && (WINAPI_FAMILY==WINAPI_FAMILY_PC_APP || WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP)

#define TESSERACT_WINRT

// Leptonica
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

#if defined(_WINRT_WIN8) // Win 8.1 or Win 8
#define getcwd NULL
#else
#define getcwd _getcwd
#endif

#define getpid GetCurrentProcessId

/////////////////////////////////////////////////////////////
// Tesseract

/////////////////////////////////////////////////////////////
// Types and stub functions extracted from winsock.h

#include  "inaddr.h"
#include  "AtlConv.h" // needed for wide-string to ansi-string conversions
/*
* Basic system type definitions, taken from the BSD file sys/types.h.
*/
typedef unsigned char   u_char;
typedef unsigned short  u_short;
typedef unsigned int    u_int;
typedef unsigned long   u_long;

/*
* The new type to be used in all
* instances which refer to sockets.
*/

typedef UINT_PTR        SOCKET;

/*
* Select uses arrays of SOCKETs.  These macros manipulate such
* arrays.  FD_SETSIZE may be defined by the user before including
* this file, but the default here should be >= 64.
*
* CAVEAT IMPLEMENTOR and USER: THESE MACROS AND TYPES MUST BE
* INCLUDED IN WINSOCK.H EXACTLY AS SHOWN HERE.
*/
#ifndef FD_SETSIZE
#define FD_SETSIZE      64
#endif /* FD_SETSIZE */

typedef struct fd_set {
	u_int   fd_count;               /* how many are SET? */
	SOCKET  fd_array[FD_SETSIZE];   /* an array of SOCKETs */
} fd_set;

struct timeval {
	long    tv_sec;         /* seconds */
	long    tv_usec;        /* and microseconds */
};

/*
* Socket address, internet style.
*/
struct sockaddr_in {
	short   sin_family;
	u_short sin_port;
	struct  in_addr sin_addr;
	char    sin_zero[8];
};

struct sockaddr {
	u_short sa_family;              /* address family */
	char    sa_data[14];            /* up to 14 bytes of direct address */
};

#define WSADESCRIPTION_LEN      256
#define WSASYS_STATUS_LEN       128

typedef struct WSAData {
	WORD                    wVersion;
	WORD                    wHighVersion;
#ifdef _WIN64
	unsigned short          iMaxSockets;
	unsigned short          iMaxUdpDg;
	char FAR *              lpVendorInfo;
	char                    szDescription[WSADESCRIPTION_LEN + 1];
	char                    szSystemStatus[WSASYS_STATUS_LEN + 1];
#else
	char                    szDescription[WSADESCRIPTION_LEN + 1];
	char                    szSystemStatus[WSASYS_STATUS_LEN + 1];
	unsigned short          iMaxSockets;
	unsigned short          iMaxUdpDg;
	char FAR *              lpVendorInfo;
#endif
} WSADATA;

typedef WSADATA FAR *LPWSADATA;

struct  hostent {
	char    FAR * h_name;           /* official name of host */
	char    FAR * FAR * h_aliases;  /* alias list */
	short   h_addrtype;             /* host address type */
	short   h_length;               /* length of address */
	char    FAR * FAR * h_addr_list; /* list of addresses */
#define h_addr  h_addr_list[0]          /* address, for backward compat */
};

#define FD_SET(fd, set) do { \
    if (((fd_set FAR *)(set))->fd_count < FD_SETSIZE) \
        ((fd_set FAR *)(set))->fd_array[((fd_set FAR *)(set))->fd_count++]=(fd);\
} while(0)

#define FD_ZERO(set) (((fd_set FAR *)(set))->fd_count=0)

/*
* Address families.
*/
#define AF_UNSPEC       0               /* unspecified */
#define AF_UNIX         1               /* local to host (pipes, portals) */
#define AF_INET         2               /* internetwork: UDP, TCP, etc. */
#define AF_IMPLINK      3               /* arpanet imp addresses */
#define AF_PUP          4               /* pup protocols: e.g. BSP */
#define AF_CHAOS        5               /* mit CHAOS protocols */
#define AF_IPX          6               /* IPX and SPX */
#define AF_NS           6               /* XEROX NS protocols */
#define AF_ISO          7               /* ISO protocols */
#define AF_OSI          AF_ISO          /* OSI is ISO */
#define AF_ECMA         8               /* european computer manufacturers */
#define AF_DATAKIT      9               /* datakit protocols */
#define AF_CCITT        10              /* CCITT protocols, X.25 etc */
#define AF_SNA          11              /* IBM SNA */
#define AF_DECnet       12              /* DECnet */
#define AF_DLI          13              /* Direct data link interface */
#define AF_LAT          14              /* LAT */
#define AF_HYLINK       15              /* NSC Hyperchannel */
#define AF_APPLETALK    16              /* AppleTalk */
#define AF_NETBIOS      17              /* NetBios-style addresses */
#define AF_VOICEVIEW    18              /* VoiceView */
#define AF_FIREFOX      19              /* FireFox */
#define AF_UNKNOWN1     20              /* Somebody is using this! */
#define AF_BAN          21              /* Banyan */

#define SOCK_STREAM     1               /* stream socket */
#define SOCK_DGRAM      2               /* datagram socket */
#define SOCK_RAW        3               /* raw-protocol interface */
#define SOCK_RDM        4               /* reliably-delivered message */
#define SOCK_SEQPACKET  5               /* sequenced packet stream */

inline hostent * gethostbyname(const char * name)
{
	assert(false);
	// Not supported
	return 0;
}

inline u_short htons(u_short hostshort)
{ 
	assert(false);
	// Not supported
	return 0; 
}

inline SOCKET socket(
	int af,
	int type,
	int protocol)
{
	assert(false);
	// Not supported
	return 0; 
}

inline int connect(
	SOCKET s,
	const struct sockaddr *name,
	int namelen)
{
	assert(false);
	// Not supported
	return 0;
}


inline int WSAStartup(
	WORD wVersionRequired,
	LPWSADATA lpWSAData)
{
	assert(false);
	// Not supported
	*lpWSAData = { 0 };
	return 0;
}

inline int send(
	SOCKET s,
	const char * buf,
	int len,
	int flags)
{
	assert(false);
	// Not supported
	return 0;
}

inline int select(
	int nfds,
	fd_set *readfds,
	fd_set *writefds,
	fd_set *exceptfds,
	const struct timeval *timeout)
{
	assert(false);
	// Not supported
	return 0;
}

inline int recv(
	SOCKET s,
	char * buf,
	int len,
	int flags)
{
	assert(false);
	// Not supported
	return 0;
}

inline int closesocket(SOCKET s)
{
	assert(false);
	// Not supported
	return 0;
}

// End of types extracted from winsock.h
/////////////////////////////////////////////////////////////


// Other stub functions

inline char * getenv(char * notused)
{
	assert(false);
	// It is not possible to access environment variables from WinRT/WinPhone Apps
	return 0;
}

#ifdef WIN32_FIND_DATA
#undefine WIN32_FIND_DATA
typedef WIN32_FIND_DATAA WIN32_FIND_DATA;
typedef PWIN32_FIND_DATAA PWIN32_FIND_DATA;
typedef LPWIN32_FIND_DATAA LPWIN32_FIND_DATA;
#endif

// The function definitions below does not really match any function from the WIN32 API,
// since some parameters are defined as ANSI-string and others as wide-string,
// in Win32 it would be very rare to find such scenario
inline HANDLE FindFirstFile(LPCSTR lpFileName, LPWIN32_FIND_DATAW lpFindFileData)
{
	assert(false);
	// TODO: It might be possible to provide a partial implementation of this method
	// by using the class StorageFolder
	return 0;
}

inline void _splitpath(LPCWSTR path, LPSTR notused1, LPSTR notused2, LPSTR name, LPSTR notused3)
{
	USES_CONVERSION;
	_splitpath(W2A(path), NULL, NULL, name, NULL);
}

#ifdef _WINRT_WIN8

#include "synchapi.h"

inline HANDLE WINAPI CreateMutex(
	LPSECURITY_ATTRIBUTES lpMutexAttributes,
	BOOL                  bInitialOwner,
	LPCTSTR               lpName
	)
{
	return CreateMutexEx(lpMutexAttributes, lpName, bInitialOwner ? CREATE_MUTEX_INITIAL_OWNER : 0, STANDARD_RIGHTS_ALL);
}

inline DWORD WINAPI WaitForSingleObject(
	HANDLE hHandle,
	DWORD  dwMilliseconds
	)
{
	return WaitForSingleObjectEx(hHandle, dwMilliseconds, FALSE);
}

inline HANDLE WINAPI CreateSemaphore(
	LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
	LONG                  lInitialCount,
	LONG                  lMaximumCount,
	LPCTSTR               lpName
	)
{
	return CreateSemaphoreEx( lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName, 0, STANDARD_RIGHTS_ALL );
}


#endif

#endif