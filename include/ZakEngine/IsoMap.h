#ifndef _ISOMAP_H_
#define _ISOMAP_H_

#include "defines.h"
#include "renderer.h"
#include "Sprite.h"
#include "Entity2D.h"
#include "TextureManager.h"
#include "ZakUtil/ConfigFile.h"
#include "IsoSprite.h"

namespace zak {


class ZAKENGINE_API IsoTile : public IsoSprite { 
public:
	float GetIsoTileWidth() { return _tileWidth; }
	float GetIsoTileHeight() { return _tileHeight; }
	int GetFlags() { return _info; }
	void SetFlags(int info) { _info = info; }
	float GetWeight() { return _weight; }
	void SetWeight(float weight) { _weight = weight; }

	void Update(float dt);
	void Draw();

	IsoTile();
	~IsoTile();
private:
	bool InitLayers(int layers);
	void DrawLayer(int layer);
	void AddEntity(IsoSprite *entity, int layer);
	void RemoveEntity(IsoSprite *entity);
	void ClearEntityLists();

	void SortEntities(vector<IsoSprite*> &entities, int inf, int sup);

	float	_tileWidth;
	float	_tileHeight;
	int		_col;
	int		_row;
	int		_layerCount;
	int		_info;
	float	_weight;

	vector<IsoSprite*> *_layers;

	friend class IsoMap;
};

class ZAKENGINE_API IsoMap : public Entity2D {
public:
	bool Load(string &str);
	void Unload();
	
	void Draw();
	void Update(float dt);

	const IsoTile *GetIsoTileFromColRow(int col, int row);
	int GetTileNumFromColRow(int col, int row);
	void GetColRowFromPlaneWorldCoords(int &col, int &row, float x, float y) ;
	void GetPlaneWorldCoordsFromIsoWorldCoords(float &x, float &y, float ix, float iy, float iz);
	void GetColRowFromIsoWorldCoords(int &col, int &row, float x, float y, float z);
	void GetIsoWorldCoordsFromColRow(float &x, float &y, float &z, int col, int row);
	void GetIsoWorldCoordsFromPlaneWorldCoords(float &ix, float &iy, float &iz, float px, float py);

	bool AddEntity(IsoSprite *entity, int col, int row, int layer);
	bool RemoveEntity(IsoSprite *entity);
	bool ClearEntityLists();

	void SetLayersToDraw(int from, int to);


	IsoMap();
	~IsoMap();

private:


	bool AddEntity(IsoSprite &entity, int col, int row, int layer) { return AddEntity(&entity, col, row, layer); } 
	bool RemoveEntity(IsoSprite &entity) { return RemoveEntity(&entity); }


	IsoTile	*_isoTiles;
	int		_rows;
	int		_cols;
	float	_thOverTw;
	float	_atanThOverTw;
	float	_tileWidth;
	float	_tileHeight;
	float	_tileWidthIso;
	float	_tileRealWidth;
	float	_tileRealHeight;
	float	_cosPrecalc;
	float	_sinPrecalc;
	int		_layerCount;
	int		_fromLayer;
	int		_toLayer;

	int		_drawFromRow;
	int		_drawToRow;
	int		_drawFromCol;
	int		_drawToCol;

	vector<IsoSprite*> _entities;
};


}

#endif // _ISOMAP_H_