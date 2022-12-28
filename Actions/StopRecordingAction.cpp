#include "StopRecordingAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"

StopRecordingAction::StopRecordingAction(ApplicationManager* pApp):Action(pApp)
{
}

void StopRecordingAction::Execute()
{
	pManager->StartRecording(0);
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Stopped Recording");

}

void StopRecordingAction::ReadActionParameters()
{
}

void StopRecordingAction::Undo()
{
}

void StopRecordingAction::Redo()
{
}
