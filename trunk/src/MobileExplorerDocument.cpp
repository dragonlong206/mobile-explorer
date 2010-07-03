/*
========================================================================
 Name        : MobileExplorerDocument.cpp
 Author      : Le Van Long
 Copyright   : Your copyright notice
 Description : 
========================================================================
*/
// [[[ begin generated region: do not modify [Generated User Includes]
#include "MobileExplorerDocument.h"
#include "MobileExplorerAppUi.h"
// ]]] end generated region [Generated User Includes]

/**
 * @brief Constructs the document class for the application.
 * @param anApplication the application instance
 */
CMobileExplorerDocument::CMobileExplorerDocument( CEikApplication& anApplication )
	: CAknDocument( anApplication )
	{
	}

/**
 * @brief Completes the second phase of Symbian object construction. 
 * Put initialization code that could leave here.  
 */ 
void CMobileExplorerDocument::ConstructL()
	{
	}
	
/**
 * Symbian OS two-phase constructor.
 *
 * Creates an instance of CMobileExplorerDocument, constructs it, and
 * returns it.
 *
 * @param aApp the application instance
 * @return the new CMobileExplorerDocument
 */
CMobileExplorerDocument* CMobileExplorerDocument::NewL( CEikApplication& aApp )
	{
	CMobileExplorerDocument* self = new ( ELeave ) CMobileExplorerDocument( aApp );
	CleanupStack::PushL( self );
	self->ConstructL();
	CleanupStack::Pop( self );
	return self;
	}

/**
 * @brief Creates the application UI object for this document.
 * @return the new instance
 */	
CEikAppUi* CMobileExplorerDocument::CreateAppUiL()
	{
	return new ( ELeave ) CMobileExplorerAppUi;
	}
				
