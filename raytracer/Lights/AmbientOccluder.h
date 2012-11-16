#ifndef __AMBIENTOCCLUDER__
#define __AMBIENTOCCLUDER__

#include "Light.h"
#include "Sampler.h"

class AmbientOccluder: public Light {

	public:

		AmbientOccluder(void);

		AmbientOccluder(const AmbientOccluder& a);

		virtual Light*
		clone(void) const;

		AmbientOccluder&
		operator= (const AmbientOccluder& rhs);

		virtual
		~AmbientOccluder(void);

		void
		scale_radiance(const float b);

		void
		set_color(const float c);

		void
		set_color(const RGBColor& c);

		void
		set_color(const float r, const float g, const float b);

		void
		set_min_amount(int n);

		virtual Vector3D
		get_direction(ShadeRec& sr);

		void
		set_sampler(Sampler* s_ptr);

		virtual RGBColor
		L(ShadeRec& s);

		bool
		in_shadow(const Ray& ray, const ShadeRec& sr) const;

		virtual bool
		casts_shadows(void) const;

		virtual void
		set_shadows(bool _s);

		virtual float
		G(const ShadeRec& sr) const;

		virtual float
		pdf(const ShadeRec& sr) const;

	private:

		float		ls;
		RGBColor	color;
		float		min_amount;
		Vector3D	u, v, w;
		Sampler*	sampler_ptr;
};


// ------------------------------------------------------------------------------- scale_radiance

inline void
AmbientOccluder::scale_radiance(const float b) {
	ls = b;
}


// ------------------------------------------------------------------------------- set_color

inline void
AmbientOccluder::set_min_amount(int n) {
	min_amount = n;
}


// ------------------------------------------------------------------------------- set_color

inline void
AmbientOccluder::set_color(const float c) {
	color.r = c; color.g = c; color.b = c;
}


// ------------------------------------------------------------------------------- set_color

inline void
AmbientOccluder::set_color(const RGBColor& c) {
	color = c;
}


// ------------------------------------------------------------------------------- set_color

inline void
AmbientOccluder::set_color(const float r, const float g, const float b) {
	color.r = r; color.g = g; color.b = b;
}


// ---------------------------------------------------------------------- casts_shadows

inline bool
AmbientOccluder::casts_shadows() const {

	return Light::casts_shadows();
}


// ---------------------------------------------------------------------- set_shadows

inline void
AmbientOccluder::set_shadows(bool _s) {

	return Light::set_shadows(_s);
}

#endif
