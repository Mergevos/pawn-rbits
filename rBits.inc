/*
	* Library: Pawn rBits (rBits.inc)
	* Author: RyDeR
	* Date: 14. Novembre 2020.
	* Copyright: (C) 2020
	* Credits: 
        Alex Cole - Y_Less - YSI Testing library
		Me - pushing this to a github repo.  
*/

// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_rBits
	#undef _inc_rBits
#endif
// custom include-guard to ensure we don't duplicate

#if defined _Included_rBits
	#endinput
#else
	#define _Included_rBits
#endif

#define BIT_TAGS \
	{ Bit1, Bit2, Bit4, Bit8, Bit16 }
		
enum e_Bits {
	Bit1,
	Bit2,
	Bit4,
	Bit8,
	Bit16,
	Bit32
};

/*
 * Macros
 */

#define Bit1:%0<%1> \
	Bit1: %0[((%1) + 31) >>> _: Bit32]	

#define	Bit1_Set(%0,%1,%2) \
    Bit_Set(%0, (%1), (%2), Bit1)
    
#define Bit1_Get(%0,%1) \
	Bit_Get(%0, (%1), Bit1)

#define Bit2:%0<%1> \
	Bit2: %0[((%1) + 15) >>> _: (Bit32 - Bit2)]
	
#define	Bit2_Set(%0,%1,%2) \
	Bit_Set(%0, (%1), (%2), Bit2)
	
#define Bit2_Get(%0,%1) \
	Bit_Get(%0, (%1), Bit2)

#define Bit4:%0<%1> \
	Bit4: %0[((%1) + 7) >>> _: (Bit32 - Bit4)]
	
#define	Bit4_Set(%0,%1,%2) \
	Bit_Set(%0, (%1), (%2), Bit4)
	
#define Bit4_Get(%0,%1) \
	Bit_Get(%0, (%1), Bit4)

#define Bit8:%0<%1> \
	Bit8: %0[(%1) char]
	
#define Bit8_Set(%0,%1,%2) \
	(_: %0{(%1)} = (%2))
	
#define Bit8_Get(%0,%1) \
	(_: %0{(%1)})
	

#define Bit16:%0<%1> \
	Bit16: %0[((%1) + 1) >>> _: (Bit32 - Bit16)]
	
#define	Bit16_Set(%0,%1,%2) \
	Bit_Set(%0, (%1), (%2), Bit16)
	
#define Bit16_Get(%0,%1) \
	Bit_Get(%0, (%1), Bit16)

/* 
 * Bit limits
 * Bit1: 1 ─ 0x1
 * Bit2: 3 ─ 0x3
 * Bit4: 15 ─ 0xF
 * Bit8: 255 ─ 0xFF	
 * Bit16: 65535 ─ 0xFFFF
 */

/*
 * Functions
 */

/*
 * <summary> Sets a value to a Bit array.</summary>
 * <param name="abArray"> Bit Array.</param>
 * <param name="iIdx"> Index of the array.</param>
 * <param name="iValue"> Value to set.</param>
 * <param name="iShift"> Bit shift.</param>
 * <param name="iSize"> Size of the array.</param>
 */

stock Bit_Set(BIT_TAGS: abArray[], iIdx, const iValue, const e_Bits: iShift, const iSize = sizeof(abArray)) {
	new
		bVar = ((iIdx & ((1 << _: (Bit32 - iShift)) - 1)) << _: iShift),
		bLim = ((1 << (1 << _: iShift)) - 1)
	;
	iIdx = (iIdx >>> _: (Bit32 - iShift));
	
	if(!(-1 < iIdx < iSize)) {
		return 0;
	}
	(_: abArray[iIdx] &= ~(bLim << bVar));
	(_: abArray[iIdx] |= ((bLim & iValue) << bVar));
	
	return 1;
}

/*
 * <summary> Gets a value from a Bit array.</summary>
 * <param name="abArray"> Bit Array.</param>
 * <param name="iIdx"> Index of the array.</param>
 * <param name="iShift"> Bit shift.</param>
 * <param name="iSize"> Size of the array.</param>
 */

stock Bit_Get(const BIT_TAGS: abArray[], iIdx, const e_Bits: iShift, const iSize = sizeof(abArray)) {
	new
		bVar = ((iIdx & ((1 << _: (Bit32 - iShift)) - 1)) << _: iShift),
		bLim = ((1 << (1 << _: iShift)) - 1)
	;
	iIdx = (iIdx >>> _: (Bit32 - iShift));
	
	if(!(-1 < iIdx < iSize)) {
		return 0;
	}
	return ((_: abArray[iIdx] >>> bVar) & bLim);
}
