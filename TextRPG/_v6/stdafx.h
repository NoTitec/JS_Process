#pragma once

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <string>

#include "tagPlayer.h"
#include "tagMonster.h"
using namespace std;