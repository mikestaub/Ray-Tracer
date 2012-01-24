#ifndef __JITTERED__
#define __JITTERED__

#include "Sampler.h"

class Jittered: public Sampler {
	public:

		Jittered(void);

		Jittered(const int num_samples);

		Jittered(const int num_samples, const int m);

		Jittered(const Jittered& u);

		Jittered& 
		operator= (const Jittered& rhs);

		virtual Jittered*
		clone(void) const;

		virtual
		~Jittered(void);

	private:

		virtual void
		generate_samples(void);
};

#endif
