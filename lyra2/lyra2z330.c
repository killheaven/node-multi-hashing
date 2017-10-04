#include <memory.h>
#include "lyra2.h"

void lyra2z330_hash(char* output, const char* input)
{
	uint64_t* lyra2z330_wholeMatrix;
	uint32_t _ALIGN(256) hash[16];

        LYRA2Z( lyra2z330_wholeMatrix, hash, 32, input, 80, input, 80,
                 2, 330, 256 );

	memcpy(output, hash, 32);
}