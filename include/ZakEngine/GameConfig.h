#pragma once

#include <string.h>

#include "defines.h"
#include "ZakUtil/configfile.h"
#include "ZakUtil/messages.h"
#include "ZakUtil/FileLog.h"

namespace zak {

/**
 *  Clase que permite manejar la configuraci�n del juego.
 *	@author Juan Pablo "McKrackeN" Bettini
 */
class ZAKENGINE_API GameConfig {
public:
	/**
	 *  Permite cargar la configuraci�n a trav�s de un archivo .ini. 
	 *  En caso de que el archivo no exista, intenta crear uno nuevo.
	 *	@param filename Nombre del archivo
	 *  @return Devuelve true si pudo ser cargado satisfactoriamente y false en caso contrario
	 */
	bool Load(char *filename);

	/**
	 *  Permite guardar la configuraci�n en un archivo .ini
	 *	@param filename Nombre del archivo
	 *  @return Devuelve true si pudo ser guardado satisfactoriamente y false en caso contrario
	 */
	bool Save(char *filename);

	/**
	 *  Permite indicar el idioma
	 *	@param language Cadena de caracteres que indica el idioma con el que trabajaremos
	 */
	void SetLanguage(char *language);

	/**
	 *  Permite indicar el t�tulo de la ventana
	 *	@param caption T�tulo de la ventana
	 */
	void SetCaption(char *caption);

	/**
	 *  Permite indicar el ancho de la ventana
	 *	@param width Ancho de la ventana
	 */
	void SetWidth(int width);

	/**
	 *  Permite indicar el alto de la ventana
	 *	@param height Alto de la ventana
	 */
	void SetHeight(int height);

	/**
	 *  Permite indicar los bits por p�xel
	 *	@param bits Bits por p�xel
	 */
	void SetBits(int bits);

	/**
	 *  Permite indicar la velocidad de refresco
	 *	@param refreshRate Velocidad de refresco 
	 */
	void SetRefreshRate(int refreshrate);

	/**
	 *  Permite indicar si deseamos congelar los cuadros por segundo
	 *	@param lockFPS Cantidad de cuadros por segundo a los que deseamos que corra la aplicaci�n
	 */
	void SetLockFPS (int lockFPS);

	/**
	 *  Permite indicar si deseamos que el juego corra a pantalla completa o no
	 *	@param fullscreen Si indicamos true, el juego correr� a pantalla completa.
	 */
	void SetFullscren(bool fullscreen);

	/**
	 *  Permite indicar si deseamos activar la sincronizaci�n vertical 
	 *	@param vsync Si indicamos true, activaremos la sincronizaci�n vertical
	 */
	void SetVSync(bool vsync);

	/**
	 *  Permite indicar si deseamos que el cursor est� visible o no
	 *	@param cursorVisible Si indicamos true, veremos el cursor de windows en pantalla
	 */
	void SetCursorVisible(bool cursorVisible);

	/**
	 *  Permite indicar si deseamos activar el sonido
	 *	@param sound Si indicamos true, activaremos el sonido.
	 */
	void SetSound(bool sound);

	/**
	 *  Devuelve el idioma
	 *	@return Cadena de caracteres que indica el idioma con el que trabajaremos
	 */
	const char *GetLanguage()	{ return _language; }

	/**
	 *  Devuelve el t�tulo de la ventana
	 *	@return T�tulo de la ventana
	 */
	const char *GetCaption()	{ return _caption; }

	/**
	 *  Devuelve el ancho de la ventana
	 *	@return Ancho de la ventana
	 */
	int GetWidth()				{ return _width; }

	/**
	 *  Devuelve el alto de la ventana
	 *	@return Alto de la ventana
	 */
	int GetHeight()				{ return _height; }

	/**
	 *  Devuelve los bits por p�xel
	 *	@return Bits por p�xel
	 */
	int	GetBits()				{ return _bits; }

	/**
	 *  Devuelve los cuadros por segundo a los que est� bloqueado. 
	 *  En caso de devolver cero significa que no estar� bloqueado.
	 *	@return Cantidad de cuadros por segundo a los que deseamos que corra la aplicaci�n
	 */
	int	GetLockFPS()			{ return _lockFPS; }

	/**
	 *  Devuelve la velocidad de refresco
	 *	@return Velocidad de refresco 
	 */
	int GetRefreshRate()		{ return _refreshRate; }

	/**
	 *  Devuelve si la aplicaci�n corre a pantalla completa o no.
	 *	@return Si devuelve true, el juego estar� corriendo a pantalla completa.
	 */
	bool GetFullscreen()		{ return _fullscreen; }

	/**
	 *  Devuelve si est� activada la sincronizaci�n vertical
	 *	@return Devuelve true en caso de que est� activada la sincronizaci�n vertical y false en caso contrario.
	 */
	bool GetVSync()				{ return _vsync; }

	/**
	 *  Devuelve si el cursor de windows est� visible
	 *	@return Devuelve true en caso de que el cursor de windows est� visible y false en caso contrario.
	 */
	bool GetCursorVisible()		{ return _cursorVisible; }

	/**
	 *  Devuelve si el sonido est� activado
	 *	@return Devuelve true en caso de que el sonido est� activado y false en caso contrario.
	 */
	bool GetSound()				{ return _sound; }

	GameConfig();
	~GameConfig();

private:
	char	_language[100];
	char	_caption[100];
	int		_width;
	int		_height;
	int		_bits;
	bool	_fullscreen;
	bool	_vsync;
	int		_refreshRate;
	int		_lockFPS;
	bool	_sound;
	bool	_cursorVisible;
};


} // end namespace

