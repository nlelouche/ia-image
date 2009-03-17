#ifndef _Entity2D_H_
#define _Entity2D_H_

#include "Entity.h"
#include "Defines.h"
#include "renderer.h"
#include "ameformat.h"
#include "ZakUtil/MathUtil.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace zak {

class Animation;

/**
 *  Clase que contiene las propiedades comunes a todas las entidades 2D.
 *	@author Juan Pablo "McKrackeN" Bettini
 */
class ZAKENGINE_API Entity2D : public ENTITY
{
	public:
		enum CollisionType {
			eCollisionBBox=1,
			eCollisionCircle=2
		};


	protected:
		CollisionType _collisionType;
		float _collisionRadius;


		float _fWidth;
		float _fHeight;
		float _fPosX;
		float _fPosY;
		float _fPreviousPosX;
		float _fPreviousPosY;
		float _fAngleZ;
		float _scale;
		float _scaleX;
		float _scaleY;
		float _pivotPosX;
		float _pivotPosY;

		int   _iCollisionGroup;
		float _fCollisionRelPosX;
		float _fCollisionRelPosY;
		float _fCollisionPosX;
		float _fCollisionPosY;
		float _fCollisionSizeX;
		float _fCollisionSizeY;

		bool  _bMoving;
		bool  _rotating;
		bool  _bCheckCollision;
		float _fMovingSpeed;
		float _fMovingDegrees;
		float _rotationSpeed;

		int	_flipH;
		int	_flipV;
		int	_lastFlipHState;
		int	_lastFlipVState;

		float	_cosDegree;
		float	_sinDegree;

		bool		_bCollisionVisible;
		ColorVertex _VertexColor[17];
		DWORD		_collisionColor;

		friend class Renderer;

	public:
		virtual void SetWindDirection(float windDirection) {}
		virtual void SetWind(float wind)  {}
		virtual void SetStartDim(float sizeX, float sizeY) {}
		virtual void SetEndDim(float sizeX, float sizeY) {}
		virtual void SetStartColor(DWORD dwColor) {}
		virtual void SetEndColor(DWORD dwColor) {}
		virtual void SetLifeTime (float fLifeTime) {}
		virtual void SetRotationSpeedNoise(float rotSpeedNoise) {}
		virtual void SetParticlesSpeed (float fParticlesSpeed)  {}
		virtual void SetParticlesAngle (float fParticlesAngle) {}
		virtual void SetLifeNoise (float fLifeNoise) {}
		virtual void SetSpeedNoise (float fSpeedNoise) {}
		virtual void SetAngleNoise (float fAngleNoise)  {}
		virtual void SetAllDead() {}
		virtual bool IsEnableSystem() { return false; }
		virtual void SetEnableSystem() {}
		virtual void SetDisableSystem() {}
		virtual void SetBlend(int blend) {}
		virtual void EnableEffect() {}
		virtual void DisableEffect()  {}
		virtual void EnableAlphaBlend (){}
		virtual void DisableAlphaBlend (){}
		virtual int	 GetTileWidth() { return 0; }
		virtual int	 GetTileHeight(){ return 0; }
		virtual int GetMapWidth(){ return 0; }
		virtual int GetMapHeight(){ return 0; }
		virtual void SetTile (int col, int row, int tileNum){}
		virtual int GetTileFromWorldCoords(float x, float y){ return 0; }
		virtual int GetTileFromColRow(int col, int row){ return 0; }
		virtual bool GetColRowFromWorldCoords(float x, float y, int &col, int &row){ return false; }
		virtual bool GetWorldCoordsFromColRow(int col, int row, float &x, float &y){return false;}
		virtual bool GetColRowFromTile(int tile, int &col, int &row){return false;}
		virtual bool GetWorldCoordsFromTile(int tile, float &x, float &y){return false;}
		virtual int	 GetTileNumCount(int tile){return 0;}
		virtual ameBlockInfo *GetAmeTileInfoFromColRow(int col, int row){ return NULL;}
		virtual ameBlockInfo *GetAmeTileInfoFromWorldCoords(float x, float y){ return NULL; }
		virtual ameHeader *GetAmeMapDetails() { return NULL;}

		virtual void Unload() {}
		virtual void SetColor(DWORD color) {}
		virtual void SetText(const char* text,...) {}
		virtual void ShowSet(int set) {}
		virtual void SetAnimation(Animation *anim) {}
		virtual bool IsAnimationRunning() { return false; }
		virtual Animation *GetAnimation() { return NULL; }


