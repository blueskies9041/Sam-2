#ifndef _VECTOR4D_H
#define _VECTOR4D_H




	


#include <iostream>

using namespace std;

class  Vector4D
{
	public:

		/* Three floats for XYZW values */
		float m_fX;
		float m_fY;
		float m_fZ;
		float m_fW;

		/* Constructors and Deconstructor */
		Vector4D(float a_fX, float a_fY, float a_fZ, float m_fW); //Primary
		Vector4D(const Vector4D &ac_v4DCopy); //Copy
		Vector4D(); //Default
		~Vector4D(); //Decon

		/* Operators */
		Vector4D operator + (Vector4D &a_v4DAdded);
		void operator += (Vector4D a_v4DAdded);
		Vector4D operator - (Vector4D &a_v4DSubtracted);
		void operator -= (Vector4D &a_v4DSubtracted);
		Vector4D operator * (float a_fScalar);
		void operator *= (float a_fScalar);
		Vector4D operator / (float a_fScalar);
		void operator /= (float a_fScalar);
		void operator = (Vector4D &a_v4DCopy);
		bool operator == (Vector4D &a_v4DCompare);

		/* Functions */
		float Magnitude();
		void Normalize();
		Vector4D GetNormal();
		float Dot(Vector4D a_v4DOther);
		Vector4D Cross(Vector4D a_v4DOther);
		float Euler(Vector4D a_v4DOther);
		Vector4D Interpolate(Vector4D &a_v4DOther, float a_fTime);
		Vector4D& ConstructFromColor(int a_iHexValue);

		inline friend ostream& operator<<(ostream& os, const Vector4D& dt)
		{
			os << "(" << dt.m_fX << ',' << dt.m_fY << ',' << dt.m_fZ << ',' << dt.m_fW << ")" ;
			return os;
		}

};

#endif