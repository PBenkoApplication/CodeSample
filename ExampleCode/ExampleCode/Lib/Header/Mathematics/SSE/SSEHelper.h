#ifndef SSEHELPER_H
#define SSEHELPER_H

namespace BAME
{
	class SSEHelper
	{
	public:
		static bool checkSSE3Support();

	private:
		static void checkSupport();

		static bool alreadyChecked;
		//  Misc.
		static bool HW_MMX;
		static bool HW_x64;
		static bool HW_ABM; // Advanced Bit Manipulation
		static bool HW_RDRAND;
		static bool HW_BMI1;
		static bool HW_BMI2;
		static bool HW_ADX;
		static bool HW_PREFETCHWT1;

		//  SIMD: 128-bit
		static bool HW_SSE;
		static bool HW_SSE2;
		static bool HW_SSE3;
		static bool HW_SSSE3;
		static bool HW_SSE41;
		static bool HW_SSE42;
		static bool HW_SSE4a;
		static bool HW_AES;
		static bool HW_SHA;

		//  SIMD: 256-bit
		static bool HW_AVX;
		static bool HW_XOP;
		static bool HW_FMA3;
		static bool HW_FMA4;
		static bool HW_AVX2;

		//  SIMD: 512-bit
		static bool HW_AVX512F; //  AVX512 Foundation
		static bool HW_AVX512CD; //  AVX512 Conflict Detection
		static bool HW_AVX512PF; //  AVX512 Prefetch
		static bool HW_AVX512ER; //  AVX512 Exponential + Reciprocal
		static bool HW_AVX512VL; //  AVX512 Vector Length Extensions
		static bool HW_AVX512BW; //  AVX512 Byte + Word
		static bool HW_AVX512DQ; //  AVX512 Doubleword + Quadword
		static bool HW_AVX512IFMA; //  AVX512 Integer 52-bit Fused Multiply-Add
		static bool HW_AVX512VBMI; //  AVX512 Vector Byte Manipulation Instructions		
	};
};

#endif
