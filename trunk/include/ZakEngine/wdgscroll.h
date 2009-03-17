#pragma once

#include "Widgets.h"

namespace zak {

class WdgScrollCursor : Widget {
public:
	void OnDrag() {
		SetRelPos(MouseRelPosf(ZAK_INPUT_MOUSE_POS_X)+GetPosX(),MouseRelPosf(ZAK_INPUT_MOUSE_POS_Y)+GetPosY()); 		
	}

	WdgScrollCursor() {}
	~WdgScrollCursor() {}

private:

};

class WdgSlider : Widget {
public:
	WdgSlider() {}
	~WdgSlider() {}
private:

};

class WdgScroll : Widget {
public:
	

	WdgScroll() {}
	~WdgScroll() {}
private:

};

}