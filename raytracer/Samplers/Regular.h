#ifndef __REGULAR__
#define __REGULAR__

#include "Sampler.h"

class Regular: public Sampler {

	public:

		Regular(void);

		Regular(const int num);

		Regular(const Regular& u);

		Regular&
		operator= (const Regular& rhs);

		virtual Regular*
		clone(void) const;

		virtual
		~Regular(void);

		virtual void
		generate_samples(void);
};

#endif
