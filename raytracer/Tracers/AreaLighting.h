#ifndef __AREA_LIGHTING__
#define __AREA_LIGHTING__

#include "Tracer.h"

class AreaLighting: public Tracer {

	public:

		AreaLighting(void);

		AreaLighting(World* _worldPtr);

		virtual
		~AreaLighting(void);

		virtual RGBColor
		trace_ray(const Ray& ray) const;

		virtual RGBColor
		trace_ray(const Ray ray, const int depth) const;
};

#endif
