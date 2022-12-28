#ifndef TO_PLAY_H
#define TO_PLAY_H

#include "Action.h"

class SwitchToPlayAction :public Action {

private:

public:

	SwitchToPlayAction(ApplicationManager* pApp);
	
	virtual void Execute();
	virtual void ReadActionParameters();
	virtual void Undo();

	virtual void Redo();




};









#endif