#ifndef _MISCMATH_H_
#define _MISCMATH_H_

#ifdef DLL
	#define DLLXPORT __declspec(dllexport)
#else
	#define DLLXPORT __declspec(dllimport)
#endif

DLLXPORT float Interpolate(float a_fx, float a_fy, float a_ft);
DLLXPORT float ConvertToRadians(float a_fDegrees);
DLLXPORT float ConvertToDegrees(float a_fRadians);
DLLXPORT int NextPowTwo(double a_fNum);

#endif