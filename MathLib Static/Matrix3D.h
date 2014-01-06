#ifndef _MATRIX3D_H_
#define _MATRIX3D_H_




	


#include <iostream>
#include "Vector3D.h"

using namespace std;

class  Matrix3D
{
public:
	union
	{
		struct
		{
			float e_11, e_12, e_13,
				e_21, e_22, e_23,
				e_31, e_32, e_33;
		};
		float m_aFloats[3][3];
		float m_aArray[9];
	};

	inline Matrix3D() {}
	inline Matrix3D(const Matrix3D &a_oCopy)
	{
		*this = a_oCopy;
	}
	inline Matrix3D(float a_e11, float a_e12, float a_e13,
					float a_e21, float a_e22, float a_e23,
					float a_e31, float a_e32, float a_e33) : 
				e_11(a_e11), e_12(a_e12), e_13(a_e13),
				e_21(a_e21), e_22(a_e22), e_23(a_e23),
				e_31(a_e31), e_32(a_e32), e_33(a_e33) {}

	
	inline void operator = (const float* ca_pfArray)
	{
		e_11 = ca_pfArray[0]; e_12 = ca_pfArray[1]; e_13 = ca_pfArray[2];
		e_21 = ca_pfArray[3]; e_22 = ca_pfArray[4]; e_23 = ca_pfArray[5];
		e_31 = ca_pfArray[6]; e_32 = ca_pfArray[7]; e_33 = ca_pfArray[8];
	}

	Matrix3D  operator + (const Matrix3D &a_roRHS) const;
	Matrix3D  operator - (const Matrix3D &a_roRHS) const ;
	Matrix3D& operator *= (float a_fScalar);
	Matrix3D& operator *= (const Matrix3D &a_roRHS);
	Matrix3D& operator /= (float a_fScalar);
	Matrix3D& operator += (const Matrix3D &a_roRHS);
	Matrix3D& operator -= (const Matrix3D &a_roRHS);
	Matrix3D  operator * (const Matrix3D &a_roRHS) const;
	Matrix3D  operator * (float a_fScalar) const;
	Vector3D  operator * (const Vector3D &a_roRHS) const;

	inline void SetZero()
	{
		e_11 = e_12 = e_13 = e_21 = e_22 = e_23 = e_31 = e_32 = e_33 = 0.0f;
	}
	inline void SetIdentity()
	{
		e_11 = 1.0f; e_12 = 0.0f; e_13 = 0.0f;
		e_21 = 0.0f; e_22 = 1.0f; e_23 = 0.0f;
		e_31 = 0.0f; e_32 = 0.0f; e_33 = 1.0f;
	}
	Matrix3D CreateRotation(float a_fAngle);
	Matrix3D CreateTranslation(Vector3D& a_roTranslator);
	Matrix3D CreateScaling(Vector3D& a_roScalar);
	void TransformPoint(Vector3D& a_roPoint, float a_fAngle, Vector3D& a_roTranslator, Vector3D& a_roScalar);
	
	inline friend ostream& operator<<(ostream& os, const Matrix3D& dt)
	{
		for(int i = 0; i < 3; ++i)
		{
		
			for(int j = 0; j < 3; ++j)
			{
				os << "["<< dt.m_aFloats[i][j] << "]" ;
			}
			os << endl;
		}
		return os;
	}
	
};

#endif