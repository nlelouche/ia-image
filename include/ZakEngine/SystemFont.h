#pragma once

#include "defines.h"
#include "dxtypes.h"
#include "renderer.h"
#include "entity2d.h"
#include <string>

using namespace std;

namespace zak {

class ZAKENGINE_API SystemFont : public Entity2D {
private:
	int				_size;
	ID3DXFont*		_pDefDXFont;
	ZAK_FONT_TYPES	_pDefDXFontType;
	RECT			r;
	D3DCOLOR		_color;
	unsigned int	_align;
	string			_text;


public:

	bool SetFont(int ft, int size=15);
	void SetText(string &text, int align) { _text = text; _align = align; };
	void SetColor(unsigned int color) { _color = color; }
	int GetFont(){ return (int)_pDefDXFontType; }
	int GetFontHeight() { return _size; }
	int GetTextSize(string &text, float x, float y, float w, float h, unsigned int align);
	int GetTextSize();
	void DrawString(string &text, float x, float y, float w, float h, unsigned int align=ZAK_TEXT_LEFT);
	void Draw();

	SystemFont();
	~SystemFont();
};

}