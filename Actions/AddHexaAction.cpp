#include "AddHexaAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexaAction::AddHexaAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at Center");

	//Read Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);



	HexaGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}
//Execute
void AddHexaAction::Execute(bool isBeingPlayed)
{
	if (!isBeingPlayed)
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}
	//Create a hexagon with the parameters read from the user

	FigPtr = new CHexagon(P1, HexaGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(FigPtr);

	
	
	
	
	//Add the figure to the recording list if recording;
	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}

}
void AddHexaAction::Undo()
{
	pManager->DeleteFigure(FigPtr);
	FigPtr->SetSelected(false);
}

void AddHexaAction::Redo()
{
	pManager->AddFigure(FigPtr);
	FigPtr->SetSelected(false);
}