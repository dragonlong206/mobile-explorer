/*
========================================================================
 Name        : MobileExplorerAppUi.h
 Author      : Le Van Long
 Copyright   : Your copyright notice
 Description : 
========================================================================
*/
#ifndef MOBILEEXPLORERAPPUI_H
#define MOBILEEXPLORERAPPUI_H

// [[[ begin generated region: do not modify [Generated Includes]
#include <aknviewappui.h>
// ]]] end generated region [Generated Includes]

// [[[ begin generated region: do not modify [Generated Forward Declarations]
class CMobileExplorerListBoxView;
class CMobileExplorerContainerView;
class CMobileExplorerContainer_AboutView;
// ]]] end generated region [Generated Forward Declarations]

/**
 * @class	CMobileExplorerAppUi MobileExplorerAppUi.h
 * @brief The AppUi class handles application-wide aspects of the user interface, including
 *        view management and the default menu, control pane, and status pane.
 */
class CMobileExplorerAppUi : public CAknViewAppUi
	{
public: 
	// constructor and destructor
	CMobileExplorerAppUi();
	virtual ~CMobileExplorerAppUi();
	void ConstructL();

public:
	// from CCoeAppUi
	TKeyResponse HandleKeyEventL(
				const TKeyEvent& aKeyEvent,
				TEventCode aType );

	// from CEikAppUi
	void HandleCommandL( TInt aCommand );
	void HandleResourceChangeL( TInt aType );

	// from CAknAppUi
	void HandleViewDeactivation( 
			const TVwsViewId& aViewIdToBeDeactivated, 
			const TVwsViewId& aNewlyActivatedViewId );

private:
	void InitializeContainersL();
	// [[[ begin generated region: do not modify [Generated Methods]
public: 
	// ]]] end generated region [Generated Methods]
	
	// [[[ begin generated region: do not modify [Generated Instance Variables]
private: 
	CMobileExplorerListBoxView* iMobileExplorerListBoxView;
	CMobileExplorerContainerView* iMobileExplorerContainerView;
	CMobileExplorerContainer_AboutView* iMobileExplorerContainer_AboutView;
	// ]]] end generated region [Generated Instance Variables]
	
	
	// [[[ begin [User Handlers]
protected: 
	// ]]] end [User Handlers]
public:
	RBuf iFileText;
	RBuf iLabelText;
	TBuf<256> iCurrentPath;
	};

#endif // MOBILEEXPLORERAPPUI_H			
