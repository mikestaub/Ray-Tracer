#include "MultiJittered.h"
#include "AreaLight.h"
#include "Emissive.h"
#include "Sphere.h"
#include "Plane.h"
#include "MyRectangle.h"
#include "AreaLighting.h"
#include "Matte.h"
#include "AmbientOccluder.h"
#include "EnvironmentLight.h"
#include "PointLight.h"
#include "Triangle.h"
#include "Instance.h"
#include "Grid.h"
#include "Mesh.h"
#include "Reflective.h"
#include "Whitted.h"
#include "PureRandom.h"
#include "OpenCylinder.h"


void
World::build(void) {

	int num_samples = 16;
	
	vp.set_hres(600);      
	vp.set_vres(600);    
	vp.set_samples(num_samples);
	vp.set_max_depth(2);	
	
	tracer_ptr = new Whitted(this);
	background_color = black;
	
	MultiJittered* sampler_ptr = new MultiJittered(num_samples);
		
	AmbientOccluder* occluder_ptr = new AmbientOccluder;
	occluder_ptr->set_min_amount(0.25);		
	occluder_ptr->set_sampler(sampler_ptr);
	set_ambient_light(occluder_ptr);
	
	Pinhole* pinhole_ptr = new Pinhole;
	pinhole_ptr->set_eye(-6, 5, 11);    	
	pinhole_ptr->set_lookat(0 , 0, 0);
	pinhole_ptr->set_view_distance(5200);  
	pinhole_ptr->compute_uvw();     
	set_camera(pinhole_ptr); 

	PointLight* light_ptr = new PointLight;
	light_ptr->set_location(10, 5, 20);		
	light_ptr->scale_radiance(2.0);
	light_ptr->set_shadows(true);
	add_light(light_ptr);
	
	
	Phong* phong_ptr = new Phong;			
	phong_ptr->set_ka(0.2); 
	phong_ptr->set_kd(0.95); 
	phong_ptr->set_cd(1, 0.6, 0);   // orange
	phong_ptr->set_ks(0.5);  
	phong_ptr->set_exp(20); 
	phong_ptr->set_cs(1, 0.6, 0);   // orange   
		
	const char* file_name = "plyFiles/Horse97K.ply";		
	Grid* horse_ptr = new Grid(new Mesh);
	horse_ptr->read_smooth_triangles(file_name);
	horse_ptr->set_material(phong_ptr); 
	horse_ptr->setup_cells();
	add_object(horse_ptr);

	
	Reflective*	reflective_ptr = new Reflective;			
	reflective_ptr->set_ka(0.2); 
	reflective_ptr->set_kd(0.75);
	reflective_ptr->set_cd(0.5);
	reflective_ptr->set_ks(0.0);
	reflective_ptr->set_exp(20);
	reflective_ptr->set_kr(0.5);  
	reflective_ptr->set_cr(0.8, 1.0, 0.8);    
	
	Plane* plane_ptr = new Plane(Point3D(0, -.3, 0), Normal(0, 1, 0)); 	
	plane_ptr->set_material(reflective_ptr);
	add_object(plane_ptr);	
}


















