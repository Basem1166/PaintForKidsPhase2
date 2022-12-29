#include "SwitchToPlayAction.h"


#include "..\ApplicationManager.h"
#include <fstream>

#include "..\GUI\Output.h"

SwitchToPlayAction::SwitchToPlayAction(ApplicationManager* pApp) :Action(pApp)
{
}



void SwitchToPlayAction::Execute(bool WillRecord)
{

	ofstream outputFile;
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