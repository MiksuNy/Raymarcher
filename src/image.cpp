#include "image.h"

void Image::WritePPM(const char* file_path, const std::vector<Color> &pixel_buffer) {
	std::fstream output_file(file_path, std::fstream::out);

	output_file << "P3\n" << Raymarcher::SCREEN_W << ' ' << Raymarcher::SCREEN_H << "\n255\n";

	for (int y = 0; y < Raymarcher::SCREEN_H; y++) {
		for (int x = 0; x < Raymarcher::SCREEN_W; x++) {
			output_file << Raymarcher::pixel_buffer[x + (y * Raymarcher::SCREEN_W)].r << ' ';
			output_file << Raymarcher::pixel_buffer[x + (y * Raymarcher::SCREEN_W)].g << ' ';
			output_file << Raymarcher::pixel_buffer[x + (y * Raymarcher::SCREEN_W)].b << ' ';
		}
		output_file << '\n';
	}
}
