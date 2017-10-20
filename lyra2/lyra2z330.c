/*-
 * Copyright 2009 Colin Percival, 2011 ArtForz, 2013 Neisklar, 2017 Zcoin Developers
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file was originally written by Colin Percival as part of the Tarsnap
 * online backup system.
 */

 #include "Lyra2z.h"
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>
 #include <stdio.h>
 #include "../sha3/sph_blake.h"
 #include "Lyra2.h"
 
 void lyra2z330_hash(const char* input, char* output, uint32_t height)
 {
	 uint32_t _ALIGN(256) hash[16];
	 
	 uint64_t* lyra2z330_wholeMatrix;

		 LYRA2Z( lyra2z330_wholeMatrix, hash, 32, input, 80, input, 80,
				  2, 330, 256 );
 
	 memcpy(output, hash, 32);
 }
 

//  void lyra2z330_hash(const char* input, char* output, uint32_t len)
//  {
//      sph_blake256_context     ctx_blake;
 
//      uint32_t hashA[8], hashB[8];
 
//      sph_blake256_init(&ctx_blake);
//      sph_blake256 (&ctx_blake, input, 80);
//      sph_blake256_close (&ctx_blake, hashA);	
     
//      LYRA2(hashB, 32, hashA, 32, hashA, 32, 2, 330, 256);
     
//      memcpy(output, hashB, 32);
//  }
 

// #include <memory.h>
// #include <stdlib.h>
// #include <stdint.h>
// #include <string.h>
// #include <stdio.h>
// #include "lyra2z330.h"
// #include "Lyra2.h"


// void lyra2z330_hash(const char* input, char* output, uint32_t len)
// {
// 	        uint32_t hashY[8];

//             LYRA2(hashY, 32, input, 80, input, 80, 2, 330, 256);

// 	        memcpy(output, hashY, 32);
// }









