#include "PlayRecordingAction.h"
#include "..\ApplicationManager.h"


#include "..\GUI\Output.h"





PlayRecordingAction::PlayRecordingAction(ApplicationManager* pApp) :Action(pApp)
{
}

void PlayRecordingAction::Execute(bool isBeingPlayed, string filename, bool where )
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetRecordingListCount() == 0) {
		pOut->PrintMessage("No Recording to Be Played!");
		return;
	}
	if (pManager->getWillRecord())
	{
		pOut->PrintMessage("Cannot Play Recording While Recording!");
		return;
	}
	
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
