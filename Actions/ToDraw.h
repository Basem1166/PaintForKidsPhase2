#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class  ToDraw :public Action
{

public:

	ToDraw(ApplicationManager* pApp);

	~ToDraw(void);

	void ReadActionParameters();
	void Execute();

	void Undo();

	void Redo();
};