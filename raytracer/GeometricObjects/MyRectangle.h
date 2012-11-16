#ifndef __MYRectangle__
#define __MYRectangle__

#include "Sampler.h"
#include "GeometricObject.h"

class MyRectangle: public GeometricObject {

	public:
		
		MyRectangle(void);   									
				
		MyRectangle(const Point3D& _p0, const Vector3D& _a, const Vector3D& _b);
		
		MyRectangle(const Point3D& _p0, const Vector3D& _a, const Vector3D& _b, const Normal& n);
		
		virtual MyRectangle* 										
		clone(void) const;
	
		MyRectangle(const MyRectangle& r); 						

		virtual													
		~MyRectangle(void);   									

		MyRectangle& 												
		operator= (const MyRectangle& rhs);
		
		//BBox
		//get_bounding_box(void);				
	
		virtual bool 												 
		hit(const Ray& ray, double& t, ShadeRec& s) const;

		virtual bool
		shadow_hit(const Ray& ray, float& tmin) const;
				
		
		// the following functions are used when the MyRectangle is a light source
		
		virtual void 								
		set_sampler(Sampler* sampler); 
				
		virtual Point3D 											
		sample(void);
		
		virtual Normal 																
		get_normal(const Point3D& p);		
		
		virtual float												
		pdf(ShadeRec& sr);
		
	private:
	
		Point3D 		p0;   			// corner vertex 
		Vector3D		a;				// side
		Vector3D		b;				// side
		double			a_len_squared;	// square of the length of side a
		double			b_len_squared;	// square of the length of side b
		Normal			normal;	
		
		float			area;			// for rectangular lights
		float			inv_area;		// for rectangular lights
		Sampler*		sampler_ptr;	// for rectangular lights 	
		
		static const double kEpsilon;   											
};

#endif
