/*
========================================================================
 Name        : MobileExplorerContainerView.h
 Author      : Le Van Long
 Copyright   : Your copyright notice
 Description : 
========================================================================
*/
#ifndef MOBILEEXPLORERCONTAINERVIEW_H
#define MOBILEEXPLORERCONTAINERVIEW_H

// [[[ begin generated region: do not modify [Generated Includes]
#include <aknview.h>
// ]]] end generated region [Generated Includes]


// [[[ begin [Event Handler Includes]
// ]]] end [Event Handler Includes]

// [[[ begin generated region: do not modify [Generated Constants]
// ]]] end generated region [Generated Constants]

// [[[ begin generated region: do not modify [Generated Forward Declarations]
class CMobileExplorerContainer;
// ]]] end generated region [Generated Forward Declarations]

/**
 * Avkon view class for MobileExplorerContainerView. It is register with the view server
 * by the AppUi. It owns the container control.
 * @class	CMobileExplorerContainerView MobileExplorerContainerView.h
 */						
			
class CMobileExplorerContainerView : public CAknView
	{
	
	
	// [[[ begin [Public Section]
public:
	// constructors and destructor
	CMobileExplorerContainerView();
	static CMobileExplorerContainerView* NewL();
	static CMobileExplorerContainerView* NewLC();        
	void ConstructL();
	virtual ~CMobileExplorerContainerView();
						
	// from base class CAknView
	TUid Id() const;
	void HandleCommandL( TInt aCommand );
	
	// [[[ begin generated region: do not modify [Generated Methods]
	CMobileExplorerContainer* CreateContainerL();
	// ]]] end generated region [Generated Methods]
	
	// ]]] end [Public Section]
	
	
	// [[[ begin [Protected Section]
protected:
	// from base class CAknView
	void DoActivateL(
		const TVwsViewId& aPrevViewId,
		TUid aCustomMessageId,
		const TDesC8& aCustomMessage );
	void DoDeactivate();
	void HandleStatusPaneSizeChange();
	
	// [[[ begin generated region: do not modify [Overridden Methods]
	// ]]] end generated region [Overridden Methods]
	
	
	// [[[ begin [User Handlers]
	void HandleMobileExplorerContainerViewDeactivated();
	TBool HandleControlPaneRightSoftKeyPressedL( TInt aCommand );
	void HandleMobileExplorerContainerViewActivatedL();
	// ]]] end [User Handlers]
	
	// ]]] end [Protected Section]
	
	
	// [[[ begin [Private Section]
private:
	void SetupStatusPaneL();
	void CleanupStatusPane();
	
	// [[[ begin generated region: do not modify [Generated Instance Variables]
	CMobileExplorerContainer* iMobileExplorerContainer;
	// ]]] end generated region [Generated Instance Variables]
	
	// [[[ begin generated region: do not modify [Generated Methods]
	// ]]] end generated region [Generated Methods]
	
	// ]]] end [Private Section]
	
	};

#endif // MOBILEEXPLORERCONTAINERVIEW_H
