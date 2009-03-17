#ifndef _ISOSPRITE_H_
#define _ISOSPRITE_H_

#include "Sprite.h"

namespace zak {

class ZAKENGINE_API IsoSprite : public Sprite { 
private:
	float _isoPosX;
	float _isoPosY;
	float _isoPosZ;

	int _col;
	int _row;

	int	 _layer;

	friend class IsoTile;
	friend class IsoMap;

public:
	void SetIsoPos(float x, float y, float z) { _isoPosX = x; _isoPosY = y; _isoPosZ = z;}
	void SetIsoPosX(float x) { _isoPosX = x; }
	void SetIsoPosY(float y) { _isoPosY = y; }
	void SetIsoPosZ(float z) { _isoPosZ = z; }
	void GetIsoPos(float &x, float &y, float &z) { x = _isoPosX; y = _isoPosY; z = _isoPosZ; }
	float GetIsoPosX() { return _isoPosX; }
	float GetIsoPosY() { return _isoPosY; }
	float GetIsoPosZ() { return _isoPosZ; }
	void SetCol(int col) { _col = col; }
	void SetRow(int row) { _col = row; }
	int GetCol() { return _col; }
	int GetRow() { return _row; }
	int GetLayer() { return _layer; }

	IsoSprite() {_isoPosX = _isoPosY = _isoPosZ = 0; _col = 0; _row = 0; _layer = 0; }
	~IsoSprite() {}
};

}

#endif // _ISOSPRITE_H_