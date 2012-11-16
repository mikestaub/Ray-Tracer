#ifndef __SMOOTH_MESH_TRIANGLE__
#define __SMOOTH_MESH_TRIANGLE__

// SmoothMeshTriangle is a MeshTriangle that uses smooth shading with an interpolated normal at each hit point

#include "MeshTriangle.h"

class SmoothMeshTriangle: public MeshTriangle {		
	public:
		
		SmoothMeshTriangle(void);   									
		
		SmoothMeshTriangle(Mesh* _meshPtr, const int i0, const int i1, const int i2);		

		virtual SmoothMeshTriangle* 										
		clone(void) const;
	
		SmoothMeshTriangle(const SmoothMeshTriangle& fmt); 					

		virtual
		~SmoothMeshTriangle(void);   									

		SmoothMeshTriangle& 												
		operator= (const SmoothMeshTriangle& rhs);
				
		virtual	bool 
		hit(const Ray& ray, double& tmin, ShadeRec& sr) const;

		virtual bool
		shadow_hit(const Ray& ray, float& tmin) const;

	protected:
	
		Normal 
		interpolate_normal(const float beta, const float gamma) const;
};

#endif

