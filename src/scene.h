#pragma once

#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "vec.h"

void LoadSceneFromFile(const char* file_path);

// Return the minimum distance to a 3D point in the scene
float CheckSceneSdf(const Vec3 at_pos);

Vec3 NormalFromSceneSdf(const Vec3 at_pos);

class Sphere {
public:
	Vec3 position;
	float radius = 0.0f;

	inline float sdf(const Vec3 at_pos) const {
		return Vec3::length(at_pos - this->position) - this->radius;
	}
};
