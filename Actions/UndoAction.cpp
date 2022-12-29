#include "UndoAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{}
void UndoAction::ReadActionParameters()
{}
void UndoAction::Execute(bool isBeingPlayed)
{
	pManager->UndoPrevAction();
	//Add the figure to the recording list if recording;
	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}
}
void UndoAction::Undo()
{

}

void UndoAction::Redo()
{

}