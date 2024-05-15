#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <assert.h>

#include <list>
#include <queue>
#include <map>
#include <algorithm>

#include <time.h>

using namespace std;
#include "Defines.h"
#include "Struct.h"
#include "Enum.h"

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif