#ifndef __TORUS__
#define __TORUS__

#include "GeometricObject.h"
#include "BBox.h"

class Torus: public GeometricObject {
	public:
		
		Torus(void);   									
		
		Torus(const double _a, const double _b);

		virtual Torus* 									
		clone(void) const;
	
		Torus(const Torus& torus);
		
		virtual
		~Torus(void); 											
		
		Torus& 
		operator= (Torus& rhs);	
		
		Normal 					
		compute_normal(const Point3D& p) const;  												
		
		virtual bool 																 
		hit(const Ray& ray, double& tmin, ShadeRec& sr) const;

		virtual bool 																 
		shadow_hit(const Ray& ray, float& tmin) const;
		
	private:
	
		double 		a;	 	// swept radius 
		double		b;	 	// tube radius
		BBox		bbox;	// the bounding box
};

#endif
