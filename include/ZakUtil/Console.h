#pragma once

#include <string>
#include <map>
#include <vector>
#include "zakutilapi.h"
#include "messages.h"

#define MAX_CIRCULAR_LIST_SIZE	100

using namespace std;

typedef void(*pointerToFunc)(string);

namespace zak {

/**
 *  Clase que maneja los datos de la consola estilo Quake.
 *	@author Juan Pablo "McKrackeN" Bettini
 */
class ZAKUTIL_API Console {
public:
	static void Initialize();

	/**
	 *  M�todo que elimina los elementos de la consola
	 */
	static void Clear();

	/**
	 *  M�todo que permite logear texto en la consola.
	 *  @param str Cadena de caracteres a ser agregada a la consola.
	 */
	static void Trace(string& str);

	/**
	 *  M�todo que permite logear texto en la consola.
	 *  @param str Cadena de caracteres a ser agregada a la consola con formato estilo printf.
	 */
	static void Trace(const char *str, ...);

	/**
	 *  M�todo que permite leer una l�nea de la consola. 
	 *  Al tratarse de una lista circular, la l�nea ser� eliminada. 
	 *  El m�todo deber� ser invocado si la lista no est� vac�a.
	 *  @see IsEmpty()
	 *  @return Cadena de caracteres de la l�nea.
	 */
	static char* ReadLine();

	/**
	 *  Devuelve si la lista est� vac�a o no.
	 *  @return Devuelve true si la lista est� vac�a y false en caso contrario.
	 */
	static bool IsEmpty() { return (_writeCursor == _readCursor); }

	/**
	 *  Permite ejecutar un comando pasado por par�metro.
	 *  @param input L�nea de comandos a ser ejecutada.
	 *  @return Devuelve true si el comando fue ejecutado con �xito y false en caso contrario.
	 */
	static bool ExecuteCommand(string input);

	/**
	 *  Permite regisrar un nuevo comando con la funci�n que deber� ejecutarse.
	 *  Esta funci�n deber� cumplir con el prototipo: 
	 \code
	 void Funcion (string cadena);
	 \endcode
	 *  @param cmd Comando asignado para ejecutar la funci�n
	 *  @param func Puntero a la funci�n que deber� ser ejecutada al invocarse el comando
	 *  @return Devuelve true si el comando fue registrado con �xito y false en caso contrario.
	 */
	static bool RegisterCommand(string cmd, pointerToFunc func);

	static vector<string>	_lastCommands;
	static int				_lastCmdCursor;

private:
	static map<string, pointerToFunc>	_commands;
	static vector<string>				_vector;
	static string						_buffer[MAX_CIRCULAR_LIST_SIZE];
	static int							_readCursor;
	static int							_writeCursor;

	static void Help(string help);
	static void InsertString (string& str);
};

} // end namespace
