#include "scene.h"

std::vector<Sphere> scene_spheres;

// TODO: Load camera and other types of primitives from scene files
void Scene::LoadFromFile(const char* file_path) {
	std::fstream file(file_path, std::fstream::in);
	std::string line;
	while (getline(file, line)) {
		if (line.substr(0, 6) == "sphere") {
			Sphere s;
			sscanf_s(line.c_str(), "sphere %lf %lf %lf %f", &s.position.x, &s.position.y, &s.position.z, &s.radius);
			std::cout << "Found sphere at pos: " << s.position.x << ", " << s.position.y << ", " << s.position.z << "\n";
			std::cout << "With radius: " << s.radius << "\n\n";
			scene_spheres.push_back(s);
		}
	}
	file.close();
}

float Scene::CheckSdf(const Vec3 at_pos) {
	float final_dist = 10000000000.0f;
	for (Sphere& s : scene_spheres) {
		float temp_dist = s.sdf(at_pos);
		final_dist = (final_dist > temp_dist) ? temp_dist : final_dist;
	}
	return final_dist;
}

Vec3 Scene::NormalAt(const Vec3 at_pos) {
	float offset = 0.001;

	Vec3 v1(
		CheckSdf(at_pos + Vec3(offset, 0.0, 0.0)),
		CheckSdf(at_pos + Vec3(0.0, offset, 0.0)),
		CheckSdf(at_pos + Vec3(0.0, 0.0, offset))
	);

	Vec3 v2(
		CheckSdf(at_pos - Vec3(offset, 0.0, 0.0)),
		CheckSdf(at_pos - Vec3(0.0, offset, 0.0)),
		CheckSdf(at_pos - Vec3(0.0, 0.0, offset))
	);

	return Vec3::normalized(Vec3(v1 - v2));
}
