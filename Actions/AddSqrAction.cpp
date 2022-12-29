#include "AddSqrAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSqrAction::AddSqrAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSqrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at Center");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	SqrGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SqrGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSqrAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a square with the parameters read from the user
	FigPtr = new CSquare(P1, SqrGfxInfo);

	//Add the Square to the list of figures
	pManager->AddFigure(FigPtr);
}

void AddSqrAction::Undo()
{
	pManager->DeleteFigure(FigPtr);
	FigPtr->SetSelected(false);
}

void AddSqrAction::Redo()
{
	pManager->AddFigure(FigPtr);
	FigPtr->SetSelected(false);
}