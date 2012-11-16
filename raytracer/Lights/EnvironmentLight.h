#ifndef __ENVIRONMENT_LIGHT__
#define __ENVIRONMENT_LIGHT__

#include "Light.h"
#include "Sampler.h"
#include "Material.h"

class EnvironmentLight: public Light {

	public:

		EnvironmentLight(void);

		EnvironmentLight(const EnvironmentLight& al);

		virtual Light*
		clone(void) const;

		virtual
		~EnvironmentLight(void);

		EnvironmentLight&
		operator= (const EnvironmentLight& rhs);

		void
		set_sampler(Sampler* sampler);

		void
		set_material(Material* material);

		virtual Vector3D
		get_direction(ShadeRec& s);

		virtual RGBColor
		L(ShadeRec& sr);

		virtual bool
		in_shadow(const Ray& ray, const ShadeRec& sr) const;

		virtual float
		pdf(const ShadeRec& sr) const;

		virtual bool
		casts_shadows(void) const;

		virtual void
		set_shadows(bool _s);

	private:

		Sampler* sampler_ptr;
		Material* material_ptr;
		Vector3D u, v, w;
		Vector3D			wi;				// unit direction from hit point being shaded to sample point on light surface
};


// ---------------------------------------------------------------------- casts_shadows

inline bool
EnvironmentLight::casts_shadows() const {

	return Light::casts_shadows();
}


// ---------------------------------------------------------------------- set_shadows

inline void
EnvironmentLight::set_shadows(bool _s) {

	return Light::set_shadows(_s);
}


// --------------------------------------------------------------- set_material

inline void
EnvironmentLight::set_material(Material* mat_ptr) {
	material_ptr = mat_ptr;
}

#endif
