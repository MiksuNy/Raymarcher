#include "scene.h"

namespace Scene {
	std::vector<Sphere> scene_spheres;
	std::vector<Box> scene_boxes;
}

// TODO: Load camera and other types of primitives from scene files
void Scene::LoadFromFile(const char* file_path) {
	std::fstream file(file_path, std::fstream::in);
	std::string line;

	while (getline(file, line)) {
		if (line.substr(0, 6) == "sphere") {
			Sphere s;
			sscanf_s(line.c_str(), "sphere position %lf %lf %lf radius %f", &s.position.x, &s.position.y, &s.position.z, &s.radius);
			scene_spheres.push_back(s);
		}
		else if (line.substr(0, 3) == "box") {
			Box b;
			sscanf_s (
				line.c_str(), "box position %lf %lf %lf bounds %lf %lf %lf",
				&b.position.x, &b.position.y, &b.position.z,
				&b.bounds.x, &b.bounds.y, &b.bounds.z
			);
			scene_boxes.push_back(b);
		}
	}
	file.close();
}

float Scene::CheckSdf(const Vec3 at_pos) {
	float final_dist = 10000000000.0f;
	for (Sphere& s : scene_spheres) {
		const float temp_dist = s.Sdf(at_pos);
		final_dist = (final_dist > temp_dist) ? temp_dist : final_dist;
	}
	for (Box& b : scene_boxes) {
		const float temp_dist = b.Sdf(at_pos);
		final_dist = (final_dist > temp_dist) ? temp_dist : final_dist;
	}
	return final_dist;
}

Vec3 Scene::NormalAt(const Vec3 at_pos) {
	const double offset = 0.0001;

	const Vec3 v1(
		CheckSdf(at_pos + Vec3(offset, 0.0, 0.0)),
		CheckSdf(at_pos + Vec3(0.0, offset, 0.0)),
		CheckSdf(at_pos + Vec3(0.0, 0.0, offset))
	);

	const Vec3 v2(
		CheckSdf(at_pos - Vec3(offset, 0.0, 0.0)),
		CheckSdf(at_pos - Vec3(0.0, offset, 0.0)),
		CheckSdf(at_pos - Vec3(0.0, 0.0, offset))
	);

	return Vec3::Normalize(Vec3(v1 - v2));
}
