#ifndef MOVE_FIGURE_ACTION_H
#define MOVE_FIGURE_ACTION_H

#include "Action.h"

//Add MoveFigure Action class
class MoveFigureAction : public Action
{
private:
	Point P1;
	GfxInfo RectGfxInfo;
public:
	MoveFigureAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif