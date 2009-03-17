#pragma once

// Project headers
#include "IAudioLoader.h"

// Ogg Vorbis
#include "vorbis/codec.h"
#include "vorbis/vorbisfile.h"

namespace zak
{

class SOUND_API VorbisAudio : public IAudioLoader
{
public:
	VorbisAudio();
	~VorbisAudio();

	// Abre el archivo
	bool Open(const char * pFilename);
	// Cierra el archivo
	void Close();
	// Lee una porción del archivo
	void Read(char * pBuffer, unsigned int * pLen);

	// Retorna cantidad de muestras pcm
	long GetSampleCount() const { return _numSamples; }

	// Retorna puntero a estructura de información de archivo
	WAVEFORMATEX * GetWaveFormat() { return &_waveFormatEx; }

	// Retorna tamaño de archivo (descomprimido)
	unsigned int GetSize() const;

	// Indica si se encuentra en fin de archivo
	bool IsEof() const { return _eof;	}
	// Reset
	void Reset();
private:
	// Retorna información sobre el archivo
	void GetStreamInfo();

	// Estructura que representa el archivo vorbis
	OggVorbis_File _vorbisFile;
	// Estructura de información del archivo abierto
	WAVEFORMATEX _waveFormatEx;
	// Indica si el archivo fue abierto correctamente
	bool _isOpen;
	// Indica si se está en el fin de archivo
	bool _eof;
	// Puntero a archivo
	FILE * _pFile;
	// Cantidad de muestras
	long _numSamples;
};

} // end namespace

