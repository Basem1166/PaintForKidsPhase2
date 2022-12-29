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

	pOut->PrintMessage("Moving Selected Figure: Click on new center");

	//Read new center and store in point P1
	pIn->GetPointClicked(PNew.x, PNew.y);



	pOut->ClearStatusBar();

}

//Execute the action
void MoveFigureAction::Execute(bool isBeingPlayed)
{
	if(!isBeingPlayed)
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	FigPtr = pManager->GetSelectedFigure();
	POld = FigPtr->GetCenter();
	FigPtr->Move(PNew.x, PNew.y); // Moves Figure to new Center;
	pOut->PrintMessage("Figure Moved");
	//Add the figure to the recording list if recording;
	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}
}

void MoveFigureAction::Undo()
{
	FigPtr->Move(POld.x, POld.y);
}
void MoveFigureAction::Redo()
{
	FigPtr->Move(PNew.x, PNew.y);
}