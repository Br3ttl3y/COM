// Created from Pluralsight course: The Essentials of COM

#include <iostream>
#include "DynamicLinking.h"
//#include "ExportObjects.h"
#include "ExtendingObjects.h"

// Run the examples
int main()
{
#pragma region Dynamic Linking
// An example of dynamic linking with COM
	
	Cluck();
#pragma endregion

// Toggle ExportObjects.h on and ExtendingObjects.h off.
#pragma region Exporting Objects
// Exporting Objects Example in COM.  Shows how to use interfaces to create
// COM objects, manage their references and dispose of their resources 
// properly.

//	IHen* henrietta = CreateHen();
//	henrietta->Cluck();
//	// henrietta->Delete();
//
// Increase references
//	IHen* hennessy = henrietta;
//	hennessy->AddRef();
//	hennessy->Roost();
//	hennessy->Release();
//
// Remove last reference - See Chicken Soup!
//	henrietta->Release();
#pragma endregion

// Toggle ExtendingObjects.h on and ExportObjects.h off.
#pragma region Extending Objects
// Shows how to create more complex interfaces and check their types while
// managing their resources.  Concerns are more separated here.

	// DEBUG: Cheep!, Cluck!
	IHen* hen = CreateHen();
	hen->Cluck();
	
	// DEBUG: Forage!, Zzz!
	IHen2 * hen2 = static_cast<IHen2 *>(hen->As("IHen2"));
	if(hen2)
	{
		hen2->Forage();
		hen2->Release();
	}

	IOfflineChicken * offline = static_cast<IOfflineChicken *>(hen->As("IOfflineChicken"));
	if(offline)
	{
		offline->Save("filename");
		offline->Release();
	}

	// DEBUG: Chicken Soup!
	hen->Release();

#pragma endregion
}