/*
========================================================================
 Name        : MobileExplorerListBoxView.cpp
 Author      : Le Van Long
 Copyright   : Your copyright notice
 Description : 
========================================================================
*/
// [[[ begin generated region: do not modify [Generated System Includes]
#include <aknviewappui.h>
#include <eikmenub.h>
#include <avkon.hrh>
#include <barsread.h>
#include <stringloader.h>
#include <aknlists.h>
#include <eikenv.h>
#include <akniconarray.h>
#include <eikclbd.h>
#include <akncontext.h>
#include <akntitle.h>
#include <eikbtgpc.h>
#include <MobileExplorer.rsg>
// ]]] end generated region [Generated System Includes]

// [[[ begin generated region: do not modify [Generated User Includes]

#include "MobileExplorer.hrh"
#include "MobileExplorerListBoxView.h"
#include "MobileExplorerListBox.hrh"
#include "MobileExplorerListBox.h"
// ]]] end generated region [Generated User Includes]

// [[[ begin generated region: do not modify [Generated Constants]
// ]]] end generated region [Generated Constants]

/**
 * First phase of Symbian two-phase construction. Should not contain any
 * code that could leave.
 */
CMobileExplorerListBoxView::CMobileExplorerListBoxView()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	iMobileExplorerListBox = NULL;
	// ]]] end generated region [Generated Contents]
	isRootDirectory = ETrue;	
	currentPath.Copy(_L(""));
	}

/** 
 * The view's destructor removes the container from the control
 * stack and destroys it.
 */
CMobileExplorerListBoxView::~CMobileExplorerListBoxView()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	delete iMobileExplorerListBox;
	iMobileExplorerListBox = NULL;
	// ]]] end generated region [Generated Contents]
	delete mainListBox;
	mainListBox = NULL;
	delete lbModel;
	lbModel = NULL;
	backQueue->Reset();
	delete backQueue;
	backQueue = NULL;
	forwardQueue->Reset();
	delete forwardQueue;
	forwardQueue = NULL;
	}

/**
 * Symbian two-phase constructor.
 * This creates an instance then calls the second-phase constructor
 * without leaving the instance on the cleanup stack.
 * @return new instance of CMobileExplorerListBoxView
 */
CMobileExplorerListBoxView* CMobileExplorerListBoxView::NewL()
	{
	CMobileExplorerListBoxView* self = CMobileExplorerListBoxView::NewLC();
	CleanupStack::Pop( self );
	return self;
	}

/**
 * Symbian two-phase constructor.
 * This creates an instance, pushes it on the cleanup stack,
 * then calls the second-phase constructor.
 * @return new instance of CMobileExplorerListBoxView
 */
CMobileExplorerListBoxView* CMobileExplorerListBoxView::NewLC()
	{
	CMobileExplorerListBoxView* self = new ( ELeave ) CMobileExplorerListBoxView();
	CleanupStack::PushL( self );
	self->ConstructL();
	return self;
	}


/**
 * Second-phase constructor for view.  
 * Initialize contents from resource.
 */ 
void CMobileExplorerListBoxView::ConstructL()
	{
	// [[[ begin generated region: do not modify [Generated Code]
	BaseConstructL( R_MOBILE_EXPLORER_LIST_BOX_MOBILE_EXPLORER_LIST_BOX_VIEW );
				
	// ]]] end generated region [Generated Code]
	
	// add your own initialization code here
	backQueue = new(ELeave) CDesCArraySeg(8);
	forwardQueue = new(ELeave) CDesCArraySeg(8);
	}

/**
 * @return The UID for this view
 */
TUid CMobileExplorerListBoxView::Id() const
	{
	return TUid::Uid( EMobileExplorerListBoxViewId );
	}

/**
 * Handle a command for this view (override)
 * @param aCommand command id to be handled
 */
