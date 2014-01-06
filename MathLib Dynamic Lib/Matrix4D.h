#ifndef _MATRIX4D_H_
#define _MATRIX4D_H_

#ifdef DLL
	#define DLLXPORT __declspec(dllexport)
#else
	#define DLLXPORT __declspec(dllimport)
#endif

#include <iostream>
#include "Vector4D.h"

using namespace std;

class DLLXPORT Matrix4D
{
public:
	union
	{
		struct
		{
			float e_11, e_12, e_13, e_14,
				e_21, e_22, e_23, e_24,
				e_31, e_32, e_33, e_34,
				e_41, e_42, e_43, e_44;
		};
		float m_aFloats[4][4];
		float m_aArray[16];
	};

	inline Matrix4D() {}
	inline Matrix4D(const Matrix4D &a_oCopy)
	{
		*this = a_oCopy;
	}
	inline Matrix4D(float a_e11, float a_e12, float a_e13, float a_e14,
					float a_e21, float a_e22, float a_e23, float a_e24,
					float a_e31, float a_e32, float a_e33, float a_e34,
					float a_e41, float a_e42, float a_e43, float a_e44) : 
				e_11(a_e11), e_12(a_e12), e_13(a_e13), e_14(a_e14),
				e_21(a_e21), e_22(a_e22), e_23(a_e23), e_24(a_e24),
				e_31(a_e31), e_32(a_e32), e_33(a_e33), e_34(a_e34),
				e_41(a_e41), e_42(a_e42), e_43(a_e43), e_44(a_e44){}

	
	inline void operator = (const float* ca_pfArray)
	{
		e_11 = ca_pfArray[0]; e_12 = ca_pfArray[1]; e_13 = ca_pfArray[2]; e_14 = ca_pfArray[3];
		e_21 = ca_pfArray[4]; e_22 = ca_pfArray[5]; e_23 = ca_pfArray[6]; e_24 = ca_pfArray[7];
		e_31 = ca_pfArray[8]; e_32 = ca_pfArray[9]; e_33 = ca_pfArray[10]; e_34 = ca_pfArray[11];
		e_41 = ca_pfArray[12]; e_42 = ca_pfArray[13]; e_43 = ca_pfArray[14]; e_44 = ca_pfArray[15];
	}

	Matrix4D  operator + (const Matrix4D &a_roRHS) const;
	Matrix4D  operator - (const Matrix4D &a_roRHS) const ;
	Matrix4D& operator *= (float a_fScalar);
	Matrix4D& operator *= (const Matrix4D &a_roRHS);
	Matrix4D& operator /= (float a_fScalar);
	Matrix4D& operator += (const Matrix4D &a_roRHS);
	Matrix4D& operator -= (const Matrix4D &a_roRHS);
	Matrix4D  operator * (const Matrix4D &a_roRHS) const;
	Matrix4D  operator * (float a_fScalar) const;
	Vector4D  operator * (const Vector4D &a_roRHS) const;

	inline void SetZero()
	{
		e_11 = e_12 = e_13 = e_14 = e_21 = e_22 = e_23 = e_24 = e_31 = e_32 = e_33 = e_34 = e_41 = e_42 = e_43 = e_44 = 0.0f;
	}
	inline void SetIdentity()
	{
		e_11 = 1.0f; e_12 = 0.0f; e_13 = 0.0f; e_14 = 1.0f;
		e_21 = 0.0f; e_22 = 1.0f; e_23 = 0.0f; e_24 = 1.0f;
		e_31 = 0.0f; e_32 = 0.0f; e_33 = 1.0f; e_34 = 1.0f;
		e_41 = 0.0f; e_42 = 0.0f; e_43 = 1.0f; e_44 = 1.0f;
	}

	Matrix4D CreateRotationX(float a_fAngle);
	Matrix4D CreateRotationY(float a_fAngle);
	Matrix4D CreateRotationZ(float a_fAngle);
	Matrix4D CreateTranslation(Vector4D& a_roTranslator);
	Matrix4D CreateScaling(Vector4D& a_roScalar);
	Matrix4D CreateOrtho(float a_fLeft, float a_fRight,float a_fBottom, float a_fTop, float a_fFar, float a_fNear);
	void TransformPoint(Vector4D& a_roPoint, float a_fAngleX, float a_fAngleY, float a_fAngleZ, Vector4D& a_roTranslator, Vector4D& a_roScalar);
	void TransformVector(Vector4D& a_roPoint, float a_fAngleX, float a_fAngleY, float a_fAngleZ, Vector4D& a_roScalar);

	inline friend ostream& operator<<(ostream& os, const Matrix4D& dt)
	{
		for(int i = 0; i < 4; ++i)
		{
		
			for(int j = 0; j < 4; ++j)
			{
				os << "["<< dt.m_aFloats[i][j] << "]" ;
			}
			os << endl;
		}
		return os;
	}
};

#endif