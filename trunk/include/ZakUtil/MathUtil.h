#pragma once

#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "zakutilapi.h"


#define ZAK_PI			3.1415926535897932384626433832795
#define DegreeToRad(n)	n*0.017453292519943295769236907684886
#define RadToDegree(n)	n*57.295779513082320876798154814105
#define ZAK_MAX_RAND	180000
#define BEFORE_LINE (-1)
#define ON_LINE (0)
#define AFTER_LINE (1)

#define CO_LINEAR (-1)
#define NO_INTERSECTION (0)
#define INTERSECTION (1)

#define NUM_CO_ORDS (4)
#define NUM_AXIS (2)

#define X_CO_ORD (0)
#define Y_CO_ORD (1)


namespace zak {


struct rectangle
{
	int co_ords[NUM_CO_ORDS][NUM_AXIS]; // Don't really need float for the sort of accuracy I'm after.
	float angle;
	int pivot_x;
	int pivot_y;
	float cos_angle;
	float sin_angle;
};

/**
 *  Clase que contiene métodos para distintos cálculos como
 *  por ejemplo senos y cosenos a partir de tablas o el cálculo
 *  de la distancia entre dos puntos.
 *	@author Juan Pablo "McKrackeN" Bettini
 */
class ZAKUTIL_API MathUtil {

public:
	/**
	 *  Devuelve el arcotangente del ángulo pasado por parámtro
	 *	@param tan tangente del ángulo
	 *	@return valor del arcotangente
	 */
	static float ATan(float tan);

	static float ATan2(float x, float y);

	/**
	 *  Devuelve el arcocoseno del ángulo pasado por parámtro
	 *	@param cos coseno del ángulo
	 *	@return valor del arcocoseno 
	 */
	static float ACos(float cos);

	/**
	 *  Devuelve el arcoseno del ángulo pasado por parámtro
	 *	@param sin seno del ángulo
	 *	@return valor del arcoseno 
	 */
	static float ASin(float sin);

	/**
	 *  Devuelve el seno del ángulo pasado por parámtro
	 *	@param degree ángulo en grados 
	 *	@return valor del seno del ángulo dado
	 */
	static float Sin(float degree);

	/**
	 *  Devuelve el coseno del ángulo pasado por parámtro
	 *	@param degree ángulo en grados 
	 *	@return valor del coseno del ángulo dado
	 */
	static float Cos(float degree);

	/**
	 *  Devuelve la tangente del ángulo pasado por parámtro
	 *	@param degree ángulo en grados 
	 *	@return valor de la tangente del ángulo dado
	 */
	static float Tan(float degree);

	/**
	 *  Devuelve el seno y el coseno del ángulo pasado por parámtro
	 *	@param degree ángulo en grados centígrados
	 *	@param sine devuelve el seno del ángulo
	 *	@param cosine devuelve el coseno del ángulo
	 */
	static void SinCos(float degree, float *sine, float *cosine);

	static void TanCalc(float degree, float *tan) { *tan = (float)tanf((float)(DegreeToRad((float)degree))); } 


	/**
	 *  Devuelve un número aleatorio
	 *	Ejemplo de uso:
	 \code
		// Devuelve un número del 0 al 9
		int rnd = MathUtil::Random()%10;

		// Devuelve un número del 1 al 10
		int rnd1 = MathUtil::Random()%10+1;

		// Devuelve un número del 10 al 19
		int rnd2 = MathUtil::Random()%10+10;
	 \endcode
	 *	@return devuelve un número aleatorio
	 */
	static int Random() {
		_randIndex++;

		if (_randIndex >= ZAK_MAX_RAND) {
			_randIndex = 0;
		}

		return _rand[_randIndex];
	}

	/**
	 *  Devuelve la distancia al cuadrado (más rápida) entre dos puntos
	 *	@param x1 Coordenada x de la posición del punto 1
	 *	@param y1 Coordenada y de la posición del punto 1
	 *	@param x2 Coordenada x de la posición del punto 2
	 *	@param y2 Coordenada y de la posición del punto 2
	 *	@return Distancia al cuadrado entre los dos puntos
	 */
	static float DistanceQuad (float x1, float y1, float x2, float y2) { return ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); }

	/**
	 *  Devuelve la distancia entre dos puntos
	 *	@param x1 Coordenada x de la posición del punto 1
	 *	@param y1 Coordenada y de la posición del punto 1
	 *	@param x2 Coordenada x de la posición del punto 2
	 *	@param y2 Coordenada y de la posición del punto 2
	 *	@return Distancia entre los dos puntos
	 */
	static float Distance	  (float x1, float y1, float x2, float y2) { return sqrt(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))); }

	/**
	 *  Redondea un número flotante
	 *	@param num Número que se desea redondear
	 *	@return Redondeo del número
	 */
	static float Round (float num);

	static void SinCosCalc(float degree, float *sine, float *cosine);

	static float Pow(float num, int power);
	static int Pow(int num, int power);

	static int sgn_int(int value);
	static int sgn_float (float value);
	static float distance_to_line (float x1, float y1, float x2, float y2, float px, float py , int *point_of_line , float *ratio_on_line);
	static bool same_signs (float a, float b);
	static int intersect_lines (float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,float *ix,float *iy);
	static bool line_to_line_intersect (int line_1_x1 , int line_1_y1 , int line_1_x2 , int line_1_y2 , int line_2_x1 , int line_2_y1 , int line_2_x2 , int line_2_y2 );
	static int wrap (int value , int wrap);
	static void make_rectangle ( rectangle *r , int x, int y, int upper_width , int upper_height , int lower_width , int lower_height , float angle );
	static void rotate_and_translate_rect ( rectangle *r );
	static void find_rotated_rectangle_extents ( rectangle *r , int *rect_x1 , int *rect_y1 , int *rect_x2 , int *rect_y2 );
	static bool rotated_rectangle_bounding_box_check ( rectangle *r1 , rectangle *r2 );
	static bool rotated_rectangle_to_point_intersect ( rectangle *r , int px, int py );
	static bool rotated_rectangle_to_rotated_rectangle_intersect ( rectangle *r1 , rectangle *r2 );
	static bool rotated_rectangle_to_rectangle_intersect ( rectangle *r1 , int rect_x1 , int rect_y1 , int rect_x2 , int rect_y2 );
	static bool rotated_rectangle_to_circle_intersect (rectangle *r , int px , int py , int radius );
	static bool rectangle_to_rectangle_intersect (int rect_1_x1 , int rect_1_y1 , int rect_1_x2 , int rect_1_y2 , int rect_2_x1 , int rect_2_y1 , int rect_2_x2 , int rect_2_y2);
	static bool rectangle_to_circle_intersect ( int rect_x1 , int rect_y1 , int rect_x2 , int rect_y2 , int circle_x , int circle_y , int radius );
	static bool rectangle_to_point_intersect (int rect_x1 , int rect_y1 , int rect_x2 , int rect_y2 , int px, int py);
	static bool circle_to_circle_intersect ( int x1 , int y1 , int r1 , int x2 , int y2 , int r2 );
	static bool circle_to_point_intersect ( int x1 , int y1 , int r1 , int x2 , int y2 );

private:
	static bool Initialize();
	static void Shutdown() {
		if (_rand)
			delete [] _rand;
	}

	static float _sin[360];
	static float _cos[360];
	static float _tan[360];
	static int *_rand;
	static int _randIndex;

	friend class Game;
};

};