void CMobileExplorerListBoxView::HandleCommandL( TInt aCommand )
	{
	// [[[ begin generated region: do not modify [Generated Code]
	TBool commandHandled = EFalse;
	switch ( aCommand )
		{	// code to dispatch to the AknView's menu and CBA commands is generated here
		case EMobileExplorerListBoxViewSelectMenuItemCommand:
			commandHandled = HandleSelectMenuItemSelectedL( aCommand );
			break;
		case EMobileExplorerListBoxViewCopyMenuItemCommand:
			commandHandled = HandleCopyMenuItemSelectedL( aCommand );
			break;
		case EMobileExplorerListBoxViewCutMenuItemCommand:
			commandHandled = HandleCutMenuItemSelectedL( aCommand );
			break;
		case EMobileExplorerListBoxViewPasteMenuItemCommand:
			commandHandled = HandlePasteMenuItemSelectedL( aCommand );
			break;
		case EMobileExplorerListBoxViewDeleteMenuItemCommand:
			commandHandled = HandleDeleteMenuItemSelectedL( aCommand );
			break;
		case EMobileExplorerListBoxViewBackMenuItemCommand:
			commandHandled = HandleBackMenuItemSelectedL( aCommand );
			break;
		case EMobileExplorerListBoxViewForwardMenuItemCommand:
			commandHandled = HandleForwardMenuItemSelectedL( aCommand );
			break;
		case EMobileExplorerListBoxViewGo_to_RootMenuItemCommand:
			commandHandled = HandleGo_to_RootMenuItemSelectedL( aCommand );
			break;
		case EMobileExplorerListBoxViewOptionsMenuItemCommand:
			commandHandled = HandleOptionsMenuItemSelectedL( aCommand );
			break;
		default:
			break;
		}
	
		
	if ( !commandHandled ) 
		{
	
		if ( aCommand == EAknSoftkeyExit )
			{
			AppUi()->HandleCommandL( EEikCmdExit );
			}
	
		}
	// ]]] end generated region [Generated Code]
	
	}

/**
 *	Handles user actions during activation of the view, 
 *	such as initializing the content.
 */
void CMobileExplorerListBoxView::DoActivateL( 
		const TVwsViewId& /*aPrevViewId*/,
		TUid /*aCustomMessageId*/,
		const TDesC8& /*aCustomMessage*/ )
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	SetupStatusPaneL();
	
				
				
	
	if ( iMobileExplorerListBox == NULL )
		{
		iMobileExplorerListBox = CreateContainerL();
		iMobileExplorerListBox->SetMopParent( this );
		AppUi()->AddToStackL( *this, iMobileExplorerListBox );
		} 
	HandleMobileExplorerListBoxViewActivatedL();
	// ]]] end generated region [Generated Contents]
	
	}

/**
 */
void CMobileExplorerListBoxView::DoDeactivate()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	CleanupStatusPane();
	
	if ( iMobileExplorerListBox != NULL )
		{
		AppUi()->RemoveFromViewStack( *this, iMobileExplorerListBox );
		delete iMobileExplorerListBox;
		iMobileExplorerListBox = NULL;
		}
	// ]]] end generated region [Generated Contents]
	
	}

/** 
 * Handle status pane size change for this view (override)
 */
void CMobileExplorerListBoxView::HandleStatusPaneSizeChange()
	{
	CAknView::HandleStatusPaneSizeChange();
	
	// this may fail, but we're not able to propagate exceptions here
	TVwsViewId view;
	AppUi()->GetActiveViewId( view );
	if ( view.iViewUid == Id() )
		{
		TInt result;
		TRAP( result, SetupStatusPaneL() );
		}
	
	// [[[ begin generated region: do not modify [Generated Code]
	// ]]] end generated region [Generated Code]
	
	}

// [[[ begin generated function: do not modify
void CMobileExplorerListBoxView::SetupStatusPaneL()
	{
	// reset the context pane
	TUid contextPaneUid = TUid::Uid( EEikStatusPaneUidContext );
	CEikStatusPaneBase::TPaneCapabilities subPaneContext = 
		StatusPane()->PaneCapabilities( contextPaneUid );
	if ( subPaneContext.IsPresent() && subPaneContext.IsAppOwned() )
		{
		CAknContextPane* context = static_cast< CAknContextPane* > ( 
			StatusPane()->ControlL( contextPaneUid ) );
		context->SetPictureToDefaultL();
		}
	
	// setup the title pane
	TUid titlePaneUid = TUid::Uid( EEikStatusPaneUidTitle );
	CEikStatusPaneBase::TPaneCapabilities subPaneTitle = 
		StatusPane()->PaneCapabilities( titlePaneUid );
	if ( subPaneTitle.IsPresent() && subPaneTitle.IsAppOwned() )
		{
		CAknTitlePane* title = static_cast< CAknTitlePane* >( 
			StatusPane()->ControlL( titlePaneUid ) );
		TResourceReader reader;
		iEikonEnv->CreateResourceReaderLC( reader, R_MOBILE_EXPLORER_LIST_BOX_TITLE_RESOURCE );
		title->SetFromResourceL( reader );
		CleanupStack::PopAndDestroy(); // reader internal state
		}
				
	}

// ]]] end generated function

