/*
========================================================================
 Name        : MobileExplorerApplication.h
 Author      : Le Van Long
 Copyright   : Your copyright notice
 Description : 
========================================================================
*/
#ifndef MOBILEEXPLORERAPPLICATION_H
#define MOBILEEXPLORERAPPLICATION_H

// [[[ begin generated region: do not modify [Generated Includes]
#include <aknapp.h>
// ]]] end generated region [Generated Includes]

// [[[ begin generated region: do not modify [Generated Constants]
const TUid KUidMobileExplorerApplication = { 0xE86CD648 };
// ]]] end generated region [Generated Constants]

/**
 *
 * @class	CMobileExplorerApplication MobileExplorerApplication.h
 * @brief	A CAknApplication-derived class is required by the S60 application 
 *          framework. It is subclassed to create the application's document 
 *          object.
 */
class CMobileExplorerApplication : public CAknApplication
	{
private:
	TUid AppDllUid() const;
	CApaDocument* CreateDocumentL();
	
	};
			
#endif // MOBILEEXPLORERAPPLICATION_H		
