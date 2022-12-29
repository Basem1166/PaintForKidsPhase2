#ifndef DELETE_FIGURE_ACTION_H
#define DELETE_FIGURE_ACTION_H

#include "Action.h"

//Delete Figure Action class
class DeleteFigureAction : public Action
{
public:
	DeleteFigureAction(ApplicationManager* pApp);

	void ReadActionParameters();

	//Delete selected figure from FigList ApplicationManager
	virtual void Execute(bool WillRecord);

	void Undo();

	void Redo();
};

#endif