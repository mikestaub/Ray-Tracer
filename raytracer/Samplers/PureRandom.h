#ifndef __PURE_RANDOM__
#define __PURE_RANDOM__

#include "Sampler.h"

class PureRandom: public Sampler {
	public:

		PureRandom(void);

		PureRandom(const int num);

		PureRandom(const PureRandom& r);

		PureRandom&
		operator= (const PureRandom& rhs);

		virtual PureRandom*
		clone(void) const;

		virtual
		~PureRandom(void);

	private:

		virtual void
		generate_samples(void);
};

#endif
