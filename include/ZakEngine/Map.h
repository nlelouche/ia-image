
#ifndef _Map_H_
#define _Map_H_

#include "renderer.h"
#include "Entity2D.h"
#include "TextureManager.h"
#include "AmeFormat.h"
#include <iostream>

#define MAP_TILE_WIDTH		64
#define MAP_TILE_HEIGHT		64

namespace zak {

class Tiles {
	public:
		float _fPosX, _fPosY, _fU, _fV, _fUW, _fUH;
};

/**
 *  Clase que permite cargar y mostrar mapas de mosaicos 
 *	en los formatos de los editores AnaConda Map Editor 
 *  y Mappy.
 *  Ejemplo de uso:
\code
bool TestGame::OnInit() {
	if (!_map.Load("./data/graphics/classic.bmp","./data/graphics/clasic.map",0xFF000000, false))
		return false;

	_map.SetPos(-400,300);
}

void TestGame::OnFrame() {
	_map.Update((float)_fpsMeter.GetDT());
}

void TestGame::OnDraw() {
	_map.Draw();
}
\endcode
 *
 *	@author Juan Pablo "McKrackeN" Bettini
 */
class ZAKENGINE_API Map : public Entity2D {
	private:
		TexVertex	*_Vertex;
		TexVertex	*_TempVert;
		Texture  	*_pTexture;
		float		_fUV[2];		// UV de la textura a usar
		float		_fW;			// Ancho del tile
		float		_fH;			// Alto del tile

		int			_iStartX,_iStartY;
		int			_iCountX,_iCountY;
		int			_iTempCountX,_iTempCountY;

		int			*_cMap;
		ameHeader	*_ame;
		Tiles		*_Tiles;

		int			_iActualTile;
		int			_iTileWidth;
		int			_iTileHeight;

		int			_iWidth;
		int			_iHeight;
		
		bool		_bEnableAlpha;

		bool LoadTexture(const char *pszTextureFilename, unsigned int uiColorKey, bool persist = false, DWORD filter=2, DWORD mipFilter=2); 
		bool LoadMap	(const char *pszMapFilename);
		bool LoadAnacondaMap(const char *pszMapFilename);




	public:
		void EnableAlphaBlend () {
			_bEnableAlpha = true;
		}
		void DisableAlphaBlend () {
			_bEnableAlpha = false;
		}
		int	 GetTileWidth() {
			return _iTileWidth;
		}
		int	 GetTileHeight() {
			return _iTileHeight;
		}
		int GetMapWidth() {
			return _iWidth;
		}
		int GetMapHeight() {
			return _iHeight;
		}
		void SetTile (int col, int row, int tileNum);
		int GetTileFromWorldCoords(float x, float y);
		int GetTileFromColRow(int col, int row);
		bool GetColRowFromWorldCoords(float x, float y, int &col, int &row);
		bool GetWorldCoordsFromColRow(int col, int row, float &x, float &y);
		bool GetColRowFromTile(int tile, int &col, int &row);
		bool GetWorldCoordsFromTile(int tile, float &x, float &y);
		int	 GetTileNumCount(int tile);
		ameBlockInfo *GetAmeTileInfoFromColRow(int col, int row);
		ameBlockInfo *GetAmeTileInfoFromWorldCoords(float x, float y);
		ameHeader *GetAmeMapDetails() { return _ame; } 
		bool Load		(const char *pszTextureFilename, const char *pszMapFilename, unsigned int uiColorKey, int tileWidth, int tileHeight, bool persist = false, DWORD filter=2, DWORD mipFilter=2);
		bool Load		(const char *pszTextureFilename, const char *pszMapFilename, unsigned int uiColorKey, bool persist = false, DWORD filter=2, DWORD mipFilter=2);
		bool LoadAMF	(const char *pszMapFilename, unsigned int uiColorKey, bool persist = false, DWORD filter=2, DWORD mipFilter=2);


		/**
		 *  Permite liberar la memoria RAM y de video de la textura cargada
		 *	@return retorna true si todo salió bien y false en caso contrario
		 */
		void Unload();

		/**
		 *  Muestra el mapa en pantalla
		 */
		void Draw		();

	/**
	 *  Constructor
	 */
	Map();

	/**
	 *  Destructor
	 */
	~Map();
};

}
#endif // _Map_H_