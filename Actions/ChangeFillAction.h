#ifndef CHANGE_FILL_ACTION_H
#define CHANGE_FILL_ACTION_H

#include "Action.h"
//Add Change Highlight Colour Action class
class ChangeFillAction : public Action
{
private:
	ActionType ColorAct; //CLICKED COLOR
	GfxInfo OldGfxInfo, NewGfxInfo;

public:
	ChangeFillAction(ApplicationManager* pApp);
	virtual void Execute();

	virtual void ReadActionParameters();

	bool GetFillColour(ActionType);//function for changing the fill ui color

	void Undo();

	void Redo();
};
#endif