		/**
		 *  Fija el color del área de colisión
		 *	@param color Color del área de colisión
		 */
		void SetCollisionColor(DWORD color) { _collisionColor = color; }

		/**
		 *  Fija el radio del área de la colisión por círculos
		 *	@param radius Radio de la colisión por círculos
		 */
		void SetCollisionRadius(float radius) {
			_collisionRadius = radius;
		}

		/**
		 *  Devuelve el radio del área de la colisión por círculos
		 *	@return Devuelve el radio
		 */
		float GetCollisionRadius() {
			return _collisionRadius;
		}

		/**
		 *  Fija el grupo de colisión al cual pertenece
		 *	@param iColGroup Grupo al de colisión al cual pertence
		 */
		void SetCollisionGroup(int iColGroup){
			_iCollisionGroup=iColGroup;
		}
		
		/**
		 *  Devuelve el grupo de colisión al cual pertenece
		 *	@return Devuelve el grupo al de colisión al cual pertence
		 */
		int GetCollisionGroup(void){
			return _iCollisionGroup;
		}
		
		/**
		 *  Fija un booleano que indica si la entidad chequeará colisión o no
		 *	@param bCheckCollision Booleano que indica si la entidad chequeará colisión o no
		 */
		void SetCheckCollision(bool bCheckCollision){
			_bCheckCollision=bCheckCollision;
		}

		/**
		 *  Devuelve un booleano que indica si la entidad chequeará colisión o no
		 *	@return Booleano que indica si la entidad chequeará colisión o no
		 */
		bool GetCheckCollision(){
			return _bCheckCollision;
		}

		/**
		 *  Fija si la entidad se encuentra rotando o no. 
		 *	En el caso de activar ésta propiedad, al llamar al método Update, la entidad rotará 
		 *	según el parámetro indicado por el método SetRotationSpeed.
		 *	@see SetRotationSpeed()
		 *	@see Update()
		 *	@param rotating booleano que indica si estará rotando o no
		 */
		void SetRotating(bool rotating){
			_rotating=rotating;
		}

		/**
		 *  Devuelve si la entidad se encuentra rotando o no. 
		 *	@see SetRotating()
		 *	@return Booleano que indica si la rotación está activada o no
		 */
		bool GetRotating(){
			return _rotating;
		}

		/**
		 *  Fija si la entidad se encuentra moviéndose o no. 
		 *	En el caso de activar ésta propiedad, al llamar al método Update, la entidad se moverá
		 *	según los parámetros indicados por los método SetSpeed (velocidad) y SetMovDirection 
		 *	(dirección de movimiento).
		 *	@see SetSpeed()
		 *	@see SetMovDirection()
		 *	@see Update()
		 *	@param bMoving booleano que indica si estará rotando o no
		 */
		void SetMoving(bool bMoving){
			_bMoving=bMoving;
		}

		/**
		 *  Devuelve si la entidad se está moviendo o no. 
		 *	@see SetMoving()
		 *	@return Booleano que indica si el movimiento está activado o no
		 */
		bool GetMoving(){
			return _bMoving;
		}
		
		/**
		 *  Fija la velocidad de rotación.
		 *	@see SetRotating()
		 *	@see Update()
		 *	@param speed número decimal que indica la velocidad a la que rotará la entidad
		 */
		void SetRotationSpeed(float speed){
			_rotationSpeed=speed;
		}
		
		/**
		 *  Devuelve la velocidad de rotación fijada por SetRotationSpeed.
		 *	@see SetRotationSpeed()
		 *	@see SetRotating()
		 *	@see Update()
		 *	@return Número decimal que indica la velocidad a la que rotará la entidad
		 */
		float GetRotationSpeed(){
			return _rotationSpeed;
		}

		/**
		 *  Fija la velocidad de traslación de la entidad.
		 *	@see SetMoving()
		 *	@see Update()
		 *	@param speed número decimal que indica la velocidad a la que se trasladará la entidad
		 */
		void SetSpeed(float speed){
			_fMovingSpeed=speed;
		}
		
		/**
		 *  Devuelve la velocidad de traslación de la entidad.
		 *	@see SetSpeed()
		 *	@see SetMoving()
		 *	@see Update()
		 *	@return Número decimal que indica la velocidad a la que se trasladará la entidad
		 */
		float GetSpeed(){
			return _fMovingSpeed;
		}
		
		/**
		 *  Fija la dirección en la que se trasladará la entidad
		 *	@see SetSpeed()
		 *	@see SetMoving()
		 *	@see Update()
		 *	@param direction número decimal que indica el ángulo de dirección
		 */
		void SetMovDirection(float direction){
			_fMovingDegrees=direction;

			MathUtil::SinCos(_fMovingDegrees,&_sinDegree, &_cosDegree);
		}
		
