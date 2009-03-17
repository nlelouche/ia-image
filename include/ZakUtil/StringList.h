#ifndef _STRINGLIST_H_
#define _STRINGLIST_H_

#include "list.h"

namespace zak {
		class StringList
		{
		public:
			int AddFirst(char *str);
			int AddCurrent(char *str);

			int AddElement(char *str);
			
			char *GetElementByIndex(int idx);

			void Reset() ;

			char *GetCurrentElement();

			char* GetPrev();
			
			char *GetNext();

			int GetCurrentIndex() { return _idx; }
			int GetCount() { return _list.GetCount(); }

			void Clear();

		protected:
		private:
			List<char*> _list;
			int _idx;
		};
}

#endif // _STRINGLIST_H_