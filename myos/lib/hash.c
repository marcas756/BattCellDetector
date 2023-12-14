// http://www.cse.yorku.ca/~oz/hash.html



/*!
    \file   hash_sdbm.c

    \brief

    \details    This algorithm was created for sdbm (a public-domain reimplementation of ndbm) database library.
                It was found to do well in scrambling bits, causing better distribution of the keys and fewer splits.
                It also happens to be a good general hashing function with good distribution. the actual function is

                hash(i) = hash(i - 1) * 65599 + str[i];

                What is included below is the faster version used in gawk. [there is even a faster, duff-device version]
                The magic constant 65599 was picked out of thin air while experimenting with different constants,
                and turns out to be a prime. this is one of the algorithms used in berkeley db (see sleepycat) and elsewhere.

                http://www.cse.yorku.ca/~oz/hash.html
*/


/*!
    \file       hash_sdbm.c

    \brief      Brief description of the module

    \details    Detailed description of the module
*/


#include "hash.h"



uint32_t hash_sdbm(uint32_t seed, void *data, size_t size)
{
	int idx;

	for(idx = 0; idx < size; idx++)
	{
		seed = hash_sdbm_acc(seed,((uint8_t*)data)[idx]);		
	}

    	return seed;
}








