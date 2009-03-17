#pragma once

#include "widgets.h"
#include "wdgeditbox.h"

#define MAX_CONSOLE_LINES		20 
#define CONSOLE_HEIGHT			300

namespace zak {

class ZAKENGINE_API WdgConsoleEdit : public WdgEditBox {
public:

	void OnReturn();

	WdgConsoleEdit(){}
	~WdgConsoleEdit(){}
private:
};

/**
 *  Clase que define un widget estilo consola tipo Quake
 *  Ejemplo de uso:
\code
// game.h
#pragma once

#include <sstream>
#include "ZakEngine/zak.h"

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

	WdgConsole	_console;
	WidgetMgr	_wdgMgr;
};
\endcode

\code
#include "game.h"

TestGame::TestGame() {
}

TestGame::~TestGame() { 

}
bool TestGame::OnInit() {
		
	_console.Initialize();
	_console.SetColor(0x80000000);
	_console.SetFont(FT_COURIER,15);
	_console.SetFontColor(0xFF00FF00);
	_console.SetEditColor(0xA0000000);
	_console.SetEditFontColor(0xFF00FF00);
	_console.SetEditFont(FT_COURIER,15);
	_console.SetHeight(300);

	_clearScreen = true;

	g_renderer.SetFont(FT_TAHOMA, 15);
	g_renderer.SetFontColor(0xFFFF0000);

	return true;
}

void TestGame::OnFrame() {

	if (KeyPressed(DIK_ESCAPE)) 
		PostQuitMessage(0);

	if (KeyDown(DIK_GRAVE)) {
		if (_wdgMgr.IsAttached(_console))
			_wdgMgr.Detach(_console);
		else
			_wdgMgr.Attach(_console);
	}


	_wdgMgr.Update((float)_fpsMeter.GetDT());
}

void TestGame::OnDraw() {
	wstringstream ss;

	ss << ZAK_ENGINE_NAME << endl << "FPS: " << _fpsMeter.GetFps() << endl;

	_wdgMgr.Draw();

	g_renderer.DrawString(ss.str(),10,10,800-20,600-20,ZAK_TEXT_LEFT|ZAK_TEXT_BOTTOM);
}

bool TestGame::OnShutdown() {
	_wdgMgr.DetachAll();

	ScriptMgr::ClearScriptList();

	return true;
}

\endcode
 *  @author Juan Pablo "McKrackeN" Bettini
 */
class ZAKENGINE_API WdgConsole : public Widget {

public:
	/**
	 *  Inicializa el widget
	 *  @return Retorna true si todo salió bien y false en caso contrario
	 */
	bool Initialize();

	/**
	 *  Muestra el widget en pantalla
	 */
	void Draw();

	/**
	 *  Actualiza el widget
	 *  @param dt Intervalo de tiempo entre iteraciones del bucle principal
	 */
	void Update(float dt);

	/**
	 *  Permite indicar el color de la caja de texto de la consola
	 *  @param color Color de la caja de texto
	 */
	void SetEditColor(DWORD color) { _edit.SetColor(color); }

	/**
	 *  Permite indicar el color del texto de la caja de texto de la consola
	 *  @param color Color del texto
	 */
	void SetEditFontColor(DWORD color) { _edit.SetFontColor(color); }

	/**
	 *  Permite indicar la fuente de la caja de texto de la consola
	 *  @param ft Tipo de fuente
	 *  @param size Tamaño de la fuente
	 */
	void SetEditFont(ZAK_FONT_TYPES ft, int size=15);

	void OnFocus() { _edit.OnFocus(); this->OnFocusLostInternal(); }
	void OnFocusLost() { _edit.OnFocusLost(); }

	/**
	 *  Constructor
	 */
	WdgConsole();

	/**
	 *  Destructor
	 */
	~WdgConsole();

private:
	string			_text;
	WdgConsoleEdit	_edit;
};

}