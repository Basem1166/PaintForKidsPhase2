#include "RedoAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp)
{}
void RedoAction::ReadActionParameters()
{}
void RedoAction::Execute(bool isBeingPlayed)
{
	pManager->RedoPrevAction();
	//Add the figure to the recording list if recording;
	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}
}
void RedoAction::Undo()
{

}

void RedoAction::Redo()
{

}