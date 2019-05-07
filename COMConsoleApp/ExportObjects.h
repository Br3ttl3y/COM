#pragma once

// Is not exported to C# so don't need to worry about extern "decorations"
struct IHen
{
	virtual void __stdcall Cluck() = 0;
	virtual void __stdcall Roost() = 0;

	// Doesn't destruct normally.  Updated with AddRef and Release.
	// virtual void __stdcall Delete() = 0; 

	virtual void __stdcall AddRef() = 0;
	virtual void __stdcall Release() = 0;
};

//IHen* __stdcall CreateHen();

