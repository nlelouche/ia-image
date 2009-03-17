#pragma once

#include "widgets.h"

namespace zak {

/**
 *  Clase que define un widget estilo EditBox (caja de edición de texto)
 *  @author Juan Pablo "McKrackeN" Bettini
 */
class ZAKENGINE_API WdgEditBox : public Widget {
public:
	/**
	 *  Devuelve una cadena de caracteres con el texto que contiene la caja de texto
	 *  @return Cadena de caracteres
	 */
	string GetText() { return _string; } 

	/**
	 *  Permite indicar el texto que muestra la caja de texto
	 *  @param str Cadena de caracteres
	 */
	void SetText(string str);

	/**
	 *  Muestra el widget en pantalla
	 */
	virtual void Draw();

	/**
	 *  Actualiza el widget
	 *  @param dt Intervalo de tiempo entre iteraciones del bucle principal
	 */
	virtual void Update(float dt);

	virtual void OnFocus() {
		OnFocusInternal();
	}
	virtual void OnFocusLost() {
		OnFocusLostInternal();
	}

	/**
	 *  Constructor
	 */
	WdgEditBox();

protected:

	void OnFocusInternal();
	void OnFocusLostInternal();
	void OnClickInternal();

private:
	float		_timeAccum;
	bool		_blink;

	bool		_canEnter;
	bool		_blinked;
	bool		_inserting;
	bool		_textinput;
	int			_lastElement;
	int			_maxElement;
	int			_cursor;
	int			_return;
	int			_blinking;
	string		_string;
	basic_string <char>::iterator _iter;

};

}