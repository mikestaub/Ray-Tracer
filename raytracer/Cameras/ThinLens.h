#ifndef __THINLENS__
#define __THINLENS__

#include "Point2D.h"
#include "World.h"

class ThinLens: public Camera {
	public:

		ThinLens();

		ThinLens(const ThinLens& ph);

		virtual Camera*
		clone(void) const;

		ThinLens&
		operator= (const ThinLens& rhs);

		virtual
		~ThinLens();

		void
		set_lens_radius(const float radius);

		void
		set_view_distance(const float vpd);

		void
		set_focal_distance(const float f);

		void
		set_zoom(const float zoom_factor);

		void
		set_sampler(Sampler* sp);

		Vector3D
		ray_direction(const Point2D& pixel_point, const Point2D& lens_point) const;

		void
		render_stereo(const World& w, float x, int pixel_offset);

		virtual void
		render_scene(const World& w);

	private:

		float		lens_radius;	// lens radius
		float		d;				// view plane distance
		float		f;				// focal distance
		float		zoom;			// zoom factor
		Sampler*	sampler_ptr;	// sampler object
};


//-------------------------------------------------------------------------- set_lens_radius

inline void
ThinLens::set_lens_radius(float _r) {
	lens_radius = _r;
}


//-------------------------------------------------------------------------- set_view_distance

inline void
ThinLens::set_view_distance(float _d) {
	d = _d;
}


//-------------------------------------------------------------------------- set_focal_distance

inline void
ThinLens::set_focal_distance(float _f) {
	f = _f;
}


//-------------------------------------------------------------------------- set_zoom

inline void
ThinLens::set_zoom(float zoom_factor) {
	zoom = zoom_factor;
}

#endif
