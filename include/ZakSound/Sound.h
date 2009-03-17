#pragma once

#include <windows.h>
// Windows headers
#include <mmreg.h>

// DirectX headers
#include <dsound.h>
#include "zakengine/zak.h"

// Project headers
#include "IAudioLoader.h"

namespace zak
{

class SOUND_API Sound 
{
public:
	~Sound();

	// -----------------------------------------------
	// Comienza la reproducci�n del sonido
	bool play();
	// -----------------------------------------------
	// Detienen la reproducci�n del sonido
	void stop();
	// -----------------------------------------------
	// Pausa el sonido
	void pause();
	// -----------------------------------------------
	// Indica si el sonido est� siendo ejecutado
	bool isPlaying();
	// -----------------------------------------------
	// Fija el volumen
	void setVolume(float val)
	{
		EnterCriticalSection(&_csHandler);
		if (val > 0)
			val = val*5000 -5000;
		else
			val = DSBVOLUME_MIN;

		_pDsBuffer->SetVolume((long)(val));
		LeaveCriticalSection(&_csHandler);
	}
	// -----------------------------------------------
	// Retorna el volumen
	float getVolume()
	{
		EnterCriticalSection(&_csHandler);
		static long val;
		static float ret;
		_pDsBuffer->GetVolume(&val);
		LeaveCriticalSection(&_csHandler);
		ret = float((float)(val + 5000)/5000.0f);
		return ret;
	}
	// -----------------------------------------------
	// Fija el pan
	void setPan(long val)
	{
		EnterCriticalSection(&_csHandler);
		_pDsBuffer->SetPan(val);
		LeaveCriticalSection(&_csHandler);
	}
	// -----------------------------------------------
	// Retorna el pan
	long getPan()
	{
		EnterCriticalSection(&_csHandler);
		static long val;
		_pDsBuffer->GetPan(&val);
		LeaveCriticalSection(&_csHandler);
		return val;
	}
	// -----------------------------------------------
	// Fija la posici�n del cursor de reproducci�n
	void setPosition(unsigned long pos)
	{
		EnterCriticalSection(&_csHandler);
		_pDsBuffer->SetCurrentPosition(pos);
		LeaveCriticalSection(&_csHandler);
	}
	// -----------------------------------------------
	// Retorna la posici�n de reproducci�n
	unsigned long getPosition()
	{
		EnterCriticalSection(&_csHandler);

		static unsigned long playCursor;
		static unsigned long writeCursor;

		_pDsBuffer->GetCurrentPosition(&playCursor, &writeCursor);
		
		LeaveCriticalSection(&_csHandler);

		return playCursor;
	}
	// -----------------------------------------------
	// Fija frecuencia
	void setFrequency(unsigned long val)
	{ 
		EnterCriticalSection(&_csHandler);
		_pDsBuffer->SetFrequency(val);
		LeaveCriticalSection(&_csHandler);
	}
	// -----------------------------------------------
	// Retorna frecuencia
	unsigned long getFrequency()
	{
		EnterCriticalSection(&_csHandler);
		static unsigned long val;
		_pDsBuffer->GetFrequency(&val);
		LeaveCriticalSection(&_csHandler);
		return val;
	}
	// -----------------------------------------------
	// Fija que la canci�n se encuentre en bucle
	void setLooped(bool val) { _looped = val; }
	bool getLooped() const { return _looped; }

private:

	Sound(LPDIRECTSOUNDBUFFER8 pBuffer, IAudioLoader * pLoader, bool streaming=false, bool looped=false);

	// -----------------------------------------------
	// Reseteo el buffer
	void Reset();
	// -----------------------------------------------
	// Retorna un puntero al buffer
	LPDIRECTSOUNDBUFFER8 GetBuffer() { return _pDsBuffer; }
	// -----------------------------------------------
	// Retorna puntero al loader
	IAudioLoader * GetLoader() { return _pLoader;	}
	// -----------------------------------------------
	// Actualiza el buffer con informaci�n del loader
	void UpdateBuffer();
	// -----------------------------------------------
	// Indica si el buffer requiere actualizaci�n
	bool NeedUpdate();

	// Buffer
	LPDIRECTSOUNDBUFFER8 _pDsBuffer;
	// Cargador por el medio de cual obtengo las muestras PCM
	IAudioLoader * _pLoader;
	// Buffer temporal utilizado para volcar informaci�n
	// desde el loader al buffer de ds
	char * _pBuffer;

	// Indica si la canci�n se debe ejecutar en bucle
	bool _looped;
	// Indica si se alcanz� el fin de archivo
	bool _eof;
	// Indica si se est� realizando streaming con el buffer
	bool _streaming;

	// Critical Section
	CRITICAL_SECTION _csHandler;
	// Indica en donde debo escribir del buffer
	unsigned int _dataCursor;
	// Tama�o del buffer
	unsigned int _bufferSize;

	static bool _active;

	friend class SoundMgr;

};

} // end namespace
