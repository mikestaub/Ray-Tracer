// This file contains the definition of the FishEye class

#include "Constants.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "FishEye.h"

// ----------------------------------------------------------------------------- default constructor

FishEye::FishEye(void)
	:	Camera(),
		psi_max(180.0) // is this a good default value?
{}


// ----------------------------------------------------------------------------- copy constructor

FishEye::FishEye(const FishEye& c)
	:	Camera(c),
		psi_max(c.psi_max)
{}


// ----------------------------------------------------------------------------- clone

Camera*
FishEye::clone(void) const {
	return (new FishEye(*this));
}


// ----------------------------------------------------------------------------- assignment operator

FishEye&
FishEye::operator=(const FishEye& rhs) {

	if (this == &rhs)
		return (*this);

	Camera::operator=(rhs);

	psi_max = rhs.psi_max;

	return (*this);
}


// ----------------------------------------------------------------------------- destructor

FishEye::~FishEye(void) {}


// ----------------------------------------------------------------------------- ray direction
// explained on page 188
Vector3D
FishEye::ray_direction( const Point2D&	pp,
						const int		hres,
						const int		vres,
						const float 	s,
						float&			r_squared) const {

	// compute the normalized device coordinates
	Point2D pn(2.0 / (s * hres) * pp.x, 2.0 / (s * vres) * pp.y);
	r_squared = pn.x * pn.x + pn.y * pn.y;

	if (r_squared <= 1.0) {
		float r 		= sqrt(r_squared);
		float psi 		= r * psi_max * PI_ON_180;
		float sin_psi 	= sin(psi);
		float cos_psi 	= cos(psi);
		float sin_alpha = pn.y / r;
		float cos_alpha = pn.x / r;
		Vector3D dir 	= sin_psi * cos_alpha * u +  sin_psi * sin_alpha * v - cos_psi * w;

		return (dir);
	}
	else
		return (Vector3D(0.0));
}


// ----------------------------------------------------------------------------- render_stereo

void
FishEye::render_stereo(const World& w, float x, int pixel_offset) {

		// not implemented yet
}


// ----------------------------------------------------------------------------- render scene
// explained on page 187
void
FishEye::render_scene(const World& wr) {

	RGBColor	L;
	ViewPlane	vp(wr.vp);
	int 		hres		= vp.hres;
	int 		vres 		= vp.vres;
	float		s 			= vp.s;
	Ray			ray;
	int 		depth 		= 0;
	Point2D 	sp; 					// sample point in [0, 1] X [0, 1]
	Point2D 	pp;						// sample point on the pixel
	float		r_squared;				// sum of squares of normalised device coordinates

	ray.o = eye;

	for (int r = 0; r < vres; r++)		// up
		for (int c = 0; c < hres; c++) {	// across

			L = black;
			for (int j = 0; j < vp.num_samples; j++) {
				sp = vp.sampler_ptr->sample_unit_square();
				pp.x = s * (c - 0.5 * hres + sp.x);
				pp.y = s * (r - 0.5 * vres + sp.y);
				ray.d = ray_direction(pp, hres, vres, s, r_squared);

				if (r_squared <= 1.0)
					L += wr.tracer_ptr->trace_ray(ray, depth);
			}

			L /= vp.num_samples;
			L *= exposure_time;
			wr.display_pixel(r, c, L);
		}
}
