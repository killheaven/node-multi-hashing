
#include "tribus.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "sph_jh.h"
#include "sph_keccak.h"
#include "sph_echo.h"

void tribus_hash(const char* input, char* output)
{
 	sph_jh512_context ctx_jh;
 	sph_keccak512_context ctx_keccak;
 	sph_echo512_context ctx_echo;

	uint8_t hash[64]; 
 
 	sph_jh512_init(&ctx_jh);
 	sph_jh512(&ctx_jh, input, 80);
 	sph_jh512_close(&ctx_jh, (void*) hash);
 
 	sph_keccak512_init(&ctx_keccak);
 	sph_keccak512(&ctx_keccak, (const void*) hash, 64);
 	sph_keccak512_close(&ctx_keccak, (void*) hash);
 
 	sph_echo512_init(&ctx_echo);
 	sph_echo512(&ctx_echo, (const void*) hash, 64);
 	sph_echo512_close(&ctx_echo, (void*) hash);
 
 	memcpy(output, hash, 32);
}

// void tribus_hash(void *state, const void *input)
// {
//      unsigned char hash[128] __attribute__ ((aligned (32)));
//      tribus_ctx_holder ctx;
//      memcpy( &ctx, &tribus_ctx, sizeof(tribus_ctx) );

//      sph_jh512( &ctx.jh, input+64, 16 );
//      sph_jh512_close( &ctx.jh, (void*) hash );

//      sph_keccak512( &ctx.keccak, (const void*) hash, 64 );
//      sph_keccak512_close( &ctx.keccak, (void*) hash );

// #ifdef NO_AES_NI
//      sph_echo512( &ctx.echo, hash, 64 );
//      sph_echo512_close (&ctx.echo, hash );
// #else
//      update_final_echo( &ctx.echo, (BitSequence *) hash,
//                         (const BitSequence *) hash, 512 );
// #endif

//      memcpy(state, hash, 32);
// }