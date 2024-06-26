#pragma once
#include <math.h>


inline bool Equals(float fLhs, float fRhs)
{
	const static float fEPSION = 0.5f;
	return fabs(fLhs - fRhs) < fEPSION ? true : false;
}