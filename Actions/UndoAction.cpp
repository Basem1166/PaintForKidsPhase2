#include "UndoAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{}
void UndoAction::ReadActionParameters()
{}
void UndoAction::Execute(bool WillRecord, string filename, bool where )
{
	pManager->UndoPrevAction();
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

UndoAction::~UndoAction()
{

}