// [[[ begin generated function: do not modify
void CMobileExplorerListBoxView::CleanupStatusPane()
	{
	}

// ]]] end generated function

/**
 *	Creates the top-level container for the view.  You may modify this method's
 *	contents and the CMobileExplorerListBox::NewL() signature as needed to initialize the
 *	container, but the signature for this method is fixed.
 *	@return new initialized instance of CMobileExplorerListBox
 */
CMobileExplorerListBox* CMobileExplorerListBoxView::CreateContainerL()
	{
	return CMobileExplorerListBox::NewL( ClientRect(), NULL, this );
	}

/** 
 * Handle the selected event.
 * @param aCommand the command id invoked
 * @return ETrue if the command was handled, EFalse if not
 */
TBool CMobileExplorerListBoxView::HandleSelectMenuItemSelectedL( TInt aCommand )
	{
	// TODO: implement selected event handler
	TInt selectedIndex = mainListBox->CurrentItemIndex();
		
	if (selectedIndex >= 0)
		{
		TPtrC temp = lbModel->ItemText(selectedIndex);
		TPtrC itemText = temp.Right(temp.Length() - 2);
		TBuf<256> fileSpec;
		if (isRootDirectory == 0)
			{
			fileSpec.Copy(currentPath);
			fileSpec.Append(_L("\\"));
			fileSpec.Append(itemText);			
			}
		else
			{
			TPtrC driveOffset = itemText.Left(2);
			fileSpec.Copy(driveOffset);
			}
		
		RFs fsSession;
		User::LeaveIfError(fsSession.Connect());		
		CleanupClosePushL(fsSession);
		
		if (isRootDirectory == 1)
			{
			AddToBackQueue(currentPath);
			currentPath.Copy(fileSpec);
			
			//fileSpec.Append(_L("\\*.*"));
			ShowFileList(fileSpec);			
			forwardQueue->Reset();
			isRootDirectory = EFalse;
			}
		else
			{
			TEntry entry;
			User::LeaveIfError(fsSession.Entry(fileSpec, entry));
			if (entry.IsDir())
				{
				// Updates current path and back path			
				AddToBackQueue(currentPath);				
				currentPath.Copy(fileSpec);
				
				//fileSpec.Append(_L("\\*.*"));
				ShowFileList(fileSpec);
				forwardQueue->Reset();
				}
			else
				{
				TParse parse;
				User::LeaveIfError(fsSession.Parse(fileSpec, parse));
				TFileName fileExtension;
				fileExtension.Copy(parse.Ext());
				if ((fileExtension.Compare(_L("ini")) == 0) || (fileExtension.Compare(_L("txt")) == 0))
					{
					
					}
				else
					{
					CAknInformationNote* note = new CAknInformationNote();
					note->ExecuteLD(_L("Not supported"));
					}
				}
			}
		
			CleanupStack::PopAndDestroy(&fsSession);
		}
	return ETrue;
	}
				
/** 
 * Handle the selected event.
 * @param aCommand the command id invoked
 * @return ETrue if the command was handled, EFalse if not
 */
TBool CMobileExplorerListBoxView::HandleCopyMenuItemSelectedL( TInt aCommand )
	{
	// TODO: implement selected event handler
	return ETrue;
	}
				
/** 
 * Handle the selected event.
 * @param aCommand the command id invoked
 * @return ETrue if the command was handled, EFalse if not
 */
TBool CMobileExplorerListBoxView::HandleCutMenuItemSelectedL( TInt aCommand )
	{
	// TODO: implement selected event handler
	return ETrue;
	}
				
/** 
 * Handle the selected event.
 * @param aCommand the command id invoked
 * @return ETrue if the command was handled, EFalse if not
 */
TBool CMobileExplorerListBoxView::HandlePasteMenuItemSelectedL( TInt aCommand )
	{
	// TODO: implement selected event handler
	return ETrue;
	}
				
/** 
 * Handle the selected event.
 * @param aCommand the command id invoked
 * @return ETrue if the command was handled, EFalse if not
 */
TBool CMobileExplorerListBoxView::HandleDeleteMenuItemSelectedL( TInt aCommand )
	{
	// TODO: implement selected event handler
	return ETrue;
	}
				
/** 
 * Handle the selected event.
 * @param aCommand the command id invoked
 * @return ETrue if the command was handled, EFalse if not
 */
