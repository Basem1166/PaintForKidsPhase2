#ifndef Toggle_Mute_ACTION_H
#define Toggle_Mute_ACTION_H

#include "Action.h"

class ToggleMuteAction :public Action
{
public:
	ToggleMuteAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool WillRecord, string filename, bool where = true);

	void Undo();

	void Redo();

	~ToggleMuteAction();
};

#endif