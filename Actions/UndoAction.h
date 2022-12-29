#ifndef UNDO_ACTION_H
#define UNDO_ACTION_H

#include "Action.h"

class UndoAction :public Action
{
public:
	UndoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool WillRecord);

	void Undo();

	void Redo();
};
#endif