TBool CMobileExplorerListBoxView::HandleBackMenuItemSelectedL( TInt aCommand )
	{
	// TODO: implement selected event handler
	if (backQueue != NULL && backQueue->Count() > 0)
		{
		TInt indexToBack = backQueue->Count() - 1;
		TPtrC backItem = backQueue->MdcaPoint(indexToBack);
		AddToForwardQueue(currentPath);		
		
		// If back path is root
		if (backItem.Compare(_L("")) == 0)
			{
			DisplayDrives();			
			isRootDirectory = ETrue;
			}
		else
			{
//			TBuf<256> fileSpec;
//			fileSpec.Copy(backItem);
//			fileSpec.Append(_L("\\*.*"));			
			ShowFileList(backItem);	
			if (isRootDirectory == 1)
				{
				isRootDirectory = EFalse;
				}
			}
		currentPath.Copy(backItem);
		backQueue->Delete(indexToBack);		
		}
	return ETrue;
	}
				
/** 
 * Handle the selected event.
 * @param aCommand the command id invoked
 * @return ETrue if the command was handled, EFalse if not
 */
TBool CMobileExplorerListBoxView::HandleForwardMenuItemSelectedL( TInt aCommand )
	{
	// TODO: implement selected event handler
	if (forwardQueue != NULL && forwardQueue->Count() > 0)
		{
		TInt indexToForward = forwardQueue->Count() - 1;
		TPtrC forwardItem = forwardQueue->MdcaPoint(indexToForward);
		AddToBackQueue(currentPath);
		
		// If forward path is root
		if (forwardItem.Compare(_L("")) == 0)
			{
			DisplayDrives();			
			isRootDirectory = ETrue;
			}
		else
			{
//			TBuf<256> fileSpec;
//			fileSpec.Copy(forwardItem);
//			fileSpec.Append(_L("\\*.*"));
			
			ShowFileList(forwardItem);
			if (isRootDirectory == 1)
				{
				isRootDirectory = EFalse;
				}
			}
		currentPath.Copy(forwardItem);
		
		forwardQueue->Delete(indexToForward);		
		}
	return ETrue;
	}
				
/** 
 * Handle the selected event.
 * @param aCommand the command id invoked
 * @return ETrue if the command was handled, EFalse if not
 */
TBool CMobileExplorerListBoxView::HandleGo_to_RootMenuItemSelectedL( TInt aCommand )
	{
	// TODO: implement selected event handler
	DisplayDrives();
	AddToBackQueue(currentPath);
	currentPath.Delete(0, currentPath.Length());
	return ETrue;
	}
				
/** 
 * Handle the selected event.
 * @param aCommand the command id invoked
 * @return ETrue if the command was handled, EFalse if not
 */
TBool CMobileExplorerListBoxView::HandleOptionsMenuItemSelectedL( TInt aCommand )
	{
	// TODO: implement selected event handler
	return ETrue;
	}
				
/**
 *	Handle the activated event
 */
void CMobileExplorerListBoxView::HandleMobileExplorerListBoxViewActivatedL()
	{
	// TODO: implement activated event handler		
	mainListBox = iMobileExplorerListBox->ListBox();
	lbModel = mainListBox->Model();
	DisplayDrives();
	}

void CMobileExplorerListBoxView::DisplayDrives()
	{
		RFs fsSession;
		User::LeaveIfError(fsSession.Connect());
		CleanupClosePushL(fsSession);
		
		TDriveList dlDriverList;
		TInt error;
		if ((error = fsSession.DriveList(dlDriverList)) == KErrNone)
			{
			TInt nDriver = dlDriverList.Length();
			//TInt iconIndex = 0;
			TChar driveOffset = 'A';
			_LIT(offset, "%c:");
			TBuf<50> listItemText;
			TBuf<50> temp;
			//TDriveInfo driveInfo;
			TVolumeInfo volumeInfo;
			//CEikListBox* mainListBox = iMobileExplorerListBox->ListBox(); 
			//mainList->Reset();
			CDesCArray* textArray = static_cast<CDesCArray*>(lbModel->ItemTextArray());
			textArray->Reset();
			mainListBox->HandleItemRemovalL();
			TInt i = 0;
			
			for (i = 0; i < nDriver; i++)
				{
				if (dlDriverList[i] != 0)
					{
					fsSession.DriveToChar(i, driveOffset);
					listItemText.Format(offset, driveOffset);
					//currentPath.Copy(listItemText);
					
					fsSession.Volume(volumeInfo, i);
					FormatVolumeInfo(listItemText, volumeInfo);	
										
					CMobileExplorerListBox::CreateListBoxItemL(temp, 0, listItemText);
					CMobileExplorerListBox::AddListBoxItemL(mainListBox, temp);
					}
				}
			
			isRootDirectory = ETrue;
						
			CleanupStack::PopAndDestroy(&fsSession);
			}		
	}

