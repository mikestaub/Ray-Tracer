#ifndef __GLOSSYSPECULAR__
#define __GLOSSYSPECULAR__

#include "BRDF.h"
#include "Sampler.h"

class GlossySpecular: public BRDF {

	public:

		GlossySpecular(void);

		GlossySpecular(const GlossySpecular& gloss);

		virtual GlossySpecular*
		clone(void) const;

		~GlossySpecular(void);

		GlossySpecular&
		operator= (const GlossySpecular& rhs);

		virtual RGBColor
		f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;

		virtual RGBColor
		sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, float& pdf) const;

		virtual RGBColor
		rho(const ShadeRec& sr, const Vector3D& wo) const;

		void
		set_ks(const float ks);

		void
		set_exp(const float _e);

		void
		set_cs(const RGBColor& c);

		void
		set_cs(const float r, const float g, const float b);

		void
		set_cs(const float c);

		void
		set_sampler(Sampler* sp, const float exp);				// any type of sampling

		void
		set_samples(const int num_samples, const float exp);	// multi jittered sampling

		void
		set_normal(const Normal& n);

	private:

		float		ks;				// specular reflection coefficient
		float		exp;			// specular exponent
		RGBColor 	cs;				// specular color
		Sampler*	sampler_ptr;	// for use in sample_f
};


// -------------------------------------------------------------- set_ks

inline void
GlossySpecular::set_ks(const float k) {
	ks = k;
}

// -------------------------------------------------------------- set_exp

inline void
GlossySpecular::set_exp(const float e) {
	exp= e;
}


// -------------------------------------------------------------- set_cs

inline void
GlossySpecular::set_cs(const RGBColor& c) {
	cs = c;
}


// ---------------------------------------------------------------- set_cs

inline void
GlossySpecular::set_cs(const float r, const float g, const float b) {
	cs.r = r; cs.g = g; cs.b = b;
}


// ---------------------------------------------------------------- set_cs

inline void
GlossySpecular::set_cs(const float c) {
	cs.r = c; cs.g = c; cs.b = c;
}

#endif
