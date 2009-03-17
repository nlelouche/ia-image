#ifndef _FileLog_H_
#define _FileLog_H_

#include <fstream>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "zakutilapi.h"
#include "console.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

using namespace std;

namespace zak {

/**
*	Clase que manipula y permite guardar texto en un archivo de log.
*	Ejemplo de uso:
*	\code
*	Log.Trace("Error n�mero: %d \n", errorNum);
*	\endcode
*
*	@author Juan Pablo "McKrackeN" Bettini
*/
class ZAKUTIL_API FileLog {
	private:
		char		*_szNombre;
		FILE		*_file;
		char		_szBuffer[256];

	public:

		char *GetLastMessage();

		/**
		*	M�todo que guarda un texto formateado (estilo printf) en un archivo de log
		*	@param pszText texto formateado al estilo printf
		*/
		void Trace(const char * pszTexto, ...);

		/**
		*	Constructor
		*/
		FileLog(char *szNombre);

		/**
		*	Destructor
		*/
		virtual ~FileLog();
};

extern ZAKUTIL_API FileLog Log;

}

#endif // _FileLog_H_
