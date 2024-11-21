#pragma once

#include <fstream>

#include "scene.h"
#include "ray.h"

const int SCREEN_W = 640;
const int SCREEN_H = 480;
const float ASPECT = float(SCREEN_W) / float(SCREEN_H);
const float CAM_DIR_Z = -1.0;
const Vec3 CAM_POS = Vec3(0.0, 0.0, 5.0);
const float HIT_THRESHOLD = 0.0005;
const int MAX_STEPS = 256;

// file: output image file, function is not responsible for opening and closing the file
void RayMarch(std::fstream& file);

// Transform pixel coordinates to Vec3 direction for a view ray
Vec3 screenToViewDir(int x, int y, float z = CAM_DIR_Z);
