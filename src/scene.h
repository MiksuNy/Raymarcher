#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "vec.h"

class Sphere;
class Box;

namespace Scene {
	extern std::vector<Sphere> scene_spheres;
	extern std::vector<Box> scene_boxes;

	void LoadFromFile(const char* file_path);

	// Return the minimum distance to a 3D point in the scene
	float CheckSdf(const Vec3 at_pos);

	// Checks scene distance at a few offsets to determine normal direction
	Vec3 NormalAt(const Vec3 at_pos);
}

// Signed distance functions are from https://iquilezles.org/articles/distfunctions/

class Sphere {
public:
	Vec3 position;
	float radius = 0.0f;

	inline float Sdf(const Vec3 at_pos) const {
		return Vec3::Length(at_pos - this->position) - this->radius;
	}
};

class Box {
public:
	Vec3 position;
	Vec3 bounds;

	inline float Sdf(const Vec3 at_pos) const {
		const Vec3 q = Vec3::Abs(at_pos - this->position) - bounds;
		return Vec3::Length(Vec3::Max(q, 0.0)) + std::min(std::max(q.x, std::max(q.y, q.z)), 0.0);
	}
};
