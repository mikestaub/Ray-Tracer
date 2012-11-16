#ifndef __FLAT_MESH_TRIANGLE__
#define __FLAT_MESH_TRIANGLE__


// FlatMeshTriangle is a MeshTriangle that uses flat shading with a constant normal
// This uses the inherited shadow hit function from MeshTriangle

#include "MeshTriangle.h"

class FlatMeshTriangle: public MeshTriangle {	
	public:
		
		FlatMeshTriangle(void);   									
		
		FlatMeshTriangle(Mesh* _meshPtr, const int i0, const int i1, const int i2);		

		virtual FlatMeshTriangle* 										
		clone(void) const;
	
		FlatMeshTriangle(const FlatMeshTriangle& fmt); 					

		virtual
		~FlatMeshTriangle(void);   									

		FlatMeshTriangle& 												
		operator= (const FlatMeshTriangle& rhs);
				
		virtual	bool
		hit(const Ray& ray, double& tmin, ShadeRec& sr) const;

		virtual bool
		shadow_hit(const Ray& ray, float& tmin) const;
};

#endif

