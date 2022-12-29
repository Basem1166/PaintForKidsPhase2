#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute(bool isBeingPlayed)
{
	if (!isBeingPlayed)
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}
	//Create a rectangle with the parameters read from the user
	FigPtr = new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures

	pManager->AddFigure(FigPtr);

	//Add the figure to the recording list if recording;
	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}

}

void AddRectAction::Undo()
{
	pManager->DeleteFigure(FigPtr);
	FigPtr->SetSelected(false);
}

void AddRectAction::Redo()
{
	pManager->AddFigure(FigPtr);
	FigPtr->SetSelected(false);
}