#ifndef __Box__
#define __Box__

#include "Sampler.h"
#include "GeometricObject.h"

class Box: public GeometricObject {

	public:
		
		Box(void);   									
				
		Box(const Point3D& _p0, const Vector3D& _a, const Vector3D& _b);
		
		Box(const Point3D& _p0, const Vector3D& _a, const Vector3D& _b, const Normal& n);
		
		virtual Box* 										
		clone(void) const;
	
		Box(const Box& r); 						

		virtual													
		~Box(void);   									

		Box& 												
		operator= (const Box& rhs);
		
		//Box
		//get_bounding_box(void);				
	
		virtual bool 												 
		hit(const Ray& ray, double& t, ShadeRec& s) const;

		virtual bool
		shadow_hit(const Ray& ray, float& tmin) const;

		Normal
		get_normal(const int face_hit) const;
				
		
	private:
	
		float x0, y0, z0, x1, y1, z1;
		
		static const double kEpsilon;   											
};

#endif
