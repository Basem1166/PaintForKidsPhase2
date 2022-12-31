#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"
#include "..\Figures\CFigure.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	CFigure* FigPtr;
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute(bool WillRecord, string filename, bool where = true) =0;

	virtual void Undo() = 0;

	virtual void Redo() = 0;

	virtual ~Action() {};
};

#endif