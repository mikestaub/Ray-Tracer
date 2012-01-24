#ifndef __STEREOCAMERA__
#define __STEREOCAMERA__

#include "Point2D.h"
#include "World.h"

typedef enum {
	parallel,
	transverse
} ViewingType;

class StereoCamera: public Camera {
	public:

		StereoCamera();

		StereoCamera(const StereoCamera& ph);

		virtual Camera*
		clone(void) const;

		StereoCamera&
		operator= (const StereoCamera& rhs);

		virtual
		~StereoCamera();

		void
		set_viewing_type(ViewingType enum_val);

		void
		set_left_camera(Camera* left_cam);

		void
		set_right_camera(Camera* right_cam);

		void
		set_pixel_gap(float gap);

		void
		set_beta(float beta);

		void
		setup_cameras(void);

		void
		render_stereo(const World& w, float x, int pixel_offset);

		virtual void
		render_scene(const World& w);

	private:

		ViewingType	viewing_type;		// parallel or transverse viewing
		int			pixel_gap;			// gap in pixels between the left and right images
		float		beta;				// stereo separation angle
		Camera*		left_camera_ptr;	// left eye camera
		Camera*		right_camera_ptr;	// right eye camera
};


//-------------------------------------------------------------------------- set_left_camera

inline void
StereoCamera::set_left_camera(Camera* _c) {
	left_camera_ptr = _c;
}


//-------------------------------------------------------------------------- set_right_camera
inline void
StereoCamera::set_right_camera(Camera* _c) {
	right_camera_ptr = _c;
}


//-------------------------------------------------------------------------- set_viewing_type

inline void
StereoCamera::set_viewing_type(ViewingType _v) {
	viewing_type = _v;
}


//-------------------------------------------------------------------------- set_pixel_gap

inline void
StereoCamera::set_pixel_gap(float _g) {
	pixel_gap = _g;
}


//-------------------------------------------------------------------------- set_beta

inline void
StereoCamera::set_beta(float _b) {
	beta = _b;
}

#endif
