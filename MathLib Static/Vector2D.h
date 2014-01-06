#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

#ifdef DLL
	#define DLLXPORT __declspec(dllexport)
#else
	#define DLLXPORT __declspec(dllimport)
#endif

/* TO DO 11/19 : Implement constant compatability for functions, implement already completed
Vector2D functions */

class DLLXPORT Vector2D
{
	public:
		//Two floats, for storing X and Y values
		float m_fX;
		float m_fY;

		//Constructors and deconstructor
		Vector2D(); //sets both x and y to zero
		Vector2D(float a_fX, float a_fY); //sets x and y to passed floating point arguments
		Vector2D(const Vector2D &a_v2DCopy); //copy constructor
		~Vector2D(void);

		//Operators
		Vector2D operator + (Vector2D &a_v2DAdded);
		void operator += (Vector2D a_v2DAdded);
		Vector2D operator - (Vector2D &a_v2DSubtracted);
		void operator -= (Vector2D &a_v2DSubtracted);
		Vector2D operator * (float a_fScalar);
		void operator *= (float a_fScalar);
		Vector2D operator / (float a_fScalar);
		void operator /= (float a_fScalar);
		void operator = (Vector2D &a_v2DCopy);
		bool operator == (Vector2D &a_v2DCompare);

		/* Functions */
		float Magnitude();
		void Normalize();
		Vector2D GetNormal();
		float Dot(Vector2D a_v2DOther);
		float Euler(Vector2D a_v2DOther);
		Vector2D Interpolate(Vector2D &a_v2DOther, float a_fTime);

};

#endif