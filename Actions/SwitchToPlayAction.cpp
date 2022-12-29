#include "SwitchToPlayAction.h"


#include "..\ApplicationManager.h"


#include "..\GUI\Output.h"

SwitchToPlayAction::SwitchToPlayAction(ApplicationManager* pApp) :Action(pApp)
{
}



void SwitchToPlayAction::Execute(bool isBeingPlayed)
{
	Output* pOut = pManager->GetOutput();
	pOut->CreatePlayToolBar();
}

void SwitchToPlayAction::ReadActionParameters()
{
}

void SwitchToPlayAction::Undo()
{
}

void SwitchToPlayAction::Redo()
{
}