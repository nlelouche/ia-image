#pragma once

#include <sstream>
#include "ZakUtil/console.h"
#include "renderer.h"
#include "sprite.h"
#include "ZakUtil/list.h"
#include "defines.h"

#define WIDGET_NONE				0
#define WIDGET_ROLLOVER			1
#define WIDGET_ROLLOUT			2
#define WIDGET_CLICK			3
#define WIDGET_PRESS			4
#define WIDGET_DBLCLICK			5
#define WIDGET_FOCUS			6
#define WIDGET_FOCUSLOST		7
#define WIDGET_DRAG				8
#define WIDGET_STOPDRAG			9
#define WIDGET_RETURN			10

#define WIDGET_DBLCLICK_DELAY	150

#define WIDGET_BLINK_DELAY		500

namespace zak {

class ZAKENGINE_API WidgetMgr;

/**
 *  Clase que define el esqueleto de los widgets con sus eventos
 *	Ejemplo de uso:
\code
\endcode

 *	@author Juan Pablo "McKrackeN" Bettini
 */
class ZAKENGINE_API Widget : public Sprite { 

public:
	/**
	 *  Método virtual que debe invocarse al crearse un widget. Además puede ser sobrecargado.
	 *  @return Devolverá true en el caso de que todo haya salido bien y false en caso contrario
	 */
	virtual bool Initialize();

	/**
	 *  Método virtual invocado cuando el widget toma el foco
	 */
	virtual void OnFocus() { }

	/**
	 *  Método virtual invocado cuando el widget pierde el foco
	 */
	virtual void OnFocusLost() {}

	/**
	 *  Método virtual invocado cuando el usuario hace click con el botón izquierdo del mouse sobre el widget
	 */
	virtual void OnClick() {}

	/**
	 *  Método virtual invocado cuando el usuario mantiene presionado el botón izquierdo del mouse sobre el widget
	 */
	virtual void OnPress() {}

	/**
	 *  Método virtual invocado cuando el usuario hace doble click con el botón izquierdo del mouse sobre el widget
	 */
	virtual void OnDoubleClick() {}

	/**
	 *  Método virtual invocado cuando el mouse pasa por sobre el widget
	 */
	virtual void OnRollOver() {}

	/**
	 *  Método virtual invocado cuando el mouse escapa de la zona del widget
	 */
	virtual void OnRollOut() {}

	/**
	 *  Método virtual invocado cuando el usuario trata de arrastrar el widget.
	 *  Debe estar activado el arrastre para el widget, sino el evento será ignorado.
	 */
	virtual void OnDrag() { }

	/**
	 *  Método virtual invocado si el usuario arrastra un widget sobre éste y lo suelta. 
	 *  @param widget Puntero al widget que está siendo arrastrado
	 */
	virtual void OnDropIn(Widget *widget) {}

	/**
	 *  Método virtual invocado si el usuario arrastra este widget y lo suelta sobre otro. 
	 *  @param widget Puntero al widget que donde lo está colocando
	 */
	virtual void OnDropOut(Widget *widget) {}

	/**
	 *  Método virtual invocado si se presiona enter mientras el widget está en foco
	 */
	virtual void OnReturn() {}

	/**
	 *  El método crea una fuente de sistema según los parámetros pasados´.
	 *  @param ft Tipo de fuente.
	 *  @param size Tamaño de la fuente.
	 *  @return Retorna true si fue posible crear la fuente y false en caso contrario
	 */
	bool SetFont(ZAK_FONT_TYPES ft, int size=15);

	/**
	 *  El método permite indicar el color de la fuente.
	 *  @param color Color de la fuente.
	 */
	void SetFontColor(unsigned int color) { _color = color; }

	/**
	 *  Devuelve el alto de la fuente.
	 *  @return Retorna un número entero que indica el alto de la fuente
	 */
	int GetFontHeight() { return _size; }

	/**
	 *  Devuelve el tipo de fuente actualmente seleccionada.
	 *  @return Retorna el tipo de fuente seleccionada actualmente.
	 */
	ZAK_FONT_TYPES GetFont();

	/**
	 *  Adjunta un widget al actual
	 *  @return Retorna true en caso de haber podido adjuntar el widget y false en caso contrario
	 */
	bool Attach(Widget &widget);

	/**
	 *  Desprende un widget al actual
	 *  @return Retorna true en caso de haber podido desprender el widget y false en caso contrario
	 */
	bool Detach(Widget &widget);

	/**
	 *  Desprende todos los widgets del actual
	 */
	void DetachAll();

	/**
	 *  Método virtual que muestra el widget
	 */
	virtual void Draw();

	/**
	 *  Método virtual que actualiza el widget
	 */
	virtual void Update(float dt);

	/**
	 *  Devuelve si el widget está en foco o no
	 *  @return Devuelve true en caso de estar en foco y false en caso contrario.
	 */
	bool GetFocused() { return _isFocused; } 

