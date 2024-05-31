#pragma once
#define			PURE	= 0
#define			WINCX	800
#define			WINCY	600
#define			PI					3.141592f

#define			VK_MAX				0xff

#define			TILECX  64
#define			TILECY  64

#define			TILEX	30
#define			TILEY	20

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}