		/**
		 *  Devuelve la dirección en la que se trasladará la entidad
		 *	@see SetSpeed()
		 *	@see SetMoving()
		 *	@see Update()
		 *	@return Número decimal que indica el ángulo de dirección
		 */
		float GetMovDirection(){
			return _fMovingDegrees;
		}
		
		/**
		 *  Fija la posición en el eje X
		 *	@param posX número decimal que indica la posición en el eje X
		 */
		void SetPosX(float posX) {
			_fPreviousPosX = _fPosX;
			_fPreviousPosY = _fPosY;
			_fPosX = posX;
			_fCollisionPosX=_fCollisionRelPosX+_fPosX;
		}

		/**
		 *  Fija la posición en el eje Y
		 *	@param posY número decimal que indica la posición en el eje Y
		 */
		void SetPosY(float posY) {
			_fPreviousPosX = _fPosX;
			_fPreviousPosY = _fPosY;
			_fPosY = posY;
			_fCollisionPosY=_fCollisionRelPosY+_fPosY;
		}
	
		/**
		 *  Fija la posición en ambos ejes cartesianos
		 *	@param fPosx número decimal que indica la posición en el eje X
		 *	@param fPosy número decimal que indica la posición en el eje Y
		 */
		void SetPos(float fPosx, float fPosy) {
			_fPreviousPosX = _fPosX;
			_fPreviousPosY = _fPosY;
			_fPosX = fPosx;
			_fPosY = fPosy;
			_fCollisionPosX=_fCollisionRelPosX+_fPosX;
			_fCollisionPosY=_fCollisionRelPosY+_fPosY;
		}

		/**
		 *  Devuelve la posición en ambos ejes cartesianos
		 *	@param fPosx número decimal que indica la posición en el eje X
		 *	@param fPosy número decimal que indica la posición en el eje Y
		 */
		void GetPos(float &fPosx, float &fPosy) {
			fPosx = _fPosX;
			fPosy = _fPosY;
		}

		/**
		 *  Devuelve la posición en el eje X
		 *	@return Número decimal que indica la posición en el eje X
		 */
		float GetPosX() {
			return _fPosX;
		}

		/**
		 *  Devuelve la posición en el eje Y
		 *	@return Número decimal que indica la posición en el eje Y
		 */
		float GetPosY() {
			return _fPosY;
		}
	
		/**
		 *  Fija la posición de la entidad a su posición en la iteración anterior
		 */
		void SetToPreviousPosition() {
			_fPosX = _fPreviousPosX;
			_fPosY = _fPreviousPosY;
		}

		/**
		*	Devuelve la posición anterior en ambos ejes cartesianos
		*	@param fPosx número decimal que indica la posición en el eje X
		*	@param fPosy número decimal que indica la posición en el eje Y
		*/
		void GetPreviousPos(float &fPosx, float &fPosy) {
			fPosx = _fPreviousPosX;
			fPosy = _fPreviousPosY;
		}

		/**
		*	Devuelve la posición anterior en el eje X
		*	@return Retorna la posición anterior en el eje X
		*/
		float GetPreviousPosX() {
			return _fPreviousPosX;
		}

		/**
		*	Devuelve la posición anterior en el eje Y
		*	@return Retorna la posición anterior en el eje Y
		*/
		float GetPreviousPosY() {
			return _fPreviousPosY;
		}

		/**
		 *  Devuelve el tipo de colisión de la entidad
		 *	@return Devuelve un tipo enumerador que indica el tipo de colisión de la entidad
		 */
		CollisionType GetCollisionType() {
			return _collisionType;
		}

		/**
		 *  Fija el tipo de colisión de la entidad
		 *	@param  collisionType Tipo enumerador que indica el tipo de colisión de la entidad
		 */
		void SetCollisionType(int collisionType) {
			_collisionType = (CollisionType)collisionType;
		}

		/**
		 *  Fija la posición relativa a la entidad del área de colisión
		 *	@param fPosx posición en el eje X del área de colisión
		 *	@param fPosy posición en el eje Y del área de colisión
		 */
		void SetCollisionPos(float fPosx, float fPosy) {
			_fCollisionRelPosX = fPosx;
			_fCollisionRelPosY = fPosy;
			_fCollisionPosX = fPosx;
			_fCollisionPosY = fPosy;
			_fCollisionPosX+=_fPosX;
			_fCollisionPosY+=_fPosY;
		}

