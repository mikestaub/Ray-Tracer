#ifndef __MESH__
#define __MESH__

// A mesh object stores the data for mesh triangles:
//
//			vertices
//			normals
//			uv texture coordinates
//			lists of triangles that share each vertex
//
// Mesh triangles are stored in a grid, which has a pointer to the mesh
// Each mesh triangle also has a pointer to the mesh
// The Mesh class does not inherit from GeometricObject

#include <vector>
using std::vector;

#include "Point3D.h"
#include "Normal.h"
	
class Mesh {										  	
	public:

		vector<Point3D> 		vertices;				// mesh vertices 
		vector<Normal> 			normals;				// average normal at each vertex;
		vector<float>			u;						// u texture coordinate at each vertex
		vector<float>			v;						// v texture coordinate at each vertex
		vector<vector<int> > 	vertex_faces;			// the triangles shared by each vertex
		int 					num_vertices; 			// number of vertices
		int 					num_triangles; 			// number of triangles
		
		Mesh(void);   								
			
		Mesh(const Mesh& m); 						

		~Mesh(void);   							

		Mesh& 										
		operator= (const Mesh& rhs);
};

#endif


