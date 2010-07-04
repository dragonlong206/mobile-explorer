/*
========================================================================
 Name        : MobileExplorerContainer_AboutView.cpp
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
#include "MobileExplorerContainer_AboutView.h"
#include "MobileExplorerListBox.hrh"
#include "MobileExplorerContainer_About.h"
// ]]] end generated region [Generated User Includes]

// [[[ begin generated region: do not modify [Generated Constants]
// ]]] end generated region [Generated Constants]

/**
 * First phase of Symbian two-phase construction. Should not contain any
 * code that could leave.
 */
CMobileExplorerContainer_AboutView::CMobileExplorerContainer_AboutView()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	iMobileExplorerContainer_About = NULL;
	// ]]] end generated region [Generated Contents]
	
	}

/** 
 * The view's destructor removes the container from the control
 * stack and destroys it.
 */
CMobileExplorerContainer_AboutView::~CMobileExplorerContainer_AboutView()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	delete iMobileExplorerContainer_About;
	iMobileExplorerContainer_About = NULL;
	// ]]] end generated region [Generated Contents]
	
	}

/**
 * Symbian two-phase constructor.
 * This creates an instance then calls the second-phase constructor
 * without leaving the instance on the cleanup stack.
 * @return new instance of CMobileExplorerContainer_AboutView
 */
CMobileExplorerContainer_AboutView* CMobileExplorerContainer_AboutView::NewL()
	{
	CMobileExplorerContainer_AboutView* self = CMobileExplorerContainer_AboutView::NewLC();
	CleanupStack::Pop( self );
	return self;
	}

/**
 * Symbian two-phase constructor.
 * This creates an instance, pushes it on the cleanup stack,
 * then calls the second-phase constructor.
 * @return new instance of CMobileExplorerContainer_AboutView
 */
CMobileExplorerContainer_AboutView* CMobileExplorerContainer_AboutView::NewLC()
	{
	CMobileExplorerContainer_AboutView* self = new ( ELeave ) CMobileExplorerContainer_AboutView();
	CleanupStack::PushL( self );
	self->ConstructL();
	return self;
	}


/**
 * Second-phase constructor for view.  
 * Initialize contents from resource.
 */ 
void CMobileExplorerContainer_AboutView::ConstructL()
	{
	// [[[ begin generated region: do not modify [Generated Code]
	BaseConstructL( R_MOBILE_EXPLORER_CONTAINER_ABOUT_MOBILE_EXPLORER_CONTAINER_ABOUT_VIEW );
				
	// ]]] end generated region [Generated Code]
	
	// add your own initialization code here
	
	}

/**
 * @return The UID for this view
 */
TUid CMobileExplorerContainer_AboutView::Id() const
	{
	return TUid::Uid( EMobileExplorerContainer_AboutViewId );
	}

/**
 * Handle a command for this view (override)
 * @param aCommand command id to be handled
 */
void CMobileExplorerContainer_AboutView::HandleCommandL( TInt aCommand )
	{
	// [[[ begin generated region: do not modify [Generated Code]
	TBool commandHandled = EFalse;
	switch ( aCommand )
		{	// code to dispatch to the AknView's menu and CBA commands is generated here
	
		case EAknSoftkeyExit:
			commandHandled = HandleControlPaneRightSoftKeyPressedL( aCommand );
			break;
		default:
			break;
		}
	
		
	if ( !commandHandled ) 
		{
	
		}
	// ]]] end generated region [Generated Code]
	
	}

/**
 *	Handles user actions during activation of the view, 
 *	such as initializing the content.
 */
void CMobileExplorerContainer_AboutView::DoActivateL( 
		const TVwsViewId& /*aPrevViewId*/,
		TUid /*aCustomMessageId*/,
		const TDesC8& /*aCustomMessage*/ )
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	SetupStatusPaneL();
	
				
				
	
	if ( iMobileExplorerContainer_About == NULL )
		{
		iMobileExplorerContainer_About = CreateContainerL();
		iMobileExplorerContainer_About->SetMopParent( this );
		AppUi()->AddToStackL( *this, iMobileExplorerContainer_About );
		} 
	// ]]] end generated region [Generated Contents]
	
	}

/**
 */
void CMobileExplorerContainer_AboutView::DoDeactivate()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	CleanupStatusPane();
	
	if ( iMobileExplorerContainer_About != NULL )
		{
		AppUi()->RemoveFromViewStack( *this, iMobileExplorerContainer_About );
		delete iMobileExplorerContainer_About;
		iMobileExplorerContainer_About = NULL;
		}
	// ]]] end generated region [Generated Contents]
	
	}

/** 
 * Handle status pane size change for this view (override)
 */
void CMobileExplorerContainer_AboutView::HandleStatusPaneSizeChange()
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
void CMobileExplorerContainer_AboutView::SetupStatusPaneL()
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
		iEikonEnv->CreateResourceReaderLC( reader, R_MOBILE_EXPLORER_CONTAINER_ABOUT_TITLE_RESOURCE );
		title->SetFromResourceL( reader );
		CleanupStack::PopAndDestroy(); // reader internal state
		}
				
	}

// ]]] end generated function

// [[[ begin generated function: do not modify
void CMobileExplorerContainer_AboutView::CleanupStatusPane()
	{
	}

// ]]] end generated function

/**
 *	Creates the top-level container for the view.  You may modify this method's
 *	contents and the CMobileExplorerContainer_About::NewL() signature as needed to initialize the
 *	container, but the signature for this method is fixed.
 *	@return new initialized instance of CMobileExplorerContainer_About
 */
CMobileExplorerContainer_About* CMobileExplorerContainer_AboutView::CreateContainerL()
	{
	return CMobileExplorerContainer_About::NewL( ClientRect(), NULL, this );
	}

/** 
 * Handle the rightSoftKeyPressed event.
 * @return ETrue if the command was handled, EFalse if not
 */
TBool CMobileExplorerContainer_AboutView::HandleControlPaneRightSoftKeyPressedL( TInt aCommand )
	{
	// TODO: implement rightSoftKeyPressed event handler
	iAvkonViewAppUi->ActivateLocalViewL(TUid::Uid(EMobileExplorerListBoxViewId));
	return ETrue;
	}
				
