// This file contains the definition of the ThinLens class

#include "Constants.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "StereoCamera.h"

// ----------------------------------------------------------------------------- default constructor

StereoCamera::StereoCamera(void)
	:	Camera(),
		viewing_type(parallel),
		pixel_gap(5),
		beta(1.0), // ? right?
		left_camera_ptr(NULL),
		right_camera_ptr(NULL)
{}


// ----------------------------------------------------------------------------- copy constructor

StereoCamera::StereoCamera(const StereoCamera& c)
	:	Camera(c),
		viewing_type(c.viewing_type),
		pixel_gap(c.pixel_gap),
		beta(c.beta)
{
	// need to do a deep copy of the left and right cameras
	if(c.left_camera_ptr != NULL) {
		left_camera_ptr = c.left_camera_ptr->clone();
	}

	if(c.right_camera_ptr != NULL) {
		right_camera_ptr = c.right_camera_ptr->clone();
	}
}


// ----------------------------------------------------------------------------- clone

Camera*
StereoCamera::clone(void) const {
	return (new StereoCamera(*this));
}


// ----------------------------------------------------------------------------- assignment operator

StereoCamera&
StereoCamera::operator=(const StereoCamera& rhs) {

	if (this == &rhs)
		return (*this);

	Camera::operator=(rhs);

	viewing_type		= rhs.viewing_type;
	pixel_gap			= rhs.pixel_gap;
	beta				= rhs.beta;
	left_camera_ptr		= rhs.left_camera_ptr;
	right_camera_ptr	= rhs.right_camera_ptr;

	// need to do a deep copy of the left and right cameras
	if(rhs.left_camera_ptr != NULL) {
		left_camera_ptr = rhs.left_camera_ptr->clone();
	}

	if(rhs.right_camera_ptr != NULL) {
		right_camera_ptr = rhs.right_camera_ptr->clone();
	}

	return (*this);
}


// ----------------------------------------------------------------------------- destructor

StereoCamera::~StereoCamera(void) {

	delete left_camera_ptr;
	delete right_camera_ptr;
}


// ----------------------------------------------------------------------------- set_up_cameras

void
StereoCamera::setup_cameras(void) {

	double r = eye.distance(lookat);
	double x = r * tan(0.5 * beta * PI_ON_180);  //  half the camera separation distance

	left_camera_ptr->set_eye(eye - x * u);
	left_camera_ptr->set_lookat(lookat - x * u);
	left_camera_ptr->compute_uvw();

	right_camera_ptr->set_eye(eye + x * u);
	right_camera_ptr->set_lookat(lookat + x * u);
	right_camera_ptr->compute_uvw();
}


// ----------------------------------------------------------------------------- render_stereo

void
StereoCamera::render_stereo(const World& w, float x, int pixel_offset) {}	// this will never actually be implemented
																			// (cannot have a stereo camera within a another stereo camera)


// ----------------------------------------------------------------------------- render scene

void
StereoCamera::render_scene(const World& w) {

	ViewPlane	vp 		= w.vp;
	int 		hres	= vp.hres;
	int 		vres 	= vp.vres;

	// w.open_window(2 * hres + pixel_gap, vres); // ?

	double r = eye.distance(lookat);
	double x = r * tan(0.5 * beta * PI_ON_180);

	if (viewing_type == parallel) {
		left_camera_ptr->render_stereo(w, x, 0);						// left view on left
		right_camera_ptr->render_stereo(w, -x, hres + pixel_gap);		// right view on right
	}

	if (viewing_type == transverse) {
		right_camera_ptr->render_stereo(w, -x, 0);					// right view on left
		left_camera_ptr->render_stereo(w, x, hres + pixel_gap);		// left view on right
	}
}
