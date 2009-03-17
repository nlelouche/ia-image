#pragma once

// Windows headers
#include <windows.h>
#include <mmreg.h>

// DirectX headers
#include <dsound.h>

#include <string>

// Project headers
#include "sound.h"				// representa un buffer de ds
#include "zakengine/zak.h"		// lista enlazada

namespace zak
{

// Cantidad de milisegundos durante el cual duermo el thread
// en cada iteración
#define SLEEP_THREAD_TIME				250

class SOUND_API SoundMgr
{
public:
	enum eType { WAV, VORBIS, UNKNOWN };
	enum eTypeSndMus { MUSIC, SOUND};
	//SoundManager();
	//~SoundManager();

	// -----------------------------------------------
	// Inicializa subsistema
	static bool Startup();
	// -----------------------------------------------
	// Apaga subsistema
	static void Shutdown();
	// -----------------------------------------------
	// Crea un buffer y retorna un puntero a él
	static Sound * openSound(const char * pFilename, bool streaming, bool loop, eTypeSndMus sndMus=SOUND, eType type=UNKNOWN);
	// -----------------------------------------------
	// Destruye el buffer
	static bool closeSound(Sound * pSound);
	// -----------------------------------------------
	// Función invocada en cada iteración del thread
	static void Frame();

	/**
	 *  Permite indicar si el sonido está activo o no
	 *  @param active indicar si el sonido está activo o no
	 */
	static void setSoundActive(bool active) { _active = active; Sound::_active = active; }

	/**
	 *  Devuelve si el sonido está activo o no
	 *  @return devuelve true si el sonido está activo o false en caso contrario
	 */
	static bool getSoundActive() { return _active; }

	/**
	 *  Permite indicar el volumen global para todos los sonidos
	 *  @param volume volumen global de los sonidos (entre 0.0f y 1.0f)
	 */
	static void	setGlobalVolume(float volume);

	/**
	 *  Devuelve el volumen global para todos los sonidos
	 *  @return devuelve el volumen global de los sonidos (entre 0.0f y 1.0f)
	 */
	static float getGlobalVolume() { return _globalVolume; }

	/**
	 *  Permite indicar el volumen para los efectos sonoros
	 *  @param volume volumen de los sonidos (entre 0.0f y 1.0f)
	 */
	static void	setSoundVolume(float volume);

	/**
	 *  Devuelve el volumen de los efectos sonoros
	 *  @return devuelve el volumen de los efectos sonoros (entre 0.0f y 1.0f)
	 */
	static float getSoundVolume() { return _soundVolume; }

	/**
	 *  Permite indicar el volumen para la música
	 *  @param volume volumen de la música (entre 0.0f y 1.0f)
	 */
	static void	setMusicVolume(float volume);

	/**
	 *  Devuelve el volumen de la música
	 *  @return devuelve el volumen de la música (entre 0.0f y 1.0f)
	 */
	static float getMusicVolume() { return _musicVolume; }


protected:
	static LPDIRECTSOUND8 _pDS;
	
	// Lista enlazada de objetos sound para realizar streaming
	static List<Sound *> _streamingSoundObjectsList;
	// Lista enlazada de objetos sound de buffers estáticos
	static List<Sound *> _staticSoundObjectsList;

	// Thread info
	static HANDLE _hThread;
	static unsigned long _threadId;

	static bool _active;
	static List<Sound*> _musicList;
	static List<Sound*> _sndList;
	static float _soundVolume;
	static float _musicVolume;
	static float _globalVolume;


	friend class Sound;


public:
	static volatile bool _exitThread;

};


} // end namespace

