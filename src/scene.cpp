#include "scene.h"

std::vector<Sphere> scene_spheres;

void LoadSceneFromFile(const char* file_path) {
	std::fstream file(file_path, std::fstream::in);
	std::string line;
	while (getline(file, line)) {
		Sphere s;
		sscanf_s(line.c_str(), "sphere %lf %lf %lf %f", &s.position.x, &s.position.y, &s.position.z, &s.radius);
		std::cout << s.position.x << ", " << s.position.y << ", " << s.position.z << "\n";
		std::cout << s.radius << "\n";
		scene_spheres.push_back(s);
	}
	file.close();
}

// Palauttaa pienimmän turvallisen välimatkan scenen objektiin
float CheckSceneSdf(const Vec3 at_pos) {
	float final_dist = 10000000000.0f;
	for (Sphere s : scene_spheres) {
		float temp_dist = s.sdf(at_pos);
		final_dist = std::min(final_dist, temp_dist);
	}
	return final_dist;
}

Vec3 NormalFromSceneSdf(const Vec3 at_pos) {
	float offset = 0.001;

	Vec3 v1(
		CheckSceneSdf(at_pos + Vec3(offset, 0.0, 0.0)),
		CheckSceneSdf(at_pos + Vec3(0.0, offset, 0.0)),
		CheckSceneSdf(at_pos + Vec3(0.0, 0.0, offset))
	);

	Vec3 v2(
		CheckSceneSdf(at_pos - Vec3(offset, 0.0, 0.0)),
		CheckSceneSdf(at_pos - Vec3(0.0, offset, 0.0)),
		CheckSceneSdf(at_pos - Vec3(0.0, 0.0, offset))
	);

	return Vec3::normalized(Vec3(v1 - v2));
}
