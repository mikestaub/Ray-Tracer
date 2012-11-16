#ifndef __SPHERICAL__
#define __SPHERICAL__

#include "Point2D.h"
#include "World.h"

class Spherical: public Camera {

	public:

		Spherical();

		Spherical(const Spherical& ph);

		virtual Camera*
		clone(void) const;

		Spherical&
		operator= (const Spherical& rhs);

		virtual
		~Spherical();

		void
		set_psi_max(const float max);

		void
		set_lambda_max(const float max);

		void
		set_horizontal_fov(const float fov);

		void
		set_vertical_fov(const float fov);

		Vector3D
		ray_direction(const Point2D& pixel_point, const int hres,
						const int vres, const float s) const;

		void
		render_stereo(const World& w, float x, int pixel_offset);

		virtual void
		render_scene(const World& w);

	private:

		float	psi_max;		// in degrees
		float	lambda_max;		// in degrees
};


//-------------------------------------------------------------------------- set_psi_max

inline void
Spherical::set_psi_max(float _m) {
	psi_max = _m;
}


//-------------------------------------------------------------------------- set_lambda_max

inline void
Spherical::set_lambda_max(float _l) {
	lambda_max = _l;
}


//-------------------------------------------------------------------------- set_horizontal_fov

inline void
Spherical::set_horizontal_fov(float _v) {
	psi_max = 2 * _v; // this right? check page 191 later
}


//-------------------------------------------------------------------------- set_vertical_fov

inline void
Spherical::set_vertical_fov(float _v) {
	lambda_max = 2 * _v;  // this right? check page 191 later
}

#endif
