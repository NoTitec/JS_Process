#pragma once

#define		SAFE_DELETE(p) if(p) { delete p; p = nullptr;}
#define		SAFE_DELETE_ARRAY(p) if(p) { delete[] p; p = nullptr;}

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

using namespace std;
