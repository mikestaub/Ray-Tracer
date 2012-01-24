#include "Hammersley.h"
#include "Maths.h"

// ---------------------------------------------------------------- default constructor

Hammersley::Hammersley(void)
	: 	Sampler()
{}


// ---------------------------------------------------------------- constructor

Hammersley::Hammersley(const int num)
	: 	Sampler(num) {
	generate_samples();
}


// ---------------------------------------------------------------- copy constructor

Hammersley::Hammersley(const Hammersley& h)
	: 	Sampler(h) {
	generate_samples();
}

// ---------------------------------------------------------------- assignment operator

Hammersley&
Hammersley::operator= (const Hammersley& rhs) {
	if (this == &rhs)
		return (*this);

	Sampler::operator=(rhs);

	return (*this);
}


// ---------------------------------------------------------------- clone

Hammersley*
Hammersley::clone(void) const {
	return (new Hammersley(*this));
}


// ---------------------------------------------------------------- destructor

Hammersley::~Hammersley(void) {}


// ---------------------------------------------------------------- phi
// explained on page 109
double
Hammersley::phi(int j) {
	double x = 0.0;
	double f = 0.5;

	while (j) {
		x += f * (double) (j & 1);
		j /= 2;
		f *= 0.5; 
	}

	return (x);
}


// ---------------------------------------------------------------- generate_samples

void
Hammersley::generate_samples(void) {
	for (int p = 0; p < num_sets; p++)
		for (int j = 0; j < num_samples; j++) {
			Point2D pv((float) j / (float) num_samples, phi(j));
			samples.push_back(pv);
		}
}
