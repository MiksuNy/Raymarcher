#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "vec.h"

void LoadSceneFromFile(const char* file_path);

float CheckSceneSdf(const Vec3 at_pos);
Vec3 NormalFromSceneSdf(const Vec3 at_pos);

class Sphere {
public:
	Vec3 position;
	float radius;

	inline float sdf(const Vec3 at_pos) const {
		return Vec3::length(at_pos - this->position) - this->radius;
	}
};
