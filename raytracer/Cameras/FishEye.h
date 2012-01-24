#ifndef __FISHEYE__
#define __FISHEYE__

#include "Point2D.h"
#include "World.h"

class FishEye: public Camera {
	public:

		FishEye();

		FishEye(const FishEye& ph);

		virtual Camera*
		clone(void) const;

		FishEye&
		operator= (const FishEye& rhs);

		virtual
		~FishEye();

		void
		set_psi_max(const float max);

		void
		set_fov(const float fov);

		Vector3D
		ray_direction(const Point2D& pixel_point, const int hres,
						const int vres, const float s, float& r_squared) const;

		void
		render_stereo(const World& w, float x, int pixel_offset);

		virtual void
		render_scene(const World& w);

	private:

		float	psi_max;	// in degrees
};


//-------------------------------------------------------------------------- set_psi_max

inline void
FishEye::set_psi_max(float _m) {
	psi_max = _m;
}


//-------------------------------------------------------------------------- set_fov

inline void
FishEye::set_fov(float _f) {
	psi_max = 2 * _f; // this right? check page 187 later
}

#endif