		/**
		 *  Fija la posición relativa a la entidad del área de colisión
		 *	@param fPosx posición en el eje X del área de colisión
		 */
		void SetCollisionPosX(float fPosx) {
			_fCollisionRelPosX = fPosx;
			_fCollisionPosX = fPosx;
			_fCollisionPosX+=_fPosX;
		}
		void SetCollisionPosY(float fPosy) {
			_fCollisionRelPosY = fPosy;
			_fCollisionPosY = fPosy;
			_fCollisionPosY+=_fPosY;
		}

		/**
		 *  Devuelve la posición relativa a la entidad del área de colisión
		 *	@param fPosx posición en el eje X del área de colisión
		 *	@param fPosy posición en el eje Y del área de colisión
		 */
		void GetCollisionPos(float &fPosx, float &fPosy) {
			fPosx = _fCollisionPosX;
			fPosy = _fCollisionPosY;
		}

		float GetCollisionPosX() { return _fCollisionPosX; }
		float GetCollisionPosY() { return _fCollisionPosY; }

		/**
		 *  Fija el tamaño del área de colisión 
		 *	@param fSizeX ancho del área de colisión
		 *	@param fSizeY alto del área de colisión
		 */
		void SetCollisionSize(float fSizeX, float fSizeY) {
			_fCollisionSizeX = fSizeX;
			_fCollisionSizeY = fSizeY;
		}

		/**
		 *  Fija el tamaño del área de colisión 
		 *	@param fSizeX ancho del área de colisión
		 */
		void SetCollisionWidth(float fSizeX) {
			_fCollisionSizeX = fSizeX;
		}
		/**
		 *  Fija el tamaño del área de colisión 
		 *	@param fSizeY ancho del área de colisión
		 */
		void SetCollisionHeight(float fSizeY) {
			_fCollisionSizeY = fSizeY;
		}

		/**
		 *  Devuelve el tamaño del área de colisión 
		 *	@param fSizeX ancho del área de colisión
		 *	@param fSizeY alto del área de colisión
		 */
		void GetCollisionSize(float &fSizeX, float &fSizeY) {
			fSizeX = _fCollisionSizeX;
			fSizeY = _fCollisionSizeY;
		}

		/**
		 *  Devuelve el ancho del área de colisión 
		 *	@return Número decimal que indica el ancho del área de colisión
		 */
		float GetCollisionWidth() {
			return _fCollisionSizeX;
		}

		/**
		 *  Devuelve el alto del área de colisión 
		 *	@return Número decimal que indica el alto del área de colisión
		 */
		float GetCollisionHeight() {
			return _fCollisionSizeY;
		}
		
		/**
		 *  Fija la visibilidad del área de colisión
		 *	@see DrawCollision()
		 *	@param bCollisionVisible booleano que indica si el área de colisión será visible o no
		 */
		void SetCollisionVisible(bool bCollisionVisible) {
			_bCollisionVisible = bCollisionVisible;
		}

		/**
		 *  Retora la visibilidad del área de colisión
		 *	@see DrawCollision()
		 *	@return retorna true si el área de colisión está visible y false en caso contrario
		 */
		bool GetCollisionVisible() {
			return _bCollisionVisible;
		}

		/**
		 *  Fija la rotación de la entidad
		 *	@param fAngleZ número decimal que indica el ángulo en grados que se rotará la entidad
		 */
		void SetAngleZ (float fAngleZ) {
			_fAngleZ = fAngleZ;

			if (_fAngleZ < 0) {
				_fAngleZ += 360.0f*(float)(((int)(-_fAngleZ)/360)+1);
			} else if (_fAngleZ >= 360) {
				_fAngleZ -= 360.0f*(float)(((int)(_fAngleZ)/360));
			}
		}

		/**
		 *  Devuelve la rotación de la entidad
		 *	@return Número decimal que indica el ángulo en grados que se rotará la entidad
		 */
		float  GetAngleZ () {
			return _fAngleZ;
		}

		/**
		 *  Fija el tamaño de la entidad
		 *	@param w ancho de la entidad
		 *	@param h alto de la entidad
		 */
		void SetDim(float w, float h) 
		{
			_fWidth = w;
			_fHeight = h;
		};

		/**
		 *  Devuelve el tamaño de la entidad
		 *	@param w ancho de la entidad
		 *	@param h alto de la entidad
		 */
		void GetDim(float &w, float &h) 
		{
			w = _fWidth;
			h = _fHeight;
		};

