#ifndef __HAMMERSLEY__
#define __HAMMERSLEY__

#include "Sampler.h"

class Hammersley: public Sampler {

	public:

		Hammersley(void);

		Hammersley(const int num);

		Hammersley(const Hammersley& r);

		Hammersley& 
		operator= (const Hammersley& rhs);

		virtual Hammersley*
		clone(void) const;

		virtual
		~Hammersley(void);

		double 
		phi(int j);

	private:

		virtual void
		generate_samples(void);
};

#endif
