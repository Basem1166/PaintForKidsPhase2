#include "MoveFigureAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

MoveFigureAction::MoveFigureAction(ApplicationManager* pApp) :Action(pApp)
{}

void MoveFigureAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	FigPtr = pManager->GetSelectedFigure();
	pOut->ClearStatusBar();

}

//Execute the action
void MoveFigureAction::Execute(bool WillRecord, string filename, bool where )
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (!WillRecord)
	{
		ReadActionParameters();
	}
	if (FigPtr == NULL)
	{
		pOut->PrintMessage("Error! Please Select a figure first");
		return;
	}
	pOut->PrintMessage("Moving Selected Figure: Click on new center");

	//Read new center and store in point P1
	pIn->GetPointClicked(PNew.x, PNew.y);
	POld = FigPtr->GetCenter();
	FigPtr->Move(PNew.x, PNew.y); // Moves Figure to new Center;
	pOut->PrintMessage("Figure Moved");
	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}
	pManager->AddActionToUndoList(this);
}

void MoveFigureAction::Undo()
{
	FigPtr->Move(POld.x, POld.y);
}
void MoveFigureAction::Redo()
{
	FigPtr->Move(PNew.x, PNew.y);
}

MoveFigureAction::~MoveFigureAction()
{

}