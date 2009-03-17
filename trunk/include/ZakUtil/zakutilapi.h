#ifndef _ZAKUTILAPI_H_
#define _ZAKUTILAPI_H_

#include <windows.h>

#ifdef ZAKUTIL_EXPORTS
#define ZAKUTIL_API __declspec(dllexport)		// Especifica clase para exportacion
#else
#define ZAKUTIL_API __declspec(dllimport)		// Especifica clase para importacion
#endif // ZAKENGINE_EXPORTS

#pragma warning (disable : 4251)
#pragma warning (disable : 4996)

#endif // _ZAKUTILAPI_H_