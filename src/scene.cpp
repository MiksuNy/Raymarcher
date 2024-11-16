#include "scene.h"

extern std::vector<Object> scene_objects;

void LoadSceneFromFile(const char* file_path) {
	std::fstream file(file_path, std::fstream::in);
	std::string line;
	while (getline(file, line)) {
		if (line.substr(0, 6) == "sphere ") {
			Sphere s;
			sscanf_s(line.c_str(), "sphere %f %f %f %f", &s.position.x, &s.position.y, &s.position.z, &s.radius);
			scene_objects.push_back(s);
		}
	}
	file.close();
}

// Palauttaa pienimmän turvallisen välimatkan scenen objektiin
float CheckSceneSdf(const Vec3 at_pos) {
	float final_dist = 10000000000.0f;
	for (Object o : scene_objects) {
		float temp_dist = o.checkSdf(at_pos);
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

float Sphere::checkSdf(const Vec3 at_pos) {
	return Vec3::length(at_pos - this->position) - this->radius;
}