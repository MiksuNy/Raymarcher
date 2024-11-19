#include "marching.h"

void RayMarch(std::fstream& file) {
	file << "P3\n" << SCREEN_W << " " << SCREEN_H << "\n255\n";

	for (int y = SCREEN_H; y > 0; y--) {
		for (int x = 0; x < SCREEN_W; x++) {
			Ray ray(CAM_POS, screenToViewDir(x, y));

			int steps = 0;
			Vec3 hit_normal;
			while (steps < MAX_STEPS) {
				float dist = CheckSceneSdf(ray.origin);

				if (dist < HIT_THRESHOLD && dist > -HIT_THRESHOLD) {
					hit_normal = NormalFromSceneSdf(ray.origin);
					break;
				} else if (dist > 10000.0) {
					break;
				} else {
					ray.origin += ray.direction * dist;
					steps++;
				}
			}
			// Kerrotaan 255 jotta saadaan 0-255 väriarvo
			//file << floor(hit_normal.x * 255.0) << " " << floor(hit_normal.y * 255.0) << " " << floor(hit_normal.z * 255.0) << " ";
			file << floor((float(steps) / float(MAX_STEPS)) * 255) << " " << "0" << " " << "0" << " ";
		}
		file << "\n";
	}
}

Vec3 screenToViewDir(int x, int y, float z) {
	return Vec3::normalized(Vec3((float(x) / float(SCREEN_W) - 0.5) * ASPECT, float(y) / float(SCREEN_H) - 0.5, z));
}
