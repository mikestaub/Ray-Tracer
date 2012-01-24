#ifndef __AREA_LIGHT__
#define __AREA_LIGHT__

#include "RGBColor.h"
#include "Vector3D.h"
#include "Point3D.h"
#include "Normal.h"
#include "Light.h"
#include "Material.h"
#include "GeometricObject.h"

class AreaLight: public Light {
	public:

		AreaLight(void);

		AreaLight(const AreaLight& al);

		virtual AreaLight*
		clone(void);

		virtual
		~AreaLight(void);

		AreaLight&
		operator= (const AreaLight& rhs);

		void
		set_object(GeometricObject* obj_ptr);

		virtual Vector3D
		get_direction(ShadeRec& s);

		virtual RGBColor
		L(ShadeRec& sr);

		virtual bool
		in_shadow(const Ray& ray, const ShadeRec& sr) const;

		virtual float
		G(const ShadeRec& sr) const;

		virtual float
		pdf(const ShadeRec& sr) const;

		virtual bool
		casts_shadows(void) const;

		virtual void
		set_shadows(bool _s);

	private:

		GeometricObject*	object_ptr;
		Material*			material_ptr;	// will be an emissive material
		Point3D				sample_point;
		Normal				light_normal;	// assigned in get_direction - which therefore can't be const for any light
		Vector3D			wi;				// unit direction from hit point being shaded to sample point on light surface			
	
};


// --------------------------------------------------------------- set_object

inline void
AreaLight::set_object(GeometricObject* obj_ptr) {
	object_ptr = obj_ptr;
	material_ptr = object_ptr->get_material();
}


// ---------------------------------------------------------------------- casts_shadows

inline bool
AreaLight::casts_shadows() const {

	return Light::casts_shadows();
}


// ---------------------------------------------------------------------- set_shadows

inline void
AreaLight::set_shadows(bool _s) {

	return Light::set_shadows(_s);
}

#endif
