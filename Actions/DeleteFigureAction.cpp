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
void DeleteFigureAction::Execute(bool WillRecord, string filename, bool where )
{
	//Get a Pointer to the Input / Output Interfaces
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
	pManager->DeleteFigure(FigPtr); //Delete  selected  figure
	pOut->PrintMessage("Figure Deleted");
	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}
	pManager->AddActionToUndoList(this);
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