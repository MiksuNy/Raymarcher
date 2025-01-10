#pragma once

#include <cmath>

class Color {
public:
	unsigned int r = 0;
	unsigned int g = 0;
	unsigned int b = 0;
	unsigned int a = 0;

	// Converts floats (between 0.0 and 1.0) to unsigned integers (between 0 and 255)
	static Color ConvertToColor(float r, float g, float b, float a);

private:
	static unsigned int ConvertToUInt(float f);
};
