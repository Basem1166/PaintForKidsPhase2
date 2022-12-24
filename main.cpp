#include "ApplicationManager.h"

//A7A A7ten
int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		AppManager.UpdateInterface();	

	} while(ActType != EXIT);
	
	//testing 11111111 anime 
	//asdsadass
	return 0;
}

