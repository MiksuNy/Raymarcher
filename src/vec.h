#pragma once

#include <cmath>

class Vec3 {
public:
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;

	Vec3() = default;
	Vec3(double x, double y, double z);

	static float Length(const Vec3 a);
	static float Dot(const Vec3 a, const Vec3 b);
	static Vec3 Cross(const Vec3 a, const Vec3 b);
	static Vec3 Abs(const Vec3 a);
	static Vec3 Max(const Vec3 a, const float f);
	static Vec3 Min(const Vec3 a, const float f);
	static Vec3 Normalize(const Vec3 a);

	Vec3 operator+(const Vec3 other) const;
	Vec3 operator-(const Vec3 other) const;
	Vec3 operator*(const Vec3 other) const;
	Vec3 operator*(const float f) const;
	Vec3 operator/(const Vec3 other) const;
	Vec3 operator/(const float f) const;
	void operator+=(const Vec3 other);
	void operator-=(const Vec3 other);
	void operator*=(const Vec3 other);
	void operator/=(const Vec3 other);
};
