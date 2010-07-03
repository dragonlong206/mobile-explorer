
#ifndef MOBILEEXPLORER_PAN_H
#define MOBILEEXPLORER_PAN_H

/** MobileExplorer application panic codes */
enum TMobileExplorerPanics
	{
	EMobileExplorerUi = 1
	// add further panics here
	};

inline void Panic(TMobileExplorerPanics aReason)
	{
	_LIT(applicationName,"MobileExplorer");
	User::Panic(applicationName, aReason);
	}

#endif // MOBILEEXPLORER_PAN_H
