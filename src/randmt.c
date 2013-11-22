#include <stdio.h>
#include <agtypes.h>
#include "randmt.h"
#include "math.h"

#define MATRIX_A (0x9908b0df)
const u32 UPPER_MASK = 0x80000000;
const u32 LOWER_MASK = 0x7fffffff;
const u32 INIT_SEED = 4357;
const u32 MUL_SEED = 69069;

const u32 TEMPERING_MASK_B = 0x9d2c5680;
const u32 TEMPERING_MASK_C = 0xefc60000;

const int randMTM2 = 120;

static s32 index;
static u32 seed;
static u32 mtr[randMTN];
static u32 mt[randMTN+1];

static u32 TEMPERING_SHIFT_U( u32 v ){ return v >> 11; }
static u32 TEMPERING_SHIFT_S( u32 v ){ return v << 7;  }
static u32 TEMPERING_SHIFT_T( u32 v ){ return v << 15; }
static u32 TEMPERING_SHIFT_L( u32 v ){ return v >> 18; }

static const u32 mag01[2] = { 0, MATRIX_A };

// =============================================
// randMT::generateMT
// 概要  : 乱数配列の生成 
// 引数  : none
// 戻り値: none
// =============================================
void generateMT( void ) {
// 	PRINTF("randMT::generateMT\n");

	int i;
	u32 u;

	for( i=0; i<randMTN-randMTM2; i++ ){
		u = (mt[i] & UPPER_MASK) | (mt[i+1] & LOWER_MASK);
		mt[i] = mt[i+randMTM2] ^ (u>>1) ^ mag01[u&1];
	}
	mt[randMTN] = mt[0];
	for( ; i<randMTN; i++ ){
		u = (mt[i] & UPPER_MASK) | (mt[i+1] & LOWER_MASK);
		mt[i] = mt[i+(randMTM2-randMTN)] ^ (u>>1) ^ mag01[u&1];
	}

	for( i=0; i<randMTN; i++ ){
		u = mt[i];
		u ^= TEMPERING_SHIFT_U(u);
		u ^= TEMPERING_SHIFT_S(u) & TEMPERING_MASK_B;
		u ^= TEMPERING_SHIFT_T(u) & TEMPERING_MASK_C;
		u ^= TEMPERING_SHIFT_L(u);
		mtr[i] = u;
	}
	index = 0;
}

// =============================================
// randMT::srandMT
// 概要  : 与えられたシードから乱数の初期値を決定する。
// 引数  : seed	与えるシード（なるべく大きな値がよい）
// 戻り値: none
// =============================================
void srandMT( unsigned int s ) {
	int i;

	seed = s;
	for( i=0; i<randMTN; i++ ){
		u32 v;
		s = MUL_SEED * s + 1;
		v = s & 0xffff0000;
		s = MUL_SEED * s + 1;
		mt[i] = v|((s & 0xffff0000)>>16);
	}
	generateMT();
}

// =============================================
// randMT::randMT
// 概要  : 乱数を求める
// 引数  : none
// 戻り値: unsigned int	求めた乱数 
// =============================================
unsigned int randMT( void ) {
	if( index >= randMTN ){
		generateMT();
	}
	return mtr[ index++ ]; 
}
