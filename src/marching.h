#pragma once

#include <fstream>

#include "scene.h"
#include "ray.h"

constexpr int SCREEN_W = 640;
constexpr int SCREEN_H = 480;
constexpr float ASPECT = float(SCREEN_W) / float(SCREEN_H);
constexpr float CAM_DIR_Z = -1.0;
constexpr float HIT_THRESHOLD = 0.0005;
constexpr int MAX_STEPS = 512;

// max_steps: how many steps the ray can take per bounce
// max_bounces: how many times the ray can bounce around the scene for indirect lighting
// file: output image file, function is not responsible for opening and closing the file
void RayMarch(const int max_steps, const int max_bounces, std::fstream& file);

// Transform pixel coordinates to Vec3 direction for a view ray
Vec3 screenToViewDir(int x, int y, float z = CAM_DIR_Z);
