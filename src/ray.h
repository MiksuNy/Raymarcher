#pragma once


#include "vec.h"

class Ray {
public:
	Vec3 origin;
	Vec3 direction;

	Ray() = default;
	Ray(Vec3 origin, Vec3 direction);
};
