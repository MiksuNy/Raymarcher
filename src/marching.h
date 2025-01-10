#pragma once

#include <fstream>

#include "scene.h"
#include "ray.h"
#include "color.h"

namespace Raymarcher {
	const int SCREEN_W = 640;
	const int SCREEN_H = 480;
	const float ASPECT = float(SCREEN_W) / float(SCREEN_H);
	const float CAM_DIR_Z = -1.0;
	const Vec3 CAM_POS = Vec3(0.0, 0.0, 5.0);
	const float HIT_THRESHOLD = 0.0005;
	const int MAX_STEPS = 512;

	extern std::vector<Color> pixel_buffer;

	// Renders the scene and stores pixels into pixel_buffer
	void Raymarch();

	// Transform pixel coordinates to normalized view direction
	Vec3 ScreenToViewDir(int x, int y, float z = CAM_DIR_Z);
}
