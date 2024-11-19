#include "marching.h"
#include "scene.h"

int main() {
	std::fstream image_file;
	image_file.open("../out/image.ppm", std::fstream::out);

	LoadSceneFromFile("../res/test.scene");

	RayMarch(image_file);

	image_file.close();
}
