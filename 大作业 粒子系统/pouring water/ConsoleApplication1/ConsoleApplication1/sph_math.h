#pragma once
#define PI 3.14159265358
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// fVector3
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class fVector3
{
public:
	fVector3() : x(0), y(0), z(0) {}
	fVector3(const fVector3& other) : x(other.x), y(other.y), z(other.z) {}
	fVector3(const float_3* other) : x(other->x), y(other->y), z(other->z) {}
	fVector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	~fVector3() {}

	void set(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }

	fVector3& operator= (const fVector3 &op) { x = op.x; y = op.y; z = op.z; return *this; }

	fVector3& operator+= (float op) { x += op; y += op; z += op; return *this; }
	fVector3& operator-= (float op) { x -= op; y -= op; z -= op; return *this; }
	fVector3& operator*= (float op) { x *= op; y *= op; z *= op; return *this; }
	fVector3& operator/= (float op) { x /= op; y /= op; z /= op; return *this; }

	fVector3& operator+= (const fVector3& op) { x += op.x; y += op.y; z += op.z; return *this; }
	fVector3& operator-= (const fVector3& op) { x -= op.x; y -= op.y; z -= op.z; return *this; }
	fVector3& operator*= (const fVector3& op) { x *= op.x; y *= op.y; z *= op.z; return *this; }
	fVector3& operator/= (const fVector3& op) { x /= op.x; y /= op.y; z /= op.z; return *this; }

	float dot(const fVector3& other)
	{
		return x*other.x + y*other.y + z*other.z;
	}

	float len_sq(void) const
	{
		return x*x + y*y + z*z;
	}

	void normalize(void)
	{
		float len_squar = x*x + y*y + z*z;
		if (len_squar != 0.0)
		{
			float len = sqrt(len_squar);
			x /= len; y /= len; z /= len;
		}
	}
public:
	float x, y, z;
};

inline fVector3 operator + (const fVector3& a, const fVector3& b)
{
	return fVector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline fVector3 operator - (const fVector3& a, const fVector3& b)
{
	return fVector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline fVector3 operator * (float s, const fVector3& a)
{
	return fVector3(s*a.x, s*a.y, s*a.z);
}

inline fVector3 operator * (const fVector3& a, float s)
{
	return fVector3(s*a.x, s*a.y, s*a.z);
}

inline fVector3 operator / (const fVector3& a, float s)
{
	return fVector3(a.x / s, a.y / s, a.z / s);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// fBox3
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class fBox3
{
public:
	fBox3() {}
	fBox3(const fBox3& other) : min(other.min), max(other.max) {}
	fBox3(const fVector3& _min, const fVector3& _max) : min(_min), max(_max) {}
	~fBox3() {}

public:
	fVector3 min, max;
};

