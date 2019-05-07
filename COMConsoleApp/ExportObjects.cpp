#include "ExportObjects.h"
#include <Windows.h>
#include <tchar.h>

// conditionally define for debug only
#define TRACE OutputDebugString

struct Hen : IHen
{
	unsigned m_count;

	Hen() : m_count(0)
	{
		TRACE(_T("Cheep!\n"));
	}

	~Hen()
	{
		TRACE(_T("Chicken Soup!\n"));
	}

	void __stdcall Cluck()
	{
		TRACE(_T("Cluck!\n"));
	}

	void _stdcall Roost()
	{
		TRACE(_T("Zzz!\n"));
	}

	// not a good pattern
	// void __stdcall Delete()
	// {
	//		delete this;
	// }

	void __stdcall AddRef()
	{
		++m_count;
	}

	void __stdcall Release()
	{
		if(0 == --m_count)
		{
			delete this;
		}
	}
};

// Is defined again in ExtendingObjects.h/cpp
//IHen * __stdcall CreateHen()
//{
//	IHen * henrietta = new Hen;
//	henrietta->AddRef();
//	return henrietta;
//}