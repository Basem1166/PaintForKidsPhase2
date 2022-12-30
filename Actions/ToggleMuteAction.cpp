#include"ToggleMuteAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ToggleMuteAction::ToggleMuteAction(ApplicationManager* pApp) :Action(pApp)
{}

void ToggleMuteAction::ReadActionParameters(){}

void ToggleMuteAction::Execute(bool WillRecord, string filename, bool where)
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (!WillRecord)
		//This action needs to read some parameters first
		ReadActionParameters();

	//Add the rectangle to the list of figures
	if (pManager->IsMute()==0)
	{
		pOut->PrintMessage("Muted");
	}
	else
	{
		pOut->PrintMessage("Unmuted");
	}

	pManager->ToggleMute();

	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}
}

void ToggleMuteAction::Undo(){}

void ToggleMuteAction::Redo() {}