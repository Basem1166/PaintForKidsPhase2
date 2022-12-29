#ifndef PLAY_RECORD
#define PLAY_RECORD

#include "Action.h"

class PlayRecordingAction :public Action {

private:

public:

	PlayRecordingAction(ApplicationManager* pApp);

	virtual void Execute(bool isBeingPlayed);
	virtual void ReadActionParameters();
	virtual void Undo();

	virtual void Redo();




};









#endif

