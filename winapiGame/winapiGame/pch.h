#pragma once

#include <windows.h>

#include "Types.h"
#include "TimeManager.h"
#include "Enums.h"
#include "Utils.h"

#define _CRTDEBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif



#include "List.h"
using namespace std;


//Values
const int32 GWinSizeX = 1920;
const int32 GWinSizeY = 1080;