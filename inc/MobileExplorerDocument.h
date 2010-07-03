/*
========================================================================
 Name        : MobileExplorerDocument.h
 Author      : Le Van Long
 Copyright   : Your copyright notice
 Description : 
========================================================================
*/
#ifndef MOBILEEXPLORERDOCUMENT_H
#define MOBILEEXPLORERDOCUMENT_H

#include <akndoc.h>
		
class CEikAppUi;

/**
* @class	CMobileExplorerDocument MobileExplorerDocument.h
* @brief	A CAknDocument-derived class is required by the S60 application 
*           framework. It is responsible for creating the AppUi object. 
*/
class CMobileExplorerDocument : public CAknDocument
	{
public: 
	// constructor
	static CMobileExplorerDocument* NewL( CEikApplication& aApp );

private: 
	// constructors
	CMobileExplorerDocument( CEikApplication& aApp );
	void ConstructL();
	
public: 
	// from base class CEikDocument
	CEikAppUi* CreateAppUiL();
	};
#endif // MOBILEEXPLORERDOCUMENT_H
