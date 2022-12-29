#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


class SaveAction :public Action
{
	string filename;		//the name of file that we will save data into
	GfxInfo currentGfxInfo; // to get current color and current fill color from gfxinfo
public:

	SaveAction(ApplicationManager* pApp);

	string convertcolorToString(color color);

	~SaveAction(void);

	void ReadActionParameters(); //reads file name and current clr 

	void Execute(bool isBeingPlayed);

	void Undo();

	void Redo();
};
