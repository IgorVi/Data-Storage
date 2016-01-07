#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC

#include<iostream>
#include<fstream>
#include<Windows.h>

#define new new (_NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include "ViewDataStore.h"

int main()
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF /*| _CRTDBG_CHECK_ALWAYS_DF*/ | _CRTDBG_LEAK_CHECK_DF /*| _CRTDBG_DELAY_FREE_MEM_DF*/);
#endif

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ViewDataStore vds;
	vds.Start();

	return 0;
}