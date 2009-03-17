#pragma once

// Project headers
#include "IAudioLoader.h"

// Win32 headers
#include <windows.h>
#include <mmsystem.h>
#include <mmreg.h>
#include <msacm.h>

// C/C++ headers
#include <cstdio>
using namespace std;

namespace zak
{

class SOUND_API WavAudio : public IAudioLoader
{
public:
	WavAudio();
	~WavAudio();
	
	// -----------------------------------------------
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

	bool OpenMMIO();
	bool ReadMMIO();
	bool PrepareACMBuffers(unsigned int & dataIn, unsigned int& streamRead, unsigned int sizeToRead);
	bool DecompressData(unsigned int dataIn, BYTE* pDestBuffer, unsigned int sizeToRead, DWORD* pSizeRead);

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

	// Wav specific
	static unsigned int	_waveCount;

	// MM I/O handle for the WAVE
	HMMIO _hmmio;
	// Multimedia RIFF chunk
	MMCKINFO _ck;
	// Use in opening a WAVE file
	MMCKINFO _ckRiff;
	// The size of the wave file
	unsigned int _size;

	// Estructuras específicas de ACM
	WAVEFORMATEX * _pwfx;
	HACMSTREAM _hACMStream;
	unsigned char *	_pCompressBuffer;
	unsigned int _compressBufferSize;
	unsigned char *	_pDecompressBuffer;
	unsigned int _decompressStart;
	unsigned int _decompressEnd;
	unsigned int _decompressBufferSize;
};

} // end namespace
