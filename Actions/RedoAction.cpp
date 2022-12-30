#include "RedoAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp)
{}
void RedoAction::ReadActionParameters()
{}
void RedoAction::Execute(bool WillRecord, string filename, bool where )
{
	pManager->RedoPrevAction();
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