		/**
		 *  Fija el ancho de la entidad
		 *	@param w ancho de la entidad
		 */
		void SetWidth(float w) 
		{
			_fWidth = w;
		};

		/**
		 *  Fija el alto de la entidad
		 *	@param h alto de la entidad
		 */
		void SetHeight(float h) 
		{
			_fHeight = h;
		};

		/**
		 *  Devuelve el ancho de la entidad
		 *	@return Ancho de la entidad
		 */
		float GetWidth() 
		{
			return _fWidth;
		};

		/**
		 *  Devuelve el alto de la entidad
		 *	@return Alto de la entidad
		 */
		float GetHeight() 
		{
			return _fHeight;
		};

		/**
		 *  Fija la escala de la entidad. Su valor por defecto es 1.0f en ambos ejes.
		 *	@param x escala en el eje X de la entidad
		 *	@param y escala en el eje Y de la entidad
		 */
		void SetScale(float x, float y) {
			_scaleX = x;
			_scaleY = y;
			_scale = x;
		}

		/**
		 *  Devuelve la escala.
		 *	@return escala de la entidad
		 */
		float GetScale() {
			return _scale;
		}

		/**
		 *  Fija la escala de la entidad. Su valor por defecto es 1.0f.
		 *	@return escala de la entidad
		 */
		void SetScale(float scale) {
			_scale = scale;
			_scaleX = scale;
			_scaleY = scale;
		}

		/**
		 *  Fija la escala de la entidad en el eje X. Su valor por defecto es 1.0f.
		 *	@param x escala de la entidad en el eje X.
		 */
		void SetScaleX(float x) {
			_scaleX = x;
			_scale = x;
		}

		/**
		 *  Fija la escala de la entidad en el eje Y. Su valor por defecto es 1.0f.
		 *	@param y escala de la entidad en el eje Y.
		 */
		void SetScaleY(float y) {
			_scaleY = y;
			_scale = y;
		}

		/**
		 *  Devuelve la escala de la entidad en el eje X. 
		 *	@return Escala de la entidad en el eje X.
		 */
		float GetScaleX() {
			return _scaleX;
		}

		/**
		 *  Devuelve la escala de la entidad en el eje Y. Su valor por defecto es 1.0f.
		 *	@return Escala de la entidad en el eje Y.
		 */
		float GetScaleY() {
			return _scaleY;
		}

		/**
		 *  Invierte la entidad horizontalmente
		 */
		void FlipHorizontal() {
			_flipH *= -1;
		}

		/**
		 *  Invierte la entidad verticalmente
		 */
		void FlipVertical() {
			_flipV *= -1;
		}

		/**
		 *  Devuelve si la entidad fue invertida horizontalmente
		 *	@return Devuelve true en caso de estar invertida horizontalmente y false en caso contrario
		 */
		bool GetFlipHorizontal() { return (_flipH == -1); }

		/**
		 *  Devuelve si la entidad fue invertida verticalmente
		 *	@return Devuelve true en caso de estar invertida verticalmente y false en caso contrario
		 */
		bool GetFlipVertical() { return (_flipV == -1); }

		/**
		*  Posiciona el pívot
		*  @param x posición en el eje X
		*  @param y posición en el eje Y
		*/
		void SetPivotPos(float x, float y) {
			_pivotPosX = x;
			_pivotPosY = y;
		}

		/**
		*  Posiciona el pívot en el eje X
		*  @param x posición en el eje X
		*/
		void SetPivotPosX(float x) {
			_pivotPosX = x;
		}

		/**
		*  Posiciona el pívot en el eje Y
		*  @param y posición en el eje Y
		*/
		void SetPivotPosY(float y) {
			_pivotPosY = y;
		}

		/**
		*  Devuelve la posición en el eje X
		*  @return Posición del pívot en el eje X
		*/
		float GetPivotPosX() {
			return _pivotPosX;
		}

		/**
		*  Devuelve la posición en el eje Y
		*  @return Posición del pívot en el eje Y
		*/
		float GetPivotPosY() {
			return _pivotPosY;
		}

		/**
		*  Setea la posición de la entidad relativa al centro dadas una dirección y una distancia
		*  @param fAngle ángulo que define la dirección
		*  @param fDistance distancia del centro
		*/
		void SetRelativePos(float fAngle, float fDistance)
		{
			_fPosX +=	fDistance * _cosDegree;

			_fPosY +=	fDistance * _sinDegree;

			_fCollisionPosX=_fCollisionRelPosX+_fPosX;
			_fCollisionPosY=_fCollisionRelPosY+_fPosY;
		}

