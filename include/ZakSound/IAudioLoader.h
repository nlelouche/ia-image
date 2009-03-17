#pragma once

// Windows headers
#include <windows.h>
#include <mmreg.h>


#ifdef ZAKSOUND_EXPORTS
#define SOUND_API __declspec(dllexport)
#else
#define SOUND_API __declspec(dllimport)
#endif // ZAKNETWORK_EXPORTS

namespace zak
{

class SOUND_API IAudioLoader
{
public:
	virtual ~IAudioLoader() {}

	// Abre el archivo
	virtual bool Open(const char * pFilename) = 0;

	// Cierra el archivo
	virtual void Close() = 0;

	// Lee una porción del archivo
	virtual void Read(char * pBuffer, unsigned int * pLen) = 0;

	// Retorna cantidad de muestras pcm
	virtual long GetSampleCount() const = 0;

	// Retorna puntero a estructura de información de archivo
	virtual WAVEFORMATEX * GetWaveFormat() = 0;

	// Retorna tamaño de archivo (descomprimido)
	virtual unsigned int GetSize() const = 0;

	// Indica si se encuentra en fin de archivo
	virtual bool IsEof() const = 0;

	// Reset
	virtual void Reset() = 0;
};

} // end namespace
