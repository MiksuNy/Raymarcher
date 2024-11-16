#include "ray.h"

Ray::Ray(Vec3 origin, Vec3 direction) {
	this->origin = origin;
	this->direction = direction;
}

Vec3 Ray::at(const float t) {
	return Vec3(origin + direction * t);
}
