/*
 * a template class which implements a hashtable with 2d koord keys
 */

#ifndef koordhashtable_tpl_h
#define koordhashtable_tpl_h

#include "hashtable_tpl.h"
#include "../dataobj/koord.h"


/*
 * Define the key characteristics for hashing 2d koord types
 */
template<class key_t>
class koordhash_tpl 
{
public:
	typedef int diff_type;

    static uint32 hash(const key_t key)
    {
		return (uint32)key.y << 16 | key.x;
    }

	static key_t null()
    {
		return koord::invalid;
    }

	static void dump(const key_t key)
    {
		printf("%d, %d", key.x, key.y);
    }

	static diff_type comp(key_t key1, key_t key2)
    {
		diff_type d = key1.y - key2.y;
		if (!d)	d = key1.x - key2.x;
		return d;
    }
};


/*
 * Ready to use class for hashing 2d koord types. 
 */
template<class key_t, class value_t>
class koordhashtable_tpl : public hashtable_tpl<key_t, value_t, koordhash_tpl<key_t> >
{
};


#endif
