#ifndef __AMBIENT__
#define __AMBIENT__

#include "Light.h"

class Ambient: public Light {

	public:

		Ambient(void);

		Ambient(const Ambient& a);

		virtual Light*
		clone(void) const;

		Ambient&
		operator= (const Ambient& rhs);

		virtual
		~Ambient(void);

		void
		scale_radiance(const float b);

		void
		set_color(const float c);

		void
		set_color(const RGBColor& c);

		void
		set_color(const float r, const float g, const float b);

		virtual Vector3D
		get_direction(ShadeRec& sr);

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
};


// ------------------------------------------------------------------------------- scale_radiance

inline void
Ambient::scale_radiance(const float b) {
	ls = b;
}


// ------------------------------------------------------------------------------- set_color

inline void
Ambient::set_color(const float c) {
	color.r = c; color.g = c; color.b = c;
}


// ------------------------------------------------------------------------------- set_color

inline void
Ambient::set_color(const RGBColor& c) {
	color = c;
}


// ------------------------------------------------------------------------------- set_color

inline void
Ambient::set_color(const float r, const float g, const float b) {
	color.r = r; color.g = g; color.b = b;
}


// ---------------------------------------------------------------------- casts_shadows

inline bool
Ambient::casts_shadows() const {

	return Light::casts_shadows();
}


// ---------------------------------------------------------------------- set_shadows

inline void
Ambient::set_shadows(bool _s) {

	return Light::set_shadows(_s);
}

#endif
