#pragma once

#include <vector>
#include <fstream>

#include "color.h"
#include "marching.h"

namespace Image {
	void WritePPM(const char* file_path, const std::vector<Color>& pixel_buffer);
};
