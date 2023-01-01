#ifndef MOVE_FIGURE_ACTION_H
#define MOVE_FIGURE_ACTION_H

#include "Action.h"

//Add MoveFigure Action class
class MoveFigureAction : public Action
{
private:
	Point PNew, POld;
	GfxInfo RectGfxInfo;
	bool SelectedFlag;
public:
	MoveFigureAction(ApplicationManager* pApp);

	//Reads move parameters
	virtual void ReadActionParameters();

	//Add new moved shape to the ApplicationManager
	virtual void Execute(bool WillRecord, string filename, bool where = true);

	void Undo();

	void Redo();

	~MoveFigureAction();
};

#endif