#include "marching.h"
#include "scene.h"

int main() {
	Scene::LoadFromFile("../res/test.scene");

	Raymarcher::Raymarch();

	std::cout << "Pixel data in kilobytes: " << Raymarcher::pixel_buffer.size() / 1024 << std::endl;
}
