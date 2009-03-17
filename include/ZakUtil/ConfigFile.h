#ifndef _ZAK_CONFIGFILE_H_
#define _ZAK_CONFIGFILE_H_

#include <vector>
#include "stringlist.h"
#include "stringutil.h"
#include "zakutilapi.h"

#define ZAK_MAX_LINE_CHARS			1024

#define ZAK_TOKEN_TYPE_INVALID		0
#define ZAK_TOKEN_TYPE_SECTION		1
#define ZAK_TOKEN_TYPE_STRING		2
#define ZAK_TOKEN_TYPE_INT			3
#define ZAK_TOKEN_TYPE_FLOAT		4
#define ZAK_TOKEN_TYPE_IDENT		5
#define ZAK_TOKEN_TYPE_EQUAL		6
#define ZAK_TOKEN_TYPE_SEMICOLON	7
#define ZAK_TOKEN_TYPE_HEX			8
#define	ZAK_TOKEN_TYPE_RSRVD_TRUE	9
#define	ZAK_TOKEN_TYPE_RSRVD_FALSE	10
#define ZAK_TOKEN_TYPE_ENDOFSTREAM	-1

#define ZAK_TOKEN_STATE_NONE		0
#define ZAK_TOKEN_STATE_STRING		1
#define ZAK_TOKEN_STATE_SECTION		2

namespace zak {

		class ZAKUTIL_API ConfigFile 
		{
		public:
			bool Load(const char *filename);

			int ReadInteger(const char *pszSection,
				const char *pszOption,
				int iDefaultValue);
			unsigned long ReadDWord(const char *pszSection,
				const char *pszOption,
				unsigned long iDefaultValue);
			long ReadLong (const char *pszSection,
				const char *pszOption,
				long lDefaultValue);
			bool ReadBoolean(const char *pszSection,
				const char *pszOption,
				bool bDefaultValue);
			float ReadFloat(const char *pszSection,
				const char *pszOption,
				float fDefaultValue);
			char *ReadString(const char *pszSection,
				const char *pszOption,
				const char *pszDefaultValue);
			
			void Stop();

			void SetCaseSensitive(bool caseSensitive){ _caseSensitive = caseSensitive; }
			bool GetCaseSensitive() { return _caseSensitive; }

			ConfigFile();
			~ConfigFile();
		protected:
		private:
			bool Search(char *section, char *option);
			bool SearchSection(char *section);
			int GetNextToken();
			bool SkipToNextLine();
			void ResetLexer();
			int GetCurrSourceLine();
			bool Preprocess();
			bool PreprocessSection(StringList &strList);
			bool ParseDefine();
			void Replace(char *rest);


			char			_retStr[ZAK_MAX_LINE_CHARS];
			FILE*			_file;
			StringList		_lines;
			StringList		_defines;
			StringList		_tempList;
			int				_linesCount;
			StringList		_directories;
			int				_token;
			char			_currLexeme[ZAK_MAX_LINE_CHARS];
			char			_currLineStr[ZAK_MAX_LINE_CHARS];
			int				_currLine;
			int				_startIdx;
			int				_endIdx;
			int				_tokenState;
			bool			_caseSensitive;
		};

}


#endif // _CONFIGFILE_H_