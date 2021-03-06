#ifndef APOLLO_CORE_APOLLO_H
#define APOLLO_CORE_APOLLO_H

#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>
#include <memory>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

namespace apollo {

// Global Forward Declarations
template <typename T> class Vector2;
template <typename T> class Vector3;
template <typename T> class Point2;
template <typename T> class Point3;
template <typename T> class Normal3;
template <typename T> class Bounds2;
template <typename T> class Bounds3;
class Ray;
class Matrix;
class Transform;
class Shape;
class Interaction;
class SurfaceInteraction;
class Primitive;
class RGB;
class Film;
class Camera;
class Light;

// Global constants
static constexpr float Infinity = std::numeric_limits<float>::infinity();
static constexpr float Epsilon = std::numeric_limits<float>::epsilon();
static constexpr float PI = 3.14159265358979323846;
static constexpr float InvPI = 0.31830988618379067154;

// Mathematical routines
// =====================

// Solve quadratic equation
inline bool Quadratic(float a, float b, float c, float &x1, float &x2) {
	// Calculate discriminant
	float d = b * b - 4 * a * c;
	if (d < 0.0f)
		return false;
	
	// Calculate solutions
	float dSqrt = std::sqrt(d);
	x1 = (- b + dSqrt) / (2 * a);
	x2 = (- b - dSqrt) / (2 * a);
	
	if (x1 > x2)
		std::swap(x1, x2);

	return true;
}

// Linear interpolation
inline float Lerp(float t, float x1, float x2) {
	return x1 * (1 - t) + t * x2;
}

// Clamp a variable to a given range
template <typename T, typename U, typename V>
inline T Clamp(T n, U low, V high) {
	if (n < low) 
		return low;
	if (n > high) 
		return high;
	return n;
}

}

#endif
