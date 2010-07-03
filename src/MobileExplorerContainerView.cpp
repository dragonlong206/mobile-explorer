/*
========================================================================
 Name        : MobileExplorerContainerView.cpp
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
#include <eiklabel.h>
#include <eikenv.h>
#include <gdi.h>
#include <eikedwin.h>
#include <akncontext.h>
#include <akntitle.h>
#include <eikbtgpc.h>
#include <MobileExplorer.rsg>
// ]]] end generated region [Generated System Includes]

// [[[ begin generated region: do not modify [Generated User Includes]

#include "MobileExplorer.hrh"
#include "MobileExplorerContainerView.h"
#include "MobileExplorerListBox.hrh"
#include "MobileExplorerContainer.h"
// ]]] end generated region [Generated User Includes]

// [[[ begin generated region: do not modify [Generated Constants]
// ]]] end generated region [Generated Constants]

/**
 * First phase of Symbian two-phase construction. Should not contain any
 * code that could leave.
 */
CMobileExplorerContainerView::CMobileExplorerContainerView()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	iMobileExplorerContainer = NULL;
	// ]]] end generated region [Generated Contents]
	
	}

/** 
 * The view's destructor removes the container from the control
 * stack and destroys it.
 */
CMobileExplorerContainerView::~CMobileExplorerContainerView()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	delete iMobileExplorerContainer;
	iMobileExplorerContainer = NULL;
	// ]]] end generated region [Generated Contents]
	
	}

/**
 * Symbian two-phase constructor.
 * This creates an instance then calls the second-phase constructor
 * without leaving the instance on the cleanup stack.
 * @return new instance of CMobileExplorerContainerView
 */
CMobileExplorerContainerView* CMobileExplorerContainerView::NewL()
	{
	CMobileExplorerContainerView* self = CMobileExplorerContainerView::NewLC();
	CleanupStack::Pop( self );
	return self;
	}

/**
 * Symbian two-phase constructor.
 * This creates an instance, pushes it on the cleanup stack,
 * then calls the second-phase constructor.
 * @return new instance of CMobileExplorerContainerView
 */
CMobileExplorerContainerView* CMobileExplorerContainerView::NewLC()
	{
	CMobileExplorerContainerView* self = new ( ELeave ) CMobileExplorerContainerView();
	CleanupStack::PushL( self );
	self->ConstructL();
	return self;
	}


/**
 * Second-phase constructor for view.  
 * Initialize contents from resource.
 */ 
void CMobileExplorerContainerView::ConstructL()
	{
	// [[[ begin generated region: do not modify [Generated Code]
	BaseConstructL( R_MOBILE_EXPLORER_CONTAINER_MOBILE_EXPLORER_CONTAINER_VIEW );
				
	// ]]] end generated region [Generated Code]
	
	// add your own initialization code here
	
	}

/**
 * @return The UID for this view
 */
TUid CMobileExplorerContainerView::Id() const
	{
	return TUid::Uid( EMobileExplorerContainerViewId );
	}

/**
 * Handle a command for this view (override)
 * @param aCommand command id to be handled
 */
void CMobileExplorerContainerView::HandleCommandL( TInt aCommand )
	{
	// [[[ begin generated region: do not modify [Generated Code]
	TBool commandHandled = EFalse;
	switch ( aCommand )
		{	// code to dispatch to the AknView's menu and CBA commands is generated here
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
void CMobileExplorerContainerView::DoActivateL( 
		const TVwsViewId& /*aPrevViewId*/,
		TUid /*aCustomMessageId*/,
		const TDesC8& /*aCustomMessage*/ )
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	SetupStatusPaneL();
	
				
				
	
	if ( iMobileExplorerContainer == NULL )
		{
		iMobileExplorerContainer = CreateContainerL();
		iMobileExplorerContainer->SetMopParent( this );
		AppUi()->AddToStackL( *this, iMobileExplorerContainer );
		} 
	// ]]] end generated region [Generated Contents]
	
	}

/**
 */
void CMobileExplorerContainerView::DoDeactivate()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	CleanupStatusPane();
	
	if ( iMobileExplorerContainer != NULL )
		{
		AppUi()->RemoveFromViewStack( *this, iMobileExplorerContainer );
		delete iMobileExplorerContainer;
		iMobileExplorerContainer = NULL;
		}
	// ]]] end generated region [Generated Contents]
	
	}

/** 
 * Handle status pane size change for this view (override)
 */
void CMobileExplorerContainerView::HandleStatusPaneSizeChange()
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
void CMobileExplorerContainerView::SetupStatusPaneL()
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
		iEikonEnv->CreateResourceReaderLC( reader, R_MOBILE_EXPLORER_CONTAINER_TITLE_RESOURCE );
		title->SetFromResourceL( reader );
		CleanupStack::PopAndDestroy(); // reader internal state
		}
				
	}

// ]]] end generated function

// [[[ begin generated function: do not modify
void CMobileExplorerContainerView::CleanupStatusPane()
	{
	}

// ]]] end generated function

/**
 *	Creates the top-level container for the view.  You may modify this method's
 *	contents and the CMobileExplorerContainer::NewL() signature as needed to initialize the
 *	container, but the signature for this method is fixed.
 *	@return new initialized instance of CMobileExplorerContainer
 */
CMobileExplorerContainer* CMobileExplorerContainerView::CreateContainerL()
	{
	return CMobileExplorerContainer::NewL( ClientRect(), NULL, this );
	}

