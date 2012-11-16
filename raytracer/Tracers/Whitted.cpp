#include "Whitted.h"
#include "World.h"
#include "ShadeRec.h"
#include "Material.h"

// -------------------------------------------------------------------- default constructor

Whitted::Whitted(void)
	: Tracer()
{}


// -------------------------------------------------------------------- constructor
		
Whitted::Whitted(World* _worldPtr)
	: Tracer(_worldPtr)
{}


// -------------------------------------------------------------------- destructor

Whitted::~Whitted(void) {}


// -------------------------------------------------------------------- trace_ray
// explained on page 499
RGBColor	
Whitted::trace_ray(const Ray ray, const int depth) const {
	if (depth > world_ptr->vp.max_depth)
		return(black);
	else {
		ShadeRec sr(world_ptr->hit_objects(ray));    
					
		if (sr.hit_an_object) {
			sr.depth = depth;
			sr.ray = ray;	
			return (sr.material_ptr->shade(sr));   
		}
		else
			return (world_ptr->background_color);
	}
}
