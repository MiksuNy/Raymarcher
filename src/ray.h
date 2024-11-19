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
};
