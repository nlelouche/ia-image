#ifndef _ZAK_STRINGUTIL_H_
#define _ZAK_STRINGUTIL_H_

#include <string.h>
#include <string>
using namespace std;
#include "zakutilapi.h"

#define ZAK_MZAK_DELIM_COUNT 10

namespace zak {
		class ZAKUTIL_API StringUtil {
		public:
			static bool IsCharNumeric(char chr);
			static bool IsCharWhiteSpace(char chr);
			static bool IsCharIdent(char chr);
			static bool IsCharDelimiter(char chr);
			static bool IsStringInt(char *str);
			static bool IsStringFloat(char *str);
			static bool IsStringWhiteSpace(char *str);
			static bool IsStringIdent(char *str);
			static void StripComments(char *str);
			static void TrimWhitespace(char *str);
			static bool IsCharHexValue(char str);
			static bool IsStringHex(char *str);
			static long  htoi(char *str);

			// Retorna el path de un archivo
			// NOTA: No incluye barra final
			// Ej: De "C:\tmp\pepe.txt" retorna "C:\tmp"
			static void GetFilePath(const char * pszFullFile, char * pszPath, int maxLen);
			static void GetFilePath(const string & fullFile, string & path);

			// Retorna sólo el nombre del archivo
			static void GetFileName(const char * pszFullFile, char * pszFile, int maxLen);
			static void GetFileName(const string & fullFile, string & file);

			// Extrae la terminación del archivo
			static void ExtractFileExt(char * pszFilename);
			static void ExtractFileExt(string & pszFilename);

			// Extrae la terminación del archivo
			static void ToLower(char * text);
			static void ToLower(string & text);

		private:
			static char _delims[ZAK_MZAK_DELIM_COUNT];
		};

}


#endif // _STRINGUTIL_H_

