#pragma once

#include "widgets.h"
#include "wdgeditbox.h"
#include "wdgconsole.h"

namespace zak {

/**
 *  Clase que manejará los widgets
 *  @author Juan Pablo "McKrackeN" Bettini
 */
class ZAKENGINE_API WidgetMgr {

public:

	/**
	 *  Constructor
	 */
	WidgetMgr();

	/**
	 *  Destructor
	 */
	virtual ~WidgetMgr();

	/**
	 *  Muestra los widgets que se encuentren adjuntos al manager
	 */
	void Draw();

	/**
	 *  Actualiza los widgets que se encuentran adjuntos al manager
	 *  @param dt Intervalo de tiempo entre iteraciones del bucle principal
	 */
	void Update(float dt);

	/**
	 *  Permite poner en foco un widget en particular.
	 *  @param widget Referencia al widget que deseamos poner en foco.
	 *  @return Devuelve false en caso de que el widget no se encuentre adjunto al manager
	 */
	bool SetFocus(Widget &widget);

	/**
	 *  Devuelve si un widget en particular está ajunto o no al manager
	 *  @param widget Referencia al widget en particular
	 *  @return Devuelve true en caso de encontrarse adjunto y false en caso contrario
	 */
	bool IsAttached(Widget &widget);

	/**
	 *  Adjunta un widget al manager
	 *  @param widget Referencia al widget que se desea adjuntar
	 *  @return Devuelve true si pudo ser adjuntado y false en caso contrario
	 */
	bool Attach(Widget &widget);

	/**
	 *  Desprende un widget del manager
	 *  @param widget Referencia al widget que se desea desprender
	 *  @return Devuelve true si pudo ser desprendido y false en caso contrario
	 */
	bool Detach(Widget &widget);

	/**
	 *  Desprende todos los widgets del manager
	 */
	void DetachAll();

	void ReleaseAll();
	void ResetAll();

private:
	List<Widget*> _widgets;

	Widget *_focused;
	Widget *_dragging;

	bool _dragged;
};

}