		/**
		*  Actualiza la entidad
		*  @param fTimeBetweenFrames tiempo transcurridos en cada iteración
		*/
		virtual void Update(float fTimeBetweenFrames) {
			_fPreviousPosX = _fPosX;
			_fPreviousPosY = _fPosY;

			if (_bMoving) {
				_fPosX +=	fTimeBetweenFrames * 
							_fMovingSpeed * 
							_cosDegree;

				_fPosY +=	fTimeBetweenFrames *
							_fMovingSpeed * 
							_sinDegree;

			}
			_fCollisionPosX=_fPosX + _fCollisionRelPosX * _cosDegree;
			_fCollisionPosY=_fPosY + _fCollisionRelPosY * _sinDegree;

			if (_rotating) {
				_fAngleZ += _rotationSpeed*fTimeBetweenFrames;

				if (_fAngleZ < 0) {
					_fAngleZ += 360.0f*(float)(((int)(-_fAngleZ)/360)+1);
				} else if (_fAngleZ >= 360) {
					_fAngleZ -= 360.0f*(float)(((int)(_fAngleZ)/360));
				}
			}
		}

		/**
		*  Dibuja el pivot
		*/
		void DrawPivot()
		{
			g_renderer.SetMatrixMode(ZAK_WORLD_MATRIX);
			g_renderer.LoadIdentity();

			g_renderer.Translate (MathUtil::Round(_fPosX), MathUtil::Round(_fPosY), 1.0f);
//			g_renderer.Translate (_fCollisionPosX, _fCollisionPosY, 1.0f);

			g_renderer.RotationZ(MathUtil::Round(_fAngleZ));
			//g_renderer.Translate (MathUtil::Round(_pivotPosX), MathUtil::Round(_pivotPosY), 1.0f);
			g_renderer.Scale(_scaleX, _scaleY);
			
			g_renderer.BindTexture(NULL);

			_VertexColor[0].SetVal(0, -GetHeight()/8*_scaleY, 1.0f,_collisionColor);
			_VertexColor[1].SetVal(0,  GetHeight()/8*_scaleY, 1.0f,_collisionColor);
			_VertexColor[2].SetVal(-GetWidth()/8*_scaleX,  0, 1.0f,_collisionColor);
			_VertexColor[3].SetVal( GetWidth()/8*_scaleX, 0, 1.0f,_collisionColor);

			g_renderer.Draw(_VertexColor, ZAK_PRI_LINELIST,4);
			
		}

		/**
		*  Dibuja la entidad
		*/
		virtual void Draw()
		{
			// se modifica la matriz de translacion
			g_renderer.SetMatrixMode(ZAK_WORLD_MATRIX);
			g_renderer.LoadIdentity();

			g_renderer.Translate (MathUtil::Round(_fPosX), MathUtil::Round(_fPosY), 1.0f);
//			g_renderer.Translate (_fCollisionPosX, _fCollisionPosY, 1.0f);
			
			if (_fAngleZ != 0.0f)
				g_renderer.RotationZ(MathUtil::Round(_fAngleZ));

			if (_pivotPosX != 0.0f || _pivotPosY != 0.0f)
				g_renderer.Translate (MathUtil::Round(_pivotPosX), MathUtil::Round(_pivotPosY), 1.0f);

			if (_scaleX != 0.0f || _scaleY != 0.0f)
				g_renderer.Scale(_scaleX, _scaleY);
		}

