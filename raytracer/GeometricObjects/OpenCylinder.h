#ifndef __OPEN_CYLINDER__
#define __OPEN_CYLINDER__

// An open cylinder is defined by its extent in the y direction and its radius.
// It is centered on the y axis.
// The classes ConcaveOpenCylinder and ConvexOpenCylinder can inherit from OpenCylinder.
// The classes ConcavePartCylinder and ConvexPartCylinder can in turn inherit from these.

#include "GeometricObject.h"

class OpenCylinder: public GeometricObject {
	
	public:
		
		OpenCylinder(void);   									

		OpenCylinder(const double bottom, const double top, const double radius);

		OpenCylinder(const OpenCylinder& c); 					
		
		virtual OpenCylinder* 									
		clone (void) const;

		OpenCylinder& 											
		operator= (const OpenCylinder& rhs);		
		
		virtual 												
		~OpenCylinder(void);
						
		virtual bool
		hit(const Ray& ray, double& t, ShadeRec& sr) const;

		virtual bool
		shadow_hit(const Ray& ray, float& t) const;
		
	protected:
	
		double		y0;				// bottom y value
		double		y1;				// top y value
		double		radius;			// radius
		double		inv_radius;  	// one over the radius	
};

#endif
