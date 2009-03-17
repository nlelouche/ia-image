#ifndef _Game_H_
#define _Game_H_

#include <windows.h>
#include <iostream>
#include <sstream>
#include "Defines.h"
#include "renderer.h"
#include "FPSMeter.h"
#include "ZakUtil/window.h"		// solo para conocer el hWnd que necesita
#include "Input.h"
#include "TextureManager.h"
#include "ZakUtil/Messages.h"
#include "CPUInfo.h"
#include "ZakUtil/Console.h"
#include "GameConfig.h"
#include "Sprite.h"
#include "IsoSprite.h"
#include "IsoMap.h"
#include "Shape.h"
#include "Entity2D.h"
#include "Font.h"
#include "Map.h"
#include "Particle.h"

using namespace std;

namespace zak {

/**
 *	Clase que encapsula la inicializaci�n, el bucle principal y el apagado del motor.
 *	Ejemplo de uso:
\code
// main.cpp
#include "game.h"

using namespace zak;

//#define USING_DIRECTX81

#ifdef USING_DIRECTX81

#ifdef _DEBUG
#pragma comment (lib, "zakengine81d.lib")
#else
#pragma comment (lib, "zakengine81.lib")
#endif

#else

#ifdef _DEBUG
#pragma comment (lib, "zakengined.lib")
#else
#pragma comment (lib, "zakengine.lib")
#endif

#endif

int main () {
	string desc;
	TestGame game;
	GameConfig config;

	if (!config.Load("config.ini"))
		return false;

	if (game.StartUp(&config)) {
		game.Loop();
	} else {
		game.Shutdown();

		MessageBoxA(g_window.GetHWnd(),Log.GetLastMessage(),"Error",MB_ICONERROR|MB_OK);

		return 1;
	}

	if (!game.Shutdown()) {

		MessageBoxA(g_window.GetHWnd(),Log.GetLastMessage(),"Error",MB_ICONERROR|MB_OK);
		return 1;
	}
	
	return 0;
}
\endcode

\code
// game.h
#pragma once

#include <sstream>
#include "zakengine/zak.h"

using namespace zak;

class TestGame : public Game {
public:

	void OnFrame();
	bool OnShutdown();
	bool OnInit();
	void OnDraw();


	TestGame();
	~TestGame();

private:

};
\endcode

\code
// game.cpp
#include "game.h"

TestGame::TestGame() {

}

TestGame::~TestGame() { 

}
bool TestGame::OnInit() {

	_clearScreen = true;

	return true;
}

void TestGame::OnFrame() {
	if (KeyDown(DIK_ESCAPE))
		PostQuitMessage(0);
}

void TestGame::OnDraw() {
	wstringstream ss;

	ss << ZAK_ENGINE_NAME << endl << "FPS: " << _fpsMeter.GetFps() << endl;
	g_renderer.SetFontColor(0xFFFF0000);
	g_renderer.DrawString(ss.str(),10,10,800-20,600-20,ZAK_TEXT_LEFT);
}

bool TestGame::OnShutdown() {
	return true;
}
\endcode

 *	@author Juan Pablo "McKrackeN" Bettini
 */
class ZAKENGINE_API Game {
	private:
		MSG _msg;
		CPUInfo		_CPUInfo;

		int		_width;
		int		_height;
		int		_bits;
		bool	_fullScreen;
		int		_refreshRate;
		bool	_vsync;

	protected:
		STCPUInfo	_stCPUInfo;
		FPSMeter	_fpsMeter;
		bool		_clearScreen;
		GameConfig	*_config;

	public:

		/**
		*	M�todo virtual puro invocado luego de haberse inicializado correctamente el motor.
		*	@return Debemos retornar verdadero si todo sali� correctamente y falso en caso contrario.
		*/
		virtual bool OnInit()=0;

		/**
		*	M�todo virtual puro invocado antes de apagar el motor.
		*	@return Debemos retornar verdadero si todo sali� correctamente y falso en caso contrario.
		*/
		virtual bool OnShutdown()=0;

		/**
		*	M�todo virtual puro invocado durante el bucle principal antes de dibujar la escena. 
		*	Aqu� actualizaremos las variables, chequearemos los dispositivos de entrada, etc.
		*/
		virtual void OnFrame()=0;

		/**
		*	M�todo virtual puro invocado durante el bucle principal en el momento de dibujar la escena.
		*	Aqu� llamaremos a los m�todos correspondientes al dibujado de los elementos correspondientes.
		*/
		virtual void OnDraw(){}

		/**
		*	M�todo invocado cuando se pierde el dispositivo ante un ALT+TAB en pantalla completa o por alg�n error.
		*/
		virtual void OnLostDevice(){}

		/**
		*	M�todo invocado cuando reinicia el dispositivo de Direct3D luego de perderlo ante un ALT+TAB.
		*/
		virtual void OnResetDevice(){}


		/**
		*	M�todo que debemos invocar para inicializar la aplicaci�n. 
		*	Se encargar� de crear la ventana, inicializar DirectX, inicializar el sonido, etc. y luego invocar� al m�todo OnInit.
		*/
		bool StartUp (GameConfig *config = NULL);

		/**
		*	M�todo que correr� el bucle principal.
		*	Se encargar� de llamar a los m�todos OnFrame y OnDraw respectivamente.
		*/
		void Loop();

		/**
		*	M�todo que apagar� la aplicaci�n.
		*	Se encargar� de invocar al m�todo OnShutdown y de apagar correctamente el motor.
		*/
		bool Shutdown();

		bool ChangeResolution(int width, int height, int bits, bool fullScreen, int refreshRate, bool vsync);
		bool ChangeResolution(GameConfig *config);

	/**
	*	Constructor.
	*/
	Game(){}
};

}

#endif
