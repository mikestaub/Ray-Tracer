#ifndef __N_ROOKS__
#define __N_ROOKS__

#include "Sampler.h"

class NRooks: public Sampler {

	public:

		NRooks(void);

		NRooks(const int num_samples);

		NRooks(const int num_samples, const int m);

		NRooks(const NRooks& nr);

		NRooks& 
		operator= (const NRooks& rhs);

		virtual NRooks*
		clone(void) const;

		virtual
		~NRooks(void);

	private:

		virtual void
		generate_samples(void);
};

#endif
