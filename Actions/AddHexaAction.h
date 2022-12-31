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
public:
	AddHexaAction(ApplicationManager* pApp);

	//Reads hexagon parameters
	virtual void ReadActionParameters();

	//Add hexagon to the ApplicationManager
	virtual void Execute(bool WillRecord, string filename, bool where = true);

	void Undo();

	void Redo();

	~AddHexaAction();
};

#endif