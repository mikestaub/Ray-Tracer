#ifndef __POINTLIGHT__
#define __POINTLIGHT__

#include "Light.h"
#include "ShadeRec.h"

class PointLight: public Light {

	public:

		PointLight(void);

		PointLight(const PointLight& a);

		virtual Light*
		clone(void) const;

		PointLight&
		operator= (const PointLight& rhs);

		virtual
		~PointLight(void);

		virtual Vector3D
		get_direction(ShadeRec& sr);

		virtual RGBColor
		L(ShadeRec& sr);

		virtual bool
		casts_shadows(void) const;

		virtual void
		set_shadows(bool _s);

		void
		set_location(float x, float y, float z);

		void
		scale_radiance(float _r);

		bool
		in_shadow(const Ray& ray, const ShadeRec& sr) const;

		virtual float
		G(const ShadeRec& sr) const;

		virtual float
		pdf(const ShadeRec& sr) const;

	private:
		
		float 		ls;		// radiant scale factor
		RGBColor 	color;
		Point3D 	location;
};


// ---------------------------------------------------------------------- casts_shadows

inline bool
PointLight::casts_shadows() const {

	return Light::casts_shadows();
}


// ---------------------------------------------------------------------- set_shadows

inline void
PointLight::set_shadows(bool _s) {

	return Light::set_shadows(_s);
}


// ---------------------------------------------------------------------- set_location

inline void
PointLight::set_location(float _x, float _y, float _z) {
	location.x = _x; location.y = _y; location.z = _z;
}


// ---------------------------------------------------------------------- scale_radiance

inline void
PointLight::scale_radiance(float _r) {
	ls *= _r;
}

#endif