void CMobileExplorerListBoxView::FormatVolumeInfo(TDes& listItemText, const TVolumeInfo aVolumeInfo)
    {
    // Append volume information to aBuffer
    TBuf<30> result;
    TInt64 iSize = aVolumeInfo.iSize;
    TInt64 iFree = aVolumeInfo.iFree;
    
    TInt iDevider = 1024;
    TReal fUsed = (TReal)(iSize - iFree)/iDevider;
    if (fUsed > 1024)
    	{
		iDevider *= 1024;
		fUsed /= 1024;
    	}
    
    TReal fSize = (TReal)aVolumeInfo.iSize/iDevider;
    
    if (iDevider == 1024)
    	{
		_LIT(KVolumeInfo, "[%.0f KB/%.0f KB]");
		result.Format(KVolumeInfo, fUsed, fSize);
    	}
    else
    	{
		_LIT(KVolumeInfo, "[%.0f MB/%.0f MB]");
		result.Format(KVolumeInfo, fUsed, fSize);
    	}
        
    listItemText.Append(result);
    }

void CMobileExplorerListBoxView::ShowFileList(const TDesC &fileSpec)
	{
	RFs fsSession;
	User::LeaveIfError(fsSession.Connect());		
	CleanupClosePushL(fsSession);
	
	CDir* dirList;
	TBuf<256> filePath;
	filePath.Copy(fileSpec);
	filePath.Append(_L("\\*.*"));
	User::LeaveIfError(fsSession.GetDir(filePath, KEntryAttMaskSupported, ESortByName, dirList));
	CleanupStack::PushL(dirList);
	if (dirList != NULL)
		{
		//CTextListBoxModel* lbModel = (CTextListBoxModel*)mainListBox->Model();
		CDesCArray* textArray = static_cast<CDesCArray*>(lbModel->ItemTextArray());
		textArray->Reset();
		mainListBox->HandleItemRemovalL();
		if (dirList->Count() > 0)
			{						
			TBuf<256> fileName;	
			TBuf<256> temp;
			for (int i = 0; i < dirList->Count(); i++)
				{
				fileName = (*dirList)[i].iName;		
				filePath.Copy(fileSpec);
				filePath.Append(_L("\\"));
				filePath.Append(fileName);		// full path
				
				TEntry entry;
				User::LeaveIfError(fsSession.Entry(filePath, entry));
				if (entry.IsDir())
					{
					CMobileExplorerListBox::CreateListBoxItemL(temp, 1, fileName);				
					}
				else
					{
					CMobileExplorerListBox::CreateListBoxItemL(temp, 2, fileName);
					}
				CMobileExplorerListBox::AddListBoxItemL(mainListBox, temp);
				//textArray->AppendL(temp);
				}	
			}
		}
	
	CleanupStack::PopAndDestroy(dirList);
	CleanupStack::PopAndDestroy(&fsSession);
	}

void CMobileExplorerListBoxView::AddToBackQueue(const TDesC& aPath)
	{
	// Add to back path
	if (backQueue != NULL)
		{
//		TBuf<256> temp;
//		temp.Copy(aPath);
		if (backQueue->Count() == 8)
			{
			backQueue->Delete(0);
			}
		backQueue->AppendL(aPath);
//		ASSERT((backQueue->At(backQueue->Count() - 1).Compare(aPath) == 0);
//		CAknInformationNote* note1 = new CAknInformationNote();
//		note1->ExecuteLD(*(backQueue->At[backQueue->Count() - 1)]));
		}
	else
		{
		CAknInformationNote* note = new CAknInformationNote();
		note->ExecuteLD(_L("Back queue is NULL"));
		}
	}

void CMobileExplorerListBoxView::AddToForwardQueue(const TDesC& aPath)
	{
	if (forwardQueue != NULL)
		{
//		TBuf<256> temp;
//		temp.Copy(aPath);
		if (forwardQueue->Count() == 8)
			{
			forwardQueue->Delete(0);
			}
		forwardQueue->AppendL(aPath);
		}
	else
		{
		CAknInformationNote* note = new CAknInformationNote();
		note->ExecuteLD(_L("Forward queue is NULL"));
		}	
	}

void CMobileExplorerListBoxView::OpenFile(const TDesC& filePath)
	{	
	
	//iAvkonViewAppUi->ActivateLocalViewL(TUid::Uid(EMobileExplorerContainerViewId));	
	}


