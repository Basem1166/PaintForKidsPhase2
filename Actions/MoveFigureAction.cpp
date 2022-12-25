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
	pIn->GetPointClicked(P1.x, P1.y);



	pOut->ClearStatusBar();

}

//Execute the action
void MoveFigureAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* SelectedFig = pManager->GetSelectedFigure();
	SelectedFig->Move(P1.x, P1.y); // Moves Figure to new Center;
	pOut->PrintMessage("Figure Moved");
}
