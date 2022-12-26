#ifndef ADD_HEXA_ACTION_H
#define ADD_HEXA_ACTION_H

#include "Action.h"
#include "..\Figures\CHexagon.h"
//Add Hexagon Action class
class AddHexaAction : public Action
{
private:
	Point P1; //Hexagon center
	GfxInfo HexaGfxInfo;
	CHexagon* Hexagon;
	int ID;
public:
	AddHexaAction(ApplicationManager* pApp);

	//Reads hexagon parameters
	virtual void ReadActionParameters();

	//Add hexagon to the ApplicationManager
	virtual void Execute();

	void Undo();

	void Redo();
};

#endif