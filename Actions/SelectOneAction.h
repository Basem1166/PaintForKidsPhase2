#ifndef ADD_SelectOneAction_H
#define ADD_SelectOneAction_H

#include "Action.h"


//Add Select One Action class
class SelectOneAction : public Action
{
private:
	Point P;
public:
	SelectOneAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	void Undo();
	void Redo();
};

#endif