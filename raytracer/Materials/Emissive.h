#ifndef __EMISSIVE__
#define __EMISSIVE__

#include "Material.h"

//----------------------------------------------------------------------------- class Emissive

class Emissive: public Material {

	public:

		Emissive(void);

		Emissive(const Emissive& m);

		virtual Material*
		clone(void) const;

		Emissive& 
		operator= (const Emissive& rhs);

		~Emissive(void);

		void
		scale_radiance(const float _ls);

		void
		set_ce(const float r, const float g, const float b);

		virtual RGBColor
		get_Le(ShadeRec& sr) const;

		virtual RGBColor
		shade(ShadeRec& sr);

		virtual RGBColor
		area_light_shade(ShadeRec& sr);

	private:

		float ls;		// radiance scaling facor
		RGBColor ce;	// color
};


// ---------------------------------------------------------------- scale_radiance

inline void
Emissive::scale_radiance(const float _ls){
	ls = _ls;
}


// ---------------------------------------------------------------- set_ce

inline void
Emissive::set_ce(const float r, const float g, const float b){
	ce.r = r; ce.g = g; ce.b = b;
}

#endif