		/**
		*  Dibuja el área de colisión
		*/
		void DrawCollision()
		{
			g_renderer.SetMatrixMode(ZAK_WORLD_MATRIX);
			g_renderer.LoadIdentity();

			//g_renderer.Translate (_fCollisionPosX+_pivotPosX, _fCollisionPosY+_pivotPosY, 1.0f);
			g_renderer.Translate (MathUtil::Round(_fCollisionPosX), MathUtil::Round(_fCollisionPosY), 1.0f);

			g_renderer.BindTexture(NULL);

			if (_fAngleZ != 0.0f)
				g_renderer.RotationZ(MathUtil::Round(_fAngleZ));

			if (_pivotPosX != 0.0f || _pivotPosY != 0.0f)
				g_renderer.Translate (MathUtil::Round(_pivotPosX), MathUtil::Round(_pivotPosY), 1.0f);

			if (_scaleX != 0.0f || _scaleY != 0.0f)
				g_renderer.Scale(_scaleX, _scaleY);


			switch (_collisionType) {
				case eCollisionBBox:

					_VertexColor[0].SetVal(-_fCollisionSizeX/2, -_fCollisionSizeY/2, 1.0f,_collisionColor);
					_VertexColor[1].SetVal(-_fCollisionSizeX/2,  _fCollisionSizeY/2, 1.0f,_collisionColor);
					_VertexColor[2].SetVal( _fCollisionSizeX/2,  _fCollisionSizeY/2, 1.0f,_collisionColor);
					_VertexColor[3].SetVal( _fCollisionSizeX/2, -_fCollisionSizeY/2, 1.0f,_collisionColor);
					_VertexColor[4].SetVal(-_fCollisionSizeX/2, -_fCollisionSizeY/2, 1.0f,_collisionColor);


					g_renderer.Draw(_VertexColor, ZAK_PRI_LINESTRIP,5);
					break;
				case eCollisionCircle:
				default:
					static float cos;
					static float sin;
					static float co;
					static float ca;

					for (int i=0; i<16; i++) {
						MathUtil::SinCos((360.0f/16.0f)*(float)i, &sin, &cos);
						co = _collisionRadius*sin;
						ca = _collisionRadius*cos;

						_VertexColor[i].SetVal(ca,co, 1.0f,_collisionColor);
					}

					MathUtil::SinCos(0, &sin, &cos);
					co = _collisionRadius*sin;
					ca = _collisionRadius*cos;

					_VertexColor[16].SetVal(ca,co, 1.0f,_collisionColor);
					
					g_renderer.Draw(_VertexColor, ZAK_PRI_LINESTRIP,17);

					break;
			}
		}

		float x1;
		float y1;
		float r1;
		float w1;
		float h1;
		float a1;
		rectangle rect1;
		rectangle rect2;
		float x2;
		float y2;
		float r2;
		float w2;
		float h2;
		float a2;
		Entity2D* ent1;
		/**
		*  Devuelve si la entidad está colisionando con otra (ya no existe)
		*  @param pEntity entidad contra la que se chequeará la colisión
		*  @return devuelve verdadero si hubo colisión y falso en caso contrario
		*/
		virtual bool IsColliding(Entity2D *ent2) 
		{

			x1 = this->GetPivotPosX() + this->GetCollisionPosX();
			y1 = this->GetPivotPosY() + this->GetCollisionPosY();
			r1 = this->GetCollisionRadius()*((this->GetScaleX()>this->GetScaleY())?this->GetScaleX():this->GetScaleY());

			x2 = ent2->GetPivotPosX()+ ent2->GetCollisionPosX();
			y2 = ent2->GetPivotPosY()+ ent2->GetCollisionPosY();
			r2 = ent2->GetCollisionRadius()*((ent2->GetScaleX()>ent2->GetScaleY())?ent2->GetScaleX():ent2->GetScaleY());

			if (MathUtil::DistanceQuad(x1, y1, x2,y2) <= (r1+r2)*(r1+r2)) {
				if (this->GetCollisionType() == Entity2D::eCollisionBBox) {
					w1 = this->GetCollisionWidth()*this->GetScaleX();
					h1 = this->GetCollisionHeight()*this->GetScaleY();
					a1 = this->GetAngleZ();
					if (ent2->GetCollisionType() == Entity2D::eCollisionBBox) {
						w2 = ent2->GetCollisionWidth()*ent2->GetScaleX();
						h2 = ent2->GetCollisionHeight()*ent2->GetScaleY();
						a2 = ent2->GetAngleZ();
						if (a1 != 0 && a2 != 0) {
							MathUtil::make_rectangle(&rect1, (int)(x1), (int)(y1), (int)(w1/2), (int)(h1/2), (int)(w1/2),(int)(h1/2), (float)(DegreeToRad((double)a1+90.0)));
							MathUtil::make_rectangle(&rect2, (int)(x2), (int)(y2), (int)(w2/2), (int)(h2/2), (int)(w2/2),(int)(h2/2), (float)(DegreeToRad((double)a2+90.0)));
							MathUtil::rotate_and_translate_rect(&rect1);
							MathUtil::rotate_and_translate_rect(&rect2);
							if (MathUtil::rotated_rectangle_to_rotated_rectangle_intersect(&rect1, &rect2))
								return true;
						} else if (a1 != 0) {
							MathUtil::make_rectangle(&rect1, (int)(x1), (int)(y1), (int)(w1/2), (int)(h1/2), (int)(w1/2),(int)(h1/2), (float)(DegreeToRad((double)a1+90.0)));
							MathUtil::rotate_and_translate_rect(&rect1);
							if (MathUtil::rotated_rectangle_to_rectangle_intersect(&rect1, (int)(x2-w2/2), (int)(y2-h2/2), (int)(x2+w2/2), (int)(y2+h2/2)))
								return true;
						} else if (a2 != 0) {
							MathUtil::make_rectangle(&rect2, (int)(x2), (int)(y2), (int)(w2/2), (int)(h2/2), (int)(w2/2),(int)(h2/2), (float)(DegreeToRad((double)a2+90.0)));
							MathUtil::rotate_and_translate_rect(&rect2);
							if (MathUtil::rotated_rectangle_to_rectangle_intersect(&rect2, (int)(x1-w1/2), (int)(y1-h1/2), (int)(x1+w1/2), (int)(y1+h1/2)))
								return true;
						} else if (MathUtil::rectangle_to_rectangle_intersect((int)(x1-w1/2), (int)(y1-h1/2), (int)(x1+w1/2), (int)(y1+h1/2), (int)(x2-w2/2), (int)(y2-h2/2), (int)(x2+w2/2), (int)(y2+h2/2)))
							return true;
					} else if (ent2->GetCollisionType() == Entity2D::eCollisionCircle) {
						if (a1 != 0) {
							MathUtil::make_rectangle(&rect1, (int)(x1), (int)(y1), (int)(w1/2), (int)(h1/2), (int)(w1/2),(int)(h1/2), (float)(DegreeToRad((double)a1+90.0)));
							MathUtil::rotate_and_translate_rect(&rect1);
							if (MathUtil::rotated_rectangle_to_circle_intersect(&rect1, (int)(x2),(int)(y2),(int)(r2)))
								return true;
						} else if (MathUtil::rectangle_to_circle_intersect((int)(x1-w1/2), (int)(y1-h1/2), (int)(x1+w1/2), (int)(y1+h1/2), (int)x2,(int)y2,(int)r2))
							return true;
					}
				} else if (this->GetCollisionType() == Entity2D::eCollisionCircle) {
					if (ent2->GetCollisionType() == Entity2D::eCollisionBBox) {
						w2 = ent2->GetCollisionWidth()*ent2->GetScaleX();
						h2 = ent2->GetCollisionHeight()*ent2->GetScaleY();
						a2 = ent2->GetAngleZ();
						if (a2 != 0) {
							MathUtil::make_rectangle(&rect2, (int)(x2), (int)(y2), (int)(w2/2), (int)(h2/2), (int)(w2/2),(int)(h2/2), (float)(DegreeToRad(a2+90)));
							MathUtil::rotate_and_translate_rect(&rect2);
							if (MathUtil::rotated_rectangle_to_circle_intersect(&rect2, (int)(x1),(int)(y1),(int)(r1)))
								return true;
						} else if (MathUtil::rectangle_to_circle_intersect((int)(x2-w2/2), (int)(y2-h2/2), (int)(x2+w2/2), (int)(y2+h2/2), (int)x1,(int)y1,(int)r1))
							return true;
					} else
						return true;
				}
			}

			return false;
		}
		
