#ifndef __WHITTED__
#define __WHITTED__

#include "Tracer.h"

class Whitted: public Tracer {
	public:
		
		Whitted(void);
		
		Whitted(World* _worldPtr);
		
		virtual											
		~Whitted(void);
	
		virtual RGBColor	
		trace_ray(const Ray ray, const int depth) const;
};

#endif
