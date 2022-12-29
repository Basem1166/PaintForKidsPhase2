#ifndef STOP_RECORD
#define STOP_RECORD

#include "Action.h"

class StopRecordingAction :public Action {

private:

public:

	StopRecordingAction(ApplicationManager* pApp);

	virtual void Execute(bool isBeingPlayed);
	virtual void ReadActionParameters();
	virtual void Undo();

	virtual void Redo();




};









#endif
