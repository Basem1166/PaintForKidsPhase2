#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

//BASSEMMMMMMMMMMMMMMMMMM#1

class SaveAction :public Action
{
	string filename;
	GfxInfo currentGfxInfo; // to get current color and current fill color from gfxinfo
public:

	SaveAction(ApplicationManager* pApp);
	string convertcolorToString(color color);
	~SaveAction(void);

	void ReadActionParameters(); //reads file name and current clr 

	void Execute();
};

