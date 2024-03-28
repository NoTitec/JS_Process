#pragma once

//#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <ctime>
#include <iostream>
#include <iomanip>
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif
using namespace std;