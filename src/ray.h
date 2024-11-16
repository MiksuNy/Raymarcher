#pragma once

#include "vec.h"

class Ray {
public:
	Vec3 origin;
	Vec3 direction;

	Ray() = default;
	Ray(Vec3 origin, Vec3 direction);

	// Palauttaa Vec3 sijainnin säteen matkalta pituudelta t
	Vec3 at(const float t);

	inline static float sdfSphere(const Vec3& sphere_center, const double radius, const Vec3& ray_origin) {
		return Vec3::length(ray_origin - sphere_center) - radius;
	}
};
