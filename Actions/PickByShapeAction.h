#ifndef PICK_BY_SHAPE
#define PICK_BY_SHAPE
#include "..\Figures\CFigure.h"
#include "Action.h"

class PickByShapeAction :
	public Action
{
	Point P;
	int NumberOfFiguresOnScreen;

public:
	PickByShapeAction(ApplicationManager*);
	~PickByShapeAction();
	void ReadActionParameters();
	void Execute(bool WillRecord, string filename, bool where);
	void Undo();
	void Redo();

};


#endif
