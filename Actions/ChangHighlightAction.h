#ifndef CHANGE_HIGHLIGHT_ACTION_H
#define CHANGE_HIGHLIGHT_ACTION_H

#include "Action.h"
//Add Change Highlight Colour Action class
class ChangeHighlightAction : public Action
{
private:
	ActionType ColorAct; //Changed color
	GfxInfo OldGfxInfo, NewGfxInfo;
public:
	ChangeHighlightAction(ApplicationManager* pApp);
	virtual void Execute();

	virtual void ReadActionParameters();

	bool GetHighlightColour(ActionType);//function for changing the highlight ui color
		
	void Undo();

	void Redo();
};
#endif