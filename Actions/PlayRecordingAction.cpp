#include "PlayRecordingAction.h"
#include "..\ApplicationManager.h"


#include "..\GUI\Output.h"





PlayRecordingAction::PlayRecordingAction(ApplicationManager* pApp) :Action(pApp)
{
}

void PlayRecordingAction::Execute(bool isBeingPlayed, string filename, bool where )
{

	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Playing the Recording");
	CFigure::resetID();
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

PlayRecordingAction::~PlayRecordingAction()
{

}
