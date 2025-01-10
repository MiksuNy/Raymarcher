#include "color.h"

Color Color::ConvertToColor(float r, float g, float b, float a) {
	return {
		ConvertToUInt((r > 0.0 ? r : 0.0)),
		ConvertToUInt((g > 0.0 ? g : 0.0)),
		ConvertToUInt((b > 0.0 ? b : 0.0)),
		ConvertToUInt((a > 0.0 ? a : 0.0))
	};
}

unsigned int Color::ConvertToUInt(float f) {
	return (unsigned int)(floor(f * 255.0));
}