		/**
		*  Método virtual que debemos invocar en caso de haber colisión
		*  @param pEntity entidad contra la que se ha colisionado
		*/
		virtual void OnCollide(Entity2D *pEntity) 
		{
		}

		/**
		*  Constructor
		*/
		Entity2D()
		{
			_iCollisionGroup=0;
			_fPosX = 0;
			_fPosY = 0;
			_fPreviousPosX = 0;
			_fPreviousPosY = 0;
			_fCollisionRelPosX = 0;
			_fCollisionRelPosY = 0;
			_fCollisionPosX = 0;
			_fCollisionPosY = 0;
			_fCollisionSizeX = 0;
			_fCollisionSizeY = 0;
			_fWidth = 0;
			_fHeight = 0;
			_fAngleZ = 0;
			_bCheckCollision = false;
			_bMoving = false;
			_fMovingSpeed	 = 0;
			_fMovingDegrees = 0;
			_bCollisionVisible = false;
			_rotationSpeed = 0;
			_rotating = false;
			_scale = 1.0f;
			_scaleX = 1.0f;
			_scaleY = 1.0f;
			_collisionType = eCollisionCircle;
			_flipH = 1;
			_flipV = 1;
			_lastFlipHState = 1;
			_lastFlipVState = 1;
			_pivotPosX = 0.0f;
			_pivotPosY = 0.0f;
			_collisionColor = 0xFFFFFFFF;
		}

		/**
		*  Destructor
		*/
		virtual ~Entity2D(){
		}
	private:

};

}

#endif // _Entity2D_H_
