#ifndef _VECTOR3D_H
#define _VECTOR3D_H




	


#include <iostream>
using namespace std;

class  Vector3D
{
	public:

		/* Three floats for XYZ values */
		float m_fX;
		float m_fY;
		float m_fZ;

		/* Constructors and Deconstructor */
		Vector3D(float a_fX, float a_fY, float a_fZ); //Primary
		Vector3D(const Vector3D &ac_v3DCopy); //Copy
		Vector3D(); //Default
		~Vector3D(); //Decon

		/* Operators */
		Vector3D operator + (Vector3D &a_v3DAdded);
		Vector3D& operator += (Vector3D a_v3DAdded);
		Vector3D operator - (Vector3D &a_v3DSubtracted);
		Vector3D& operator -= (Vector3D &a_v3DSubtracted);
		Vector3D operator * (float a_fScalar);
		Vector3D& operator *= (float a_fScalar);
		Vector3D operator / (float a_fScalar);
		Vector3D& operator /= (float a_fScalar);
		Vector3D& operator = (Vector3D &a_v3DCopy);
		bool operator == (Vector3D &a_v3DCompare);

		/* Functions */
		Vector3D& Inverse();
		float Magnitude();
		void Normalize();
		Vector3D GetNormal();
		float Dot(Vector3D a_v3DOther);
		Vector3D Cross(Vector3D a_v3DOther);
		float Euler(Vector3D a_v3DOther);
		Vector3D Interpolate(Vector3D &a_v3DOther, float a_fTime);

		inline friend ostream& operator<<(ostream& os, const Vector3D& dt)
		{
			os << "(" << dt.m_fX << ',' << dt.m_fY << ',' << dt.m_fZ << ")" ;
			return os;
		}
		
		

};

#endif