#pragma once
#include <math.h>

float clamp(float value, float min, float max) {
	return fmax(fmin(value, max), min);
}