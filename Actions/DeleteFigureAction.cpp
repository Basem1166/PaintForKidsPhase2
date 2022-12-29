#include "DeleteFigureAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) :Action(pApp)
{}
void DeleteFigureAction::ReadActionParameters()
{
	FigPtr = pManager->GetSelectedFigure();
}

//Execute the action
void DeleteFigureAction::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();

	//Delete  selected  figure

	pManager->DeleteFigure(FigPtr);
	pOut->PrintMessage("Figure Deleted");
}
void DeleteFigureAction::Undo()
{
	pManager->AddFigure(FigPtr);
	FigPtr->SetSelected(false);
}

void DeleteFigureAction::Redo()
{
	pManager->DeleteFigure(FigPtr);
	FigPtr->SetSelected(false);
}