#pragma once

#include <cmath>

class Vec3 {
public:
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;

	Vec3() = default;
	Vec3(double x, double y, double z);

	inline static float length(const Vec3& a) {
		return std::sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
	}

	inline static float dot(const Vec3& a, const Vec3& b) {
		return (a.x * b.x + a.y * b.y + a.z * b.z);
	}

	inline static Vec3 cross(const Vec3& a, const Vec3& b) {
		return Vec3 (
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		);
	}

	inline static Vec3 normalized(const Vec3& a) {
		return Vec3(a.x / length(a), a.y / length(a), a.z / length(a));
	}

	inline Vec3 operator+(const Vec3& other) const {
		return Vec3(this->x + other.x, this->y + other.y, this->z + other.z);
	}
	inline Vec3 operator-(const Vec3& other) const {
		return Vec3(this->x - other.x, this->y - other.y, this->z - other.z);
	}
	inline Vec3 operator*(const Vec3& other) const {
		return Vec3(this->x * other.x, this->y * other.y, this->z * other.z);
	}
	inline Vec3 operator*(const float f) const {
		return Vec3(this->x * f, this->y * f, this->z * f);
	}
	inline Vec3 operator/(const Vec3& other) const {
		return Vec3(this->x / other.x, this->y / other.y, this->z / other.z);
	}
	inline Vec3 operator/(const float f) const {
		return Vec3(this->x / f, this->y / f, this->z / f);
	}

	inline void operator+=(const Vec3& other) {
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}
	inline void operator-=(const Vec3& other) {
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
	}
	inline void operator*=(const Vec3& other) {
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
	}
	inline void operator/=(const Vec3& other) {
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
	}
};
