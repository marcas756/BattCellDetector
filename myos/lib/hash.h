// http://www.cse.yorku.ca/~oz/hash.html

/*!
    \file       hash_sdbm.h

    \brief      

    \details    
*/


#ifndef HASH_SDBM_H_
#define HASH_SDBM_H_

#include <stdint.h>
#include <stddef.h>

#define hash_sdbm_acc(hash,byte) \
	(byte + (hash << 6) + (hash << 16) - hash)

uint32_t hash_sdbm(uint32_t seed, void *data, size_t size);




#endif /* HASH_H_ */
