#include "StartRecordingAction.h"
#include "..\ApplicationManager.h"


#include "..\GUI\Output.h"


StartRecordingAction::StartRecordingAction(ApplicationManager* pApp):Action(pApp)
{
}

void StartRecordingAction::Execute(bool isBeingPlayed)
{
	Output* pOut = pManager->GetOutput();
	if (pManager->IsEmpty())
	{

		pManager->setWillRecord(1);
		pOut->PrintMessage("Started Recording");
	}
	else
	{
		
		pOut->PrintMessage("Error: Drawing Area is not empty");
	}
}

void StartRecordingAction::ReadActionParameters()
{
}

void StartRecordingAction::Undo()
{
}

void StartRecordingAction::Redo()
{
}
