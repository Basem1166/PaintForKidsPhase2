#include "DeleteFigureAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) :Action(pApp)
{}
void DeleteFigureAction::ReadActionParameters()
{}

//Execute the action
void DeleteFigureAction::Execute(bool isBeingPlayed)
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Delete  selected  figure
	pManager->DeleteFigure();

	pOut->PrintMessage("Deleted Figure");
	//Add the figure to the recording list if recording;
	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}
}
void DeleteFigureAction::Undo()
{

}

void DeleteFigureAction::Redo()
{

}