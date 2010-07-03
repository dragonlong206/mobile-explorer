/*
========================================================================
 Name        : MobileExplorerListBox.h
 Author      : Le Van Long
 Copyright   : Your copyright notice
 Description : 
========================================================================
*/
#ifndef MOBILEEXPLORERLISTBOX_H
#define MOBILEEXPLORERLISTBOX_H

// [[[ begin generated region: do not modify [Generated Includes]
#include <coecntrl.h>		
#include <akniconutils.h>
#include <gulicon.h>
// ]]] end generated region [Generated Includes]


// [[[ begin [Event Handler Includes]
// ]]] end [Event Handler Includes]

// [[[ begin generated region: do not modify [Generated Forward Declarations]
class MEikCommandObserver;		
class CAknSingleGraphicStyleListBox;
class CEikTextListBox;
// ]]] end generated region [Generated Forward Declarations]

/**
 * Container class for MobileExplorerListBox
 * 
 * @class	CMobileExplorerListBox MobileExplorerListBox.h
 */
class CMobileExplorerListBox : public CCoeControl
	{
public:
	// constructors and destructor
	CMobileExplorerListBox();
	static CMobileExplorerListBox* NewL( 
		const TRect& aRect, 
		const CCoeControl* aParent, 
		MEikCommandObserver* aCommandObserver );
	static CMobileExplorerListBox* NewLC( 
		const TRect& aRect, 
		const CCoeControl* aParent, 
		MEikCommandObserver* aCommandObserver );
	void ConstructL( 
		const TRect& aRect, 
		const CCoeControl* aParent, 
		MEikCommandObserver* aCommandObserver );
	virtual ~CMobileExplorerListBox();

public:
	// from base class CCoeControl
	TInt CountComponentControls() const;
	CCoeControl* ComponentControl( TInt aIndex ) const;
	TKeyResponse OfferKeyEventL( 
			const TKeyEvent& aKeyEvent, 
			TEventCode aType );
	void HandleResourceChange( TInt aType );
	
protected:
	// from base class CCoeControl
	void SizeChanged();

private:
	// from base class CCoeControl
	void Draw( const TRect& aRect ) const;

private:
	void InitializeControlsL();
	void LayoutControls();
	CCoeControl* iFocusControl;
	MEikCommandObserver* iCommandObserver;
	// [[[ begin generated region: do not modify [Generated Methods]
public: 
	static void AddListBoxItemL( 
			CEikTextListBox* aListBox,
			const TDesC& aString );
	static RArray< TInt >* GetSelectedListBoxItemsLC( CEikTextListBox* aListBox );
	static void DeleteSelectedListBoxItemsL( CEikTextListBox* aListBox );
	CAknSingleGraphicStyleListBox* ListBox();
	static void CreateListBoxItemL( TDes& aBuffer, 
			TInt aIconIndex,
			const TDesC& aMainText );
	void AddListBoxResourceArrayItemL( TInt aResourceId, TInt aIconIndex );
	void SetupListBoxIconsL();
	static CGulIcon* LoadAndScaleIconL(
			const TDesC& aFileName,
			TInt aBitmapId,
			TInt aMaskId,
			TSize* aSize,
			TScaleMode aScaleMode );
	TBool HandleMarkableListCommandL( TInt aCommand );
	// ]]] end generated region [Generated Methods]
	
	// [[[ begin generated region: do not modify [Generated Type Declarations]
public: 
	// ]]] end generated region [Generated Type Declarations]
	
	// [[[ begin generated region: do not modify [Generated Instance Variables]
private: 
	CAknSingleGraphicStyleListBox* iListBox;
	// ]]] end generated region [Generated Instance Variables]
	
	
	// [[[ begin [Overridden Methods]
protected: 
	// ]]] end [Overridden Methods]
	
	
	// [[[ begin [User Handlers]
protected: 
	// ]]] end [User Handlers]
	
public: 
	enum TControls
		{
		// [[[ begin generated region: do not modify [Generated Contents]
		EListBox,
		
		// ]]] end generated region [Generated Contents]
		
		// add any user-defined entries here...
		
		ELastControl
		};
	enum TListBoxImages
		{
		// [[[ begin generated region: do not modify [Generated Enums]
		EListBoxMobileexplorerDrive_iconIndex = 0,
		EListBoxMobileexplorerFolder_iconIndex = 1,
		EListBoxMobileexplorerFileIndex = 2,
		EListBoxFirstUserImageIndex
		
		// ]]] end generated region [Generated Enums]
		
		};
	};
				
#endif // MOBILEEXPLORERLISTBOX_H
