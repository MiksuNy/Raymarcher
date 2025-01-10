#include "marching.h"
#include "scene.h"
#include "image.h"

int main() {
	Scene::LoadFromFile("../res/test.scene");

	Raymarcher::Raymarch();

	Image::WritePPM("../out/image.ppm", Raymarcher::pixel_buffer);
}
