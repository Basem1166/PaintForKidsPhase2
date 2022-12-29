#ifndef REDO_ACTION_H
#define REDO_ACTION_H

#include "Action.h"

class RedoAction :public Action
{
public:
	RedoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool WillRecord);

	void Undo();

	void Redo();
};
#endif