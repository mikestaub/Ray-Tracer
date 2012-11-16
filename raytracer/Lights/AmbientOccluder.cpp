#include "AmbientOccluder.h"
#include "ShadeRec.h"
#include "World.h"


// ---------------------------------------------------------------------- default constructor

AmbientOccluder::AmbientOccluder(void)
	: 	Light(),
		ls(1.0),
		color(1.0),
		min_amount(0.25),
		u(0), v(0), w(0),
		sampler_ptr(NULL)
{}


// ---------------------------------------------------------------------- copy constructor

AmbientOccluder::AmbientOccluder(const AmbientOccluder& a)
	: 	Light(a),
		ls(a.ls),
		color(a.color),
		min_amount(a.min_amount),
		u(a.u), v(a.v), w(a.w)
{
	// need to do a deep copy of the sampler
	if(a.sampler_ptr != NULL) {
		sampler_ptr = a.sampler_ptr->clone();
	}
}


// ---------------------------------------------------------------------- clone

Light*
AmbientOccluder::clone(void) const {
	return (new AmbientOccluder(*this));
}


// ---------------------------------------------------------------------- assignment operator

AmbientOccluder&
AmbientOccluder::operator= (const AmbientOccluder& rhs) {

	if (this == &rhs)
		return (*this);

	Light::operator= (rhs);

	ls 		= rhs.ls;
	color 	= rhs.color;
	min_amount = rhs.min_amount;
	u = rhs.u; v = rhs.v; w = rhs.w;

	// need to do a deep copy of the sampler
	if(rhs.sampler_ptr != NULL) {
		sampler_ptr = rhs.sampler_ptr->clone();
	}

	return (*this);
}


// ---------------------------------------------------------------------- destructor

AmbientOccluder::~AmbientOccluder (void) {}


// ---------------------------------------------------------------------- get_direction

Vector3D
AmbientOccluder::get_direction(ShadeRec& sr) {
	Point3D sp = sampler_ptr->sample_hemisphere();
	return (sp.x * u + sp.y * v + sp.z * w);
}	



// ---------------------------------------------------------------------- set_sampler

void
AmbientOccluder::set_sampler(Sampler* s_ptr) {
	if (sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}
	
	sampler_ptr = s_ptr;
	sampler_ptr->map_samples_to_hemisphere(1);
}


// ---------------------------------------------------------------------- L

RGBColor
AmbientOccluder::L(ShadeRec& sr) {

	w = sr.normal;
	v = w ^ Vector3D(0.0072, 1.0, 0.0034); // jitter the up vector in case normal is vertical
	v.normalize();
	u = v ^ w;
	
	Ray shadow_ray;
	shadow_ray.o = sr.hit_point;
	shadow_ray.d = get_direction(sr);
	
	if (in_shadow(shadow_ray, sr))
		return (min_amount * ls * color);
	else
		return (ls * color);
}



// ---------------------------------------------------------------------- in_shadow

bool
AmbientOccluder::in_shadow(const Ray& ray, const ShadeRec& sr) const {

	float 	t;
	int 	num_objects = sr.w.objects.size();
	
	for (int j = 0; j < num_objects; j++)
		if (sr.w.objects[j]->shadow_hit(ray, t))
			return (true);
	
	return (false);
}


// ---------------------------------------------------------------------- G

float
AmbientOccluder::G(const ShadeRec& sr) const{
	return 5.5; //?
}


// ---------------------------------------------------------------------- pdf

float
AmbientOccluder::pdf(const ShadeRec& sr) const{

	return 5.5;//?
}
