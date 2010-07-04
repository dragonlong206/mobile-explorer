/*
========================================================================
 Name        : MobileExplorerContainer_AboutView.h
 Author      : Le Van Long
 Copyright   : Your copyright notice
 Description : 
========================================================================
*/
#ifndef MOBILEEXPLORERCONTAINER_ABOUTVIEW_H
#define MOBILEEXPLORERCONTAINER_ABOUTVIEW_H

// [[[ begin generated region: do not modify [Generated Includes]
#include <aknview.h>
// ]]] end generated region [Generated Includes]


// [[[ begin [Event Handler Includes]
// ]]] end [Event Handler Includes]

// [[[ begin generated region: do not modify [Generated Constants]
// ]]] end generated region [Generated Constants]

// [[[ begin generated region: do not modify [Generated Forward Declarations]
class CMobileExplorerContainer_About;
// ]]] end generated region [Generated Forward Declarations]

/**
 * Avkon view class for MobileExplorerContainer_AboutView. It is register with the view server
 * by the AppUi. It owns the container control.
 * @class	CMobileExplorerContainer_AboutView MobileExplorerContainer_AboutView.h
 */						
			
class CMobileExplorerContainer_AboutView : public CAknView
	{
	
	
	// [[[ begin [Public Section]
public:
	// constructors and destructor
	CMobileExplorerContainer_AboutView();
	static CMobileExplorerContainer_AboutView* NewL();
	static CMobileExplorerContainer_AboutView* NewLC();        
	void ConstructL();
	virtual ~CMobileExplorerContainer_AboutView();
						
	// from base class CAknView
	TUid Id() const;
	void HandleCommandL( TInt aCommand );
	
	// [[[ begin generated region: do not modify [Generated Methods]
	CMobileExplorerContainer_About* CreateContainerL();
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
	TBool HandleControlPaneRightSoftKeyPressedL( TInt aCommand );
	// ]]] end [User Handlers]
	
	// ]]] end [Protected Section]
	
	
	// [[[ begin [Private Section]
private:
	void SetupStatusPaneL();
	void CleanupStatusPane();
	
	// [[[ begin generated region: do not modify [Generated Instance Variables]
	CMobileExplorerContainer_About* iMobileExplorerContainer_About;
	// ]]] end generated region [Generated Instance Variables]
	
	// [[[ begin generated region: do not modify [Generated Methods]
	// ]]] end generated region [Generated Methods]
	
	// ]]] end [Private Section]
	
	};

#endif // MOBILEEXPLORERCONTAINER_ABOUTVIEW_H
