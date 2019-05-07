#include "ExtendingObjects.h"
#include <windows.h>
#include <tchar.h>

// only print for debug modes
// conditionally define for debug only
#define TRACE OutputDebugString

struct Hen : IHen2, IOfflineChicken
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

  // IObject
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

  void * __stdcall As(char const * type)
  {
    if(0 == strcmp(type, "IHen2")
      || 0 == strcmp(type, "IObject")
      || 0 == strcmp(type, "IHen"))
    {
      AddRef();
      return static_cast<IHen2 *>(this);
    }
    else if(0 == strcmp(type, "IOfflineChicken"))
    {
      AddRef();
      return static_cast<IOfflineChicken *>(this);
    }
    else
    {
      return 0;
    }
  }

  // Hen
  void __stdcall Cluck()
  {
    TRACE(_T("Cluck!\n"));
  }

  void __stdcall Roost()
  {
    TRACE(_T("Zzz!\n"));
  }

  // Hen2
  void __stdcall Forage()
  {
    TRACE(_T("Forage!\n"));
  }

  // IOfflineChicken
  void __stdcall Load(char const * /*file*/)
  {
  }

  void __stdcall Save(char const * /*file*/)
  {
  }

  // not a good pattern
  //Void __stdcall Delete()
  //{
  //  delete this;
  //}
};

IHen * __stdcall CreateHen()
{
  IHen* result = new Hen;
  result->AddRef();
  return result;
}

