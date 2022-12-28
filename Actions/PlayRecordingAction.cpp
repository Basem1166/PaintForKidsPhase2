#include "PlayRecordingAction.h"
#include "..\ApplicationManager.h"


#include "..\GUI\Output.h"





PlayRecordingAction::PlayRecordingAction(ApplicationManager* pApp):Action(pApp)
{
}

void PlayRecordingAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Playing the Recording");
	pManager->PlayRecording();
}

void PlayRecordingAction::ReadActionParameters()
{
}

void PlayRecordingAction::Undo()
{
}

void PlayRecordingAction::Redo()
{
}
