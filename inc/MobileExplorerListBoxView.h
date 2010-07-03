/*
========================================================================
 Name        : MobileExplorerListBoxView.h
 Author      : Le Van Long
 Copyright   : Your copyright notice
 Description : 
========================================================================
*/
#ifndef MOBILEEXPLORERLISTBOXVIEW_H
#define MOBILEEXPLORERLISTBOXVIEW_H

// [[[ begin generated region: do not modify [Generated Includes]
#include <aknview.h>
// ]]] end generated region [Generated Includes]

#include <aknnotewrappers.h>
// [[[ begin [Event Handler Includes]
// ]]] end [Event Handler Includes]

// [[[ begin generated region: do not modify [Generated Constants]
// ]]] end generated region [Generated Constants]

// [[[ begin generated region: do not modify [Generated Forward Declarations]
class CMobileExplorerListBox;
// ]]] end generated region [Generated Forward Declarations]

/**
 * Avkon view class for MobileExplorerListBoxView. It is register with the view server
 * by the AppUi. It owns the container control.
 * @class	CMobileExplorerListBoxView MobileExplorerListBoxView.h
 */						
			
class CMobileExplorerListBoxView : public CAknView
	{
	
	
	// [[[ begin [Public Section]
public:
	// constructors and destructor
	CMobileExplorerListBoxView();
	static CMobileExplorerListBoxView* NewL();
	static CMobileExplorerListBoxView* NewLC();        
	void ConstructL();
	virtual ~CMobileExplorerListBoxView();
						
	// from base class CAknView
	TUid Id() const;
	void HandleCommandL( TInt aCommand );
	
	// [[[ begin generated region: do not modify [Generated Methods]
	CMobileExplorerListBox* CreateContainerL();
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
	TBool isRootDirectory;
	CEikTextListBox* mainListBox;
	CTextListBoxModel* lbModel;
	
	TBuf<256> currentPath;
	CDesCArraySeg* backQueue;
	CDesCArraySeg* forwardQueue;
	
	void DisplayDrives();
	//void FormatDriveInfo(TDes& listItemText, const TDriveInfo aDriveInfo);
	void FormatVolumeInfo(TDes& listItemText, const TVolumeInfo aVolumeInfo);
	void ShowFileList(const TDesC& fileSpec);
	void OpenFile(const TDesC& filePath);
	void AddToBackQueue(const TDesC& aPath);
	void AddToForwardQueue(const TDesC& aPath);
	
	TBool HandleSelectMenuItemSelectedL( TInt aCommand );
	TBool HandleCopyMenuItemSelectedL( TInt aCommand );
	TBool HandleCutMenuItemSelectedL( TInt aCommand );
	TBool HandlePasteMenuItemSelectedL( TInt aCommand );
	TBool HandleDeleteMenuItemSelectedL( TInt aCommand );
	TBool HandleBackMenuItemSelectedL( TInt aCommand );
	TBool HandleForwardMenuItemSelectedL( TInt aCommand );
	TBool HandleGo_to_RootMenuItemSelectedL( TInt aCommand );
	TBool HandleOptionsMenuItemSelectedL( TInt aCommand );
	void HandleMobileExplorerListBoxViewActivatedL();
	// ]]] end [User Handlers]
	
	// ]]] end [Protected Section]
	
	
	// [[[ begin [Private Section]
private:
	void SetupStatusPaneL();
	void CleanupStatusPane();
	
	// [[[ begin generated region: do not modify [Generated Instance Variables]
	CMobileExplorerListBox* iMobileExplorerListBox;
	// ]]] end generated region [Generated Instance Variables]
	
	// [[[ begin generated region: do not modify [Generated Methods]
	// ]]] end generated region [Generated Methods]
	
	// ]]] end [Private Section]
	
	};

#endif // MOBILEEXPLORERLISTBOXVIEW_H
