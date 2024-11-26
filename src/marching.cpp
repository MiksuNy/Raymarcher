#include "marching.h"

namespace Raymarcher {
	std::vector<char> pixel_buffer;
}

void Raymarcher::Raymarch() {
	for (int y = SCREEN_H; y > 0; y--) {
		for (int x = 0; x < SCREEN_W; x++) {
			Ray ray(CAM_POS, screenToViewDir(x, y));

			int steps = 0;
			Vec3 hit_normal;
			while (steps < MAX_STEPS) {
				float dist = Scene::CheckSdf(ray.origin);

				if (dist < HIT_THRESHOLD && dist > -HIT_THRESHOLD) {
					hit_normal = Scene::NormalAt(ray.origin);
					break;
				} else if (dist > 1000.0) {
					break;
				} else {
					ray.origin += ray.direction * dist;
					steps++;
				}
			}
			pixel_buffer.push_back(char(steps * 255)); // R
			pixel_buffer.push_back(char(steps * 255)); // G
			pixel_buffer.push_back(char(steps * 255)); // B
			pixel_buffer.push_back(char(255));         // A
		}
	}
}

Vec3 Raymarcher::screenToViewDir(int x, int y, float z) {
	return Vec3::normalized(Vec3((float(x) / float(SCREEN_W) - 0.5) * ASPECT, float(y) / float(SCREEN_H) - 0.5, z));
}
