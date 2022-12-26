#include "UndoAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{}
void UndoAction::ReadActionParameters()
{}
void UndoAction::Execute()
{
	pManager->UndoPrevAction();
}