	/**
	 *  Permite indicar la posición relativa al widget que contiene al actual.
	 *  @param x Componente x de la posición relativa 
	 */
	void SetRelPosX(float x) { _relPosX = x; }

	/**
	 *  Permite indicar la posición relativa al widget que contiene al actual.
	 *  @param y Componente y de la posición relativa 
	 */
	void SetRelPosY(float y) { _relPosY = y; }

	/**
	 *  Permite indicar la posición relativa al widget que contiene al actual.
	 *  @param x Componente x de la posición relativa 
	 *  @param y Componente y de la posición relativa 
	 */
	void SetRelPos (float x, float y) { _relPosX = x; _relPosY = y; }

	/**
	 *  Devuelve la posición relativa al widget que contiene al actual.
	 *  @return Componente x de la posición relativa 
	 */
	float GetRelPosX() { return _relPosX; }

	/**
	 *  Devuelve la posición relativa al widget que contiene al actual.
	 *  @return Componente y de la posición relativa 
	 */
	float GetRelPosY() { return _relPosY; }

	/**
	 *  Indica si el widget puede arrastrarse
	 *  @param dragable Indica si el widget puede arrastrarse
	 */
	void SetDragable(bool dragable) { _dragable = dragable; }

	/**
	 *  Devuelve si el widget puede arrastrarse
	 *  @return Devuelve si el widget puede arrastrarse
	 */
	bool GetDragable() { return _dragable; }
	
	/**
	 *  Permite activar o desactivar el widget. En caso de estar desactivado, se mostrará pero no recibirá eventos.
	 *  @param enable Indica si está activado o no
	 */
	void SetEnable(bool enable) { _enable = enable; }

	/**
	 *  Devuelve si el widget se encuentra activado o no.
	 *  @return Devuelve si está activado o no
	 */
	bool GetEnable() { return _enable; }

	/**
	 *  Permite indicar el intervalo entre clicks para ser tomado como un doble click (en milisegundos)
	 *  @param dblClickDelay Número flotante que indica el intervalo de tiempo en milisegundos entre clicks
	 */
	void SetDoubleClickDelay(float dblClickDelay) { _dblClickDelay = dblClickDelay; }

	/**
	 *  Devuelve el intervalo entre clicks para ser tomado como un doble click (en milisegundos)
	 *  @return Número flotante que indica el intervalo de tiempo en milisegundos entre clicks
	 */
	float GetDoubleClickDelay() { return _dblClickDelay; } 

	/**
	 *  Constructor
	 */
	Widget();

	/**
	 *  Destructor
	 */
	virtual ~Widget();

protected:
	virtual void OnFocusInternal() { _isFocused = true; }
	virtual void OnFocusLostInternal() {_isFocused = false;  }
	virtual void OnClickInternal() {}

	void DrawString(string &text, float x, float y, float w, float h, unsigned int align=ZAK_TEXT_LEFT);
	void DrawString(wstring &text, float x, float y, float w, float h, unsigned int align=ZAK_TEXT_LEFT);
	void DrawString(char* text, float x, float y, float w, float h, unsigned int align=ZAK_TEXT_LEFT);

	Widget *DoEvents(int &event);

	Widget *GetParent() { return _parent; }
	WidgetMgr *GetMgr() { return _mgr; }

	void Release();
	void Reset();  

	ID3DXFont		*_pDefDXFont;
	Widget			*_parent;
	WidgetMgr		*_mgr;
	bool			_editing;
	unsigned int	_color;
	int				_size;


private:
	bool CheckRollOver() {
		static float x1;
		static float y1;
		static float width;
		static float height;
		static float x2;
		static float y2;
		static float xv, yv;

		width	= GetCollisionWidth();
		height	= GetCollisionHeight();
		x1		= GetPosX()-width*0.5f+GetPivotPosX();
		y1		= GetPosY()-height*0.5f+GetPivotPosY();

		g_renderer.GetViewPosition(xv, yv);

		x2 = MouseAbsPosf(ZAK_INPUT_MOUSE_POS_X)+xv;
		y2 = MouseAbsPosf(ZAK_INPUT_MOUSE_POS_Y)+yv;

		if (x2 > x1 && x2 < x1+width && y2 > y1 && y2 < y1+height) {
			return true;
		}

		return false;
	}	

	List<Widget*>	_widgets;

	float			_relPosX;
	float			_relPosY;

	bool			_mouseOver;
	bool			_dragging;
	
	bool			_dragable;
	bool			_enable;

	float			_dblClickDelay;
	float			_accumTime;

	bool			_isFocused;
	bool			_mouseClick;

	ZAK_FONT_TYPES	_pDefDXFontType;

	friend class WidgetMgr;
	friend class Widget;
};

}