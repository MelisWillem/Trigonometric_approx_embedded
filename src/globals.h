#include "math.h" 

#ifndef real_t
    #define real_t double
#endif
/*
 * If successful, returns the floating-point 
 *      remainder of the division x/y
 */
#ifndef MOD
    #define MOD(x,y) fmod(x,y)
#endif
/*
 * absolute value of a function
 */
#ifndef ABS
    #define ABS(x) fabs(x)
#endif

#ifndef SUCCESS
    #define SUCCESS 0
#endif
#ifndef FAILURE
    #define FAILURE 1
#endif

#define PI 3.1415926535897932384626433
#define TWOPI 2.0*PI
#define TWO_OVER_PI 2.0/PI
#define HALFPI PI/2.0

// /* pi times 3/2, used in tan routines */
// #define threehalfpi=3.0*pi/2.0;  		
// #define four_over_pi=4.0/pi;		/* 4/pi, used in tan routines */
// #define qtrpi=pi/4.0;			/* pi/4.0, used in tan routines */
// #define sixthpi=pi/6.0;			/* pi/6.0, used in atan routines */
// #define tansixthpi=tan(sixthpi);		/* tan(pi/6), used in atan routines */
// #define twelfthpi=pi/12.0;			/* pi/12.0, used in atan routines */
// #define tantwelfthpi=tan(twelfthpi);	/* tan(pi/12), used in atan routines */