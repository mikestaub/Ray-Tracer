#include "MultiJittered.h"

// ---------------------------------------------------------------- default constructor

MultiJittered::MultiJittered(void)
	: Sampler()
{}


// ---------------------------------------------------------------- constructor

MultiJittered::MultiJittered(const int num_samples)
	: 	Sampler(num_samples) {

	generate_samples();
}


// ---------------------------------------------------------------- constructor

MultiJittered::MultiJittered(const int num_samples, const int m)
	: 	Sampler(num_samples, m) {
	generate_samples();
}


// ---------------------------------------------------------------- copy constructor

MultiJittered::MultiJittered(const MultiJittered& mjs)
	: Sampler(mjs)
{
	generate_samples();
}

// ---------------------------------------------------------------- assignment operator

MultiJittered&
MultiJittered::operator= (const MultiJittered& rhs) {
	if (this == &rhs)
		return (*this);

	Sampler::operator=(rhs);

	return (*this);
}

// ---------------------------------------------------------------- clone

MultiJittered*
MultiJittered::clone(void) const {
	return (new MultiJittered(*this));
}

// ---------------------------------------------------------------- destructor

MultiJittered::~MultiJittered(void) {}


// ---------------------------------------------------------------- generate_samples

// This is based on code in Chui et al. (1994), cited in the references
// The overloaded functions rand_int and rand_float (called from rand_int),
// which take arguments, are defined here
// explained on page 107
int
rand_int(int min, int max) {

	if(min == max)
		return max;
	else
		return (rand() % (max - min)) + min;
}

float
rand_float(float min, float max) {

	float r = float(rand()) / (float(RAND_MAX) + 1.0);	// random double in range 0.0 to 1.0 (non inclusive)
	float X = min + r * (max - min);					// transform to wanted range
	return X;
}

void
MultiJittered::generate_samples(void) {
	// num_samples needs to be a perfect square

	int n = (int)sqrt((float)num_samples);
	float subcell_width = 1.0 / ((float) num_samples);

	// fill the samples array with dummy points to allow us to use the [ ] notation when we set the
	// initial patterns

	Point2D fill_point;
	for (int j = 0; j < num_samples * num_sets; j++)
		samples.push_back(fill_point);

	// distribute points in the initial patterns

	for (int p = 0; p < num_sets; p++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				samples[i * n + j + p * num_samples].x = (i * n + j) * subcell_width + rand_float(0, subcell_width);
				samples[i * n + j + p * num_samples].y = (j * n + i) * subcell_width + rand_float(0, subcell_width);
			}

	// shuffle x coordinates

	for (int p = 0; p < num_sets; p++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				int k = rand_int(j, n - 1);
				float t = samples[i * n + j + p * num_samples].x;
				samples[i * n + j + p * num_samples].x = samples[i * n + k + p * num_samples].x;
				samples[i * n + k + p * num_samples].x = t;
			}

	// shuffle y coordinates

	for (int p = 0; p < num_sets; p++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				int k = rand_int(j, n - 1);
				float t = samples[j * n + i + p * num_samples].y;
				samples[j * n + i + p * num_samples].y = samples[k * n + i + p * num_samples].y;
				samples[k * n + i + p * num_samples].y = t;
		}
}
