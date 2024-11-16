#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "vec.h"

class Object;

float CheckSceneSdf(const Vec3 at_pos);
Vec3 NormalFromSceneSdf(const Vec3 at_pos);

void LoadSceneFromFile(const char* file_path);

enum ObjectType {
	SPHERE = 0
};

class Object {
public:
	virtual float checkSdf(const Vec3 at_pos);
};

class Sphere : public Object {
public:
	const ObjectType type = SPHERE;
	Vec3 position;
	float radius;

	float checkSdf(const Vec3 at_pos) override;
};
