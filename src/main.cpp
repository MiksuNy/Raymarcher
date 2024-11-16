#include "marching.h"
#include "scene.h"

std::vector<Object> scene_objects;

int main() {
	std::fstream image_file;
	image_file.open("image.ppm", std::fstream::out);

	LoadSceneFromFile("test.scene");

	RayMarch(256, 4, image_file);

	image_file.close();
}

