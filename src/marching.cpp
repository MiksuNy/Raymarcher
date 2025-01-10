#include "marching.h"

namespace Raymarcher {
	std::vector<Color> pixel_buffer;
}

void Raymarcher::Raymarch() {
	for (int y = SCREEN_H; y > 0; y--) {
		for (int x = 0; x < SCREEN_W; x++) {

			Ray ray(CAM_POS, ScreenToViewDir(x, y));

			unsigned int steps = 0;
			Vec3 hit_normal;
			while (steps < MAX_STEPS) {
				float dist = Scene::CheckSdf(ray.origin);

				if (dist < HIT_THRESHOLD) {
					hit_normal = Scene::NormalAt(ray.origin);
					break;
				} else if (dist > 1000.0) { // Ray too far from anything
					break;
				} else {
					ray.origin += ray.direction * dist;
					steps++;
				}
			}
			const float color_value = (float)steps / (float)MAX_STEPS;
			Color final_color = Color::ConvertToColor(color_value, color_value, color_value, 0.0);
			pixel_buffer.push_back(final_color);
			// TODO: Alpha channel unused in PPM format, add it later for other formats
		}
		std::cout << "Lines remaining: " << y << "\n";
	}
}

Vec3 Raymarcher::ScreenToViewDir(int x, int y, float z) {
	return Vec3::Normalize(Vec3((float(x) / float(SCREEN_W) - 0.5) * ASPECT, float(y) / float(SCREEN_H) - 0.5, z));
}
