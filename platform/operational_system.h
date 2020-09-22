#pragma once


#include <typeinfo>
#include <initializer_list>


typedef ::std::type_info std_type_info;


#ifndef AFX_INLINE
#define AFX_INLINE inline /*inline*/
#endif

// Include any non-Intel platform specific items
#ifndef _X86_
#include "version_cpu.h"
#endif


#ifdef _ApplicationFrameworkDLL
#include "version_dylib.h"
#endif



//#undef  __debug_break
//#define __debug_break() ({asm("int 3")})
/*#else
 #define __debug_break() DebugBreak()
 #endif
 #else
 #define __debug_break() _CrtDbgBreak()
 #endif
 #endif*/


/////////////////////////////////////////////////////////////////////////////
// Standard preprocessor symbols if not already defined
/////////////////////////////////////////////////////////////////////////////

// SIZE_T_MAX is used by the collection classes
#ifndef SIZE_T_MAX
#define SIZE_T_MAX  UINT_MAX
#endif

// PASCAL is used for static member functions
#ifndef PASCAL
#define PASCAL
#endif

// FASTCALL is used for static member functions with little or no params
#ifndef FASTCALL
#define FASTCALL
#endif

// CDECL and EXPORT are defined in case WINDOWS.H doesn't
#ifndef CDECL
#define CDECL
#endif

#ifndef EXPORT
#define EXPORT
#endif

// UNALIGNED is used for unaligned data access (in CArchive mostly)
#if !defined(UNALIGNED)
#if defined(_M_IA64) || defined(_M_AMD64)
#define UNALIGNED __unaligned
#else
#define UNALIGNED
#endif
#endif

// AFX_DEPRECATED is used for functions that should no longer be used
#ifndef AFX_DEPRECATED
#ifdef _AFX_DISABLE_DEPRECATED
#define AFX_DEPRECATED(_Message)
#else
#define AFX_DEPRECATED(_Message) __declspec(deprecated(_Message))
#endif
#endif

// _AFX_INSECURE_DEPRECATE is used for deprecated, insecure functions.
#ifndef _AFX_INSECURE_DEPRECATE
#ifdef _AFX_SECURE_NO_DEPRECATE
#define _AFX_INSECURE_DEPRECATE(_Message)
#else
#define _AFX_INSECURE_DEPRECATE(_Message) __declspec(deprecated(_Message))
#endif // _AFX_SECURE_NO_DEPRECATE
#endif // _AFX_INSECURE_DEPRECATE

// AFXAPI is used on global public functions
#ifndef AFXAPI
#define AFXAPI
#endif

// c_cdecl is used for rare functions taking variable arguments
#ifndef c_cdecl
#define c_cdecl
#endif

// AFX_EXPORT is used for functions which need to be exported
#ifndef AFX_EXPORT
#define AFX_EXPORT
#endif

#ifndef __STATIC
#define __STATIC extern
#define __STATIC_DATA extern __declspec(selectany)
#endif

// for data
#ifndef __DATA_EXPORT
#define __DATA_EXPORT
#endif
#ifndef __DATA_IMPORT
#define __DATA_IMPORT
#endif

// for classes
#ifndef AFX_CLASS_EXPORT
#define AFX_CLASS_EXPORT
#endif
#ifndef AFX_CLASS_IMPORT
#define AFX_CLASS_IMPORT
#endif

// for global APIs
#ifndef AFX_API_EXPORT
#define AFX_API_EXPORT
#endif
#ifndef AFX_API_IMPORT
#define AFX_API_IMPORT
#endif

// This macro is used to reduce size requirements of some classes
#ifndef AFX_ALWAYS_VTABLE
#ifndef AFX_NOVTABLE
#if _MSC_VER >= 1100 && !defined(_DEBUG)
#define AFX_NOVTABLE __declspec(novtable)
#else
#define AFX_NOVTABLE
#endif
#endif
#endif

// for global data that should be in COMDATs (packaged data)
#ifndef AFX_COMDAT
#define AFX_COMDAT __declspec(selectany)
#endif

// The following macros are used on data declarations/definitions
//  (they are redefined for extension DLLs and the shared MFC DLL)
#define __DATADEF
#define AFX_API CLASS_DECL_BOOT

// used when building the "core" MFC80.DLL
#ifndef __CORE_DATA
#define __CORE_DATA CLASS_DECL_BOOT
#define __CORE_DATADEF
#endif

// used when building extension DLLs
#ifndef AFX_EXT_DATA
#define AFX_EXT_DATA
#define AFX_EXT_DATADEF
#define AFX_EXT_CLASS
#define AFX_EXT_API
#endif

// BASED_XXXX macros are provided for backward compatibility
#ifndef BASED_CODE
#define BASED_CODE
#endif

#ifndef BASED_DEBUG
#define BASED_DEBUG
#endif

#ifndef BASED_STACK
#define BASED_STACK
#endif





#include "version_cpu.h"






#ifdef _AFX_DEVBUILD
#define AFX_IMPL_DATA __DATA_EXPORT
#else
#define AFX_IMPL_DATA CLASS_DECL_BOOT
#endif


#define _AFX_FULLTYPEINFO
#define VC_EXTRALEAN
#define NO_ANSIUNI_ONLY
#define _MFC_OVERRIDES_NEW

#include <stddef.h>
#include <limits.h>
#include <malloc/malloc.h>
#undef AfxWndProc

#include <sys/types.h>
#include <time.h>

#define __time_t time_t



//#define AFXAPI



#include <netinet/in.h>
