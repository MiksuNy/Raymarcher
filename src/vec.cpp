#include "vec.h"

Vec3::Vec3(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vec3::Length(const Vec3 a) {
	return std::sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
}

float Vec3::Dot(const Vec3 a, const Vec3 b) {
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

Vec3 Vec3::Cross(const Vec3 a, const Vec3 b) {
	return Vec3 (
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}

Vec3 Vec3::Abs(const Vec3 a) {
	return Vec3 (
		std::abs(a.x),
		std::abs(a.y),
		std::abs(a.z)
	);
}

Vec3 Vec3::Max(const Vec3 a, const float f) {
	return Vec3 (
		a.x > f ? a.x : f,
		a.y > f ? a.y : f,
		a.z > f ? a.z : f
	);
}

Vec3 Vec3::Min(const Vec3 a, const float f) {
	return Vec3 (
		a.x < f ? a.x : f,
		a.y < f ? a.y : f,
		a.z < f ? a.z : f
	);
}

Vec3 Vec3::Normalize(const Vec3 a) {
	return Vec3(a.x / Vec3::Length(a), a.y / Vec3::Length(a), a.z / Vec3::Length(a));
}

Vec3 Vec3::operator+(const Vec3 other) const {
	return Vec3(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vec3 Vec3::operator-(const Vec3 other) const {
	return Vec3(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vec3 Vec3::operator*(const Vec3 other) const {
	return Vec3(this->x * other.x, this->y * other.y, this->z * other.z);
}

Vec3 Vec3::operator*(const float f) const {
	return Vec3(this->x * f, this->y * f, this->z * f);
}

Vec3 Vec3::operator/(const Vec3 other) const {
	return Vec3(this->x / other.x, this->y / other.y, this->z / other.z);
}

Vec3 Vec3::operator/(const float f) const {
	return Vec3(this->x / f, this->y / f, this->z / f);
}

void Vec3::operator+=(const Vec3 other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
}

void Vec3::operator-=(const Vec3 other) {
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
}

void Vec3::operator*=(const Vec3 other) {
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;
}

void Vec3::operator/=(const Vec3 other) {
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;
}
