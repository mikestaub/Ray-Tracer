#include "EnvironmentLight.h"

// ---------------------------------------------------------------- default constructor

EnvironmentLight::EnvironmentLight(void)
	: 	Light(),
		sampler_ptr(NULL),
		material_ptr(NULL),
		u(), v(), w(),
		wi()
{}	


// ---------------------------------------------------------------- copy constructor

EnvironmentLight::EnvironmentLight(const EnvironmentLight& el)
	: 	Light(el),
		u(el.u), v(el.v), w(el.w),
		wi(el.wi)
{
	if(el.sampler_ptr)
		sampler_ptr = el.sampler_ptr->clone(); 
	else  sampler_ptr = NULL;

	if(el.material_ptr)
		material_ptr = el.material_ptr->clone(); 
	else  material_ptr = NULL;
}


// ---------------------------------------------------------------- clone

Light*
EnvironmentLight::clone(void) const {
	return (new EnvironmentLight(*this));
}


// ---------------------------------------------------------------- destructor

EnvironmentLight::~EnvironmentLight(void) {

	if (sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}

	if (material_ptr) {
		delete material_ptr;
		material_ptr = NULL;
	}
}


// --------------------------------------------------------------- assignment operator

EnvironmentLight&
EnvironmentLight::operator= (const EnvironmentLight& rhs) {

	if (this == &rhs)
		return (*this);

	Light::operator=(rhs);

	if (sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}

	if (rhs.sampler_ptr)
		sampler_ptr = rhs.sampler_ptr->clone();

	if (material_ptr) {
		delete material_ptr;
		material_ptr = NULL;
	}

	if (rhs.material_ptr)
		material_ptr = rhs.material_ptr->clone();

	return (*this);
}


// --------------------------------------------------------------- get_direction

Vector3D
EnvironmentLight::get_direction(ShadeRec& sr) {

	w = sr.normal;
	v = Vector3D(0.0034, 1, 0.0071) ^ w;
	v.normalize();
	u = v ^ w;
	Point3D sp = sampler_ptr->sample_hemisphere();
	wi = sp.x * u + sp.y * v + sp.z * w;

	return (wi);
}


// ---------------------------------------------------------------------- set_sampler

void
EnvironmentLight::set_sampler(Sampler* s_ptr) {

	if (sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}
	
	sampler_ptr = s_ptr;
	sampler_ptr->map_samples_to_hemisphere(1);
}


// --------------------------------------------------------------- L

RGBColor
EnvironmentLight::L(ShadeRec& sr) {
	return (material_ptr->get_Le(sr));
}


// ---------------------------------------------------------------------- in_shadow
// not sure if this is correct, copied it from poitn light...
bool
EnvironmentLight::in_shadow(const Ray& ray, const ShadeRec& sr) const {

	return false; // can an environment light even be in shadow?
}


// ---------------------------------------------------------------- pdf
// The following function is not in the book.
// It uses Equation 18.6
float
EnvironmentLight::pdf(const ShadeRec& sr) const {

	return (sr.normal * wi * invPI);
}
