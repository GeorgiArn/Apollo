#ifndef APOLLO_MATH_INTERACTION_H
#define APOLLO_MATH_INTERACTION_H

#include "apollo.h"
#include "point3.h"
#include "point2.h"
#include "normal3.h"
#include "vector3.h"
#include "shape.h"
#include "primitive.h"

namespace apollo {

class Interaction {
	public:
		Interaction() {}
		Interaction(const Point3f &p, const Normal3f &n, const Vector3f &wo, float time);
		
		// Accessor methods
		const Point3f& p() const;
		Point3f& p();
		const float& time() const;
		float& time();
		const Vector3f& wo() const;
		Vector3f& wo();
		const Normal3f& n() const;
		Normal3f& n();

	protected:
		// Intersection point
		Point3f _p;
		// Time of intersection
		float _time;
		// Negative ray direction
		Vector3f _wo;
		// Surface normal
		Normal3f _n;
};

// SurfaceInteraction entity represents local information at a point on a surface
class SurfaceInteraction : public Interaction {
	public:
		SurfaceInteraction() {}
		SurfaceInteraction(const Point3f& p, const Normal3f& n, const Point2f& uv, const Vector3f& wo,
				   float time, const Shape *shape);

		// Accessor methods
		const Point2f& uv() const;
		Point2f& uv();

	private:
		// (u,v) coords from the parameterization of the surface
		Point2f _uv;
	public:
		// The shape that the point lies on
		const Shape *shape = nullptr;
		// Hit primitive
		const Primitive *primitive = nullptr;
};

}
#endif
