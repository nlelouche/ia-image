// Shape.h: interface for the Shape class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _Shape_H_
#define _Shape_H_

#include "Renderer.h"
#include "VertexBufferManager.h"
#include "Entity2D.h"
#include "Defines.h"

#define CIRCLE_MAX_SEGMENTS 102

#if _MSC_VER > 1000	
#pragma once
#endif // _MSC_VER > 1000

namespace zak {

enum ShapeType
{
	ZAK_SHAPE_TRIANGLE=0,
	ZAK_SHAPE_QUAD=1,
	ZAK_SHAPE_CIRCLE=2
};
/**
 *  Clase que permite dibujar formas geométricas sin textura
 *	@author Juan Pablo "McKrackeN" Bettini
 */
class ZAKENGINE_API Shape : public Entity2D
{
	private:
		unsigned int   _Color;
		unsigned int   _Color1;
		unsigned int   _Color2;
		unsigned int   _Color3;
		unsigned int   _Color4;
		float			_radius;
		int				_segments;

		ShapeType   _eShapeType;
		ColorVertex _vertex[CIRCLE_MAX_SEGMENTS];


		void SetShape(int Type) { SetShape((ShapeType)Type); }


	public:
		void SetSegmentsCount(int segments) { if (segments < CIRCLE_MAX_SEGMENTS-2 && segments >= 3) _segments = segments; }
		/**
		 *  Permite indicar colores por vértice
		 *	@param dwColor1 color para el primer vértice
		 *	@param dwColor2 color para el segundo vértice
		 *	@param dwColor3 color para el tercer vértice
		 *	@param dwColor4 color para el cuarto vértice
		 */
		void SetColorPerVertex(DWORD dwColor1,DWORD dwColor2,DWORD dwColor3,DWORD dwColor4);

		/**
		 *  Permite indicar colores por vértice
		 *	@param dwColor1 color para el primer vértice
		 *	@param dwColor2 color para el segundo vértice
		 *	@param dwColor3 color para el tercer vértice
		 */
		void SetColorPerVertex(DWORD dwColor1,DWORD dwColor2,DWORD dwColor3);

		/**
		 *  Permite indicar un color general para toda la figura
		 *	@param color color para la figura
		 */
		void SetColor(DWORD color);

		/**
		 *  Permite indicar el tipo de figura a mostrar
		 *	@param Type tipo de figura que puede ser ZAK_SHAPE_TRIANGLE o ZAK_SHAPE_QUAD
		 */
		void SetShape(ShapeType Type);

		void SetRadius(float radius) { _radius = radius; }
		float GetRadius() { return _radius; }

		/**
		 *  Muestra la figura en pantalla
		 */
		virtual void Draw();
		
		//bool IsColliding(Shape *shape) { return Entity2D::IsColliding((Entity2D*)shape); }

		/**
		 *  Constructor
		 */
		Shape ();

		/**
		 *  Destructor
		 */
		virtual ~Shape ();
};

}

#endif // _Shape_H_
