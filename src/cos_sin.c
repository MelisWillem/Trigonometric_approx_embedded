/*
 * This lib calculates the sine and cosine trough chebychev polynomials
 * 
 * Most of the work is based on the article: http://www.ganssle.com/approx.htm
 * with source code: http://www.ganssle.com/approx/sincos.cpp
 * 
 */

#include "cos_sin.h"
#include "globals.h"
#include <math.h>

/*
 * 4 internal routines that calculate the cosine between  [0, pi/2]
 * The 2 macro's MACRO_COS(name) and MACRO_SIN(name) map a proper 
 * function name on it. As in cos32 and sin32 for 3.2 digits accuracy.
 */
static real_t cos_32s(real_t x);
static real_t cos_52s(real_t x);
static real_t cos_73s(real_t x);
static real_t cos_121s(real_t x);

#define MACRO_COS(name) real_t cos_##name(real_t x){ \
	x=MOD(x, TWOPI);/* Get rid of values > 2* pi */ \
	if(x<0)x=-x;/* cos(-x) = cos(x) */ \
	int quadrant=(int) (x * TWO_OVER_PI); /* Get quadrant # (0 to 3) we're in */ \
	switch (quadrant){\
	    case 0: return  cos_##name##s(x);\
	    case 1: return -cos_##name##s(PI-x);\
	    case 2: return -cos_##name##s(x-PI);\
	    case 3: return  cos_##name##s(TWOPI-x);\
	}\
    return FAILURE;\
}

#define MACRO_SIN(name) real_t sin_##name(real_t x){\
    return cos_##name(HALFPI-x);\
}

/*
 * calculate the cosine for any x [-inf,+inf]
 *  accuracy = 3.2 digits
 */
MACRO_COS(32)
/* 
 * The sine is just the shifted cosine 
 *  accuracy = 3.2 digits
 */
MACRO_SIN(32)
/*
 * calculate the cosine for any x [-inf,+inf]
 *  accuracy = 5.2 digits
 */
MACRO_COS(52)
/* 
 * The sine is just the shifted cosine 
 *  accuracy = 5.2 digits
 */
MACRO_SIN(52)
/*
 * calculate the cosine for any x [-inf,+inf]
 *  accuracy = 7.3 digits
 */
MACRO_COS(73)
/* 
 * The sine is just the shifted cosine 
 *  accuracy = 7.3 digits
 */
MACRO_SIN(73)
/*
 * calculate the cosine for any x [-inf,+inf]
 *  accuracy = 12.1 digits
 */
MACRO_COS(121)
/* 
 * The sine is just the shifted cosine 
 *  accuracy = 12.1 digits
 */
MACRO_SIN(121)


/*
 * 	cos_32s computes cosine (x)
 *
 * Accurate to about 3.2 decimal digits over the range [0, pi/2].
 * The input argument is in radians.
 *
 * Algorithm:
 *      cos(x)= c1 + c2*x**2 + c3*x**4
 * which is the same as:
 *		cos(x)= c1 + x**2(c2 + c3*x**2)
 */
static real_t cos_32s(real_t x)
{
    const real_t c1= 0.99940307;
    const real_t c2=-0.49558072;
    const real_t c3= 0.03679168;

    real_t x_squared=x * x;
    return (c1 + x_squared*(c2 + c3 * x_squared));
}
/* 
 *  cos_52s computes cosine (x)
 *
 * Accurate to about 5.2 decimal digits over the range [0, pi/2].
 * The input argument is in radians.
 * 
 * Algorithm:
 *      cos(x)= c1 + c2*x**2 + c3*x**4 + c4*x**6
 * which is the same as:
 *		cos(x)= c1 + x**2(c2 + c3*x**2 + c4*x**4)
 *		cos(x)= c1 + x**2(c2 + x**2(c3 + c4*x**2))
 */

static real_t cos_52s(real_t x)
{
    const real_t c1= 0.9999932946;
    const real_t c2=-0.4999124376;
    const real_t c3= 0.0414877472;
    const real_t c4=-0.0012712095;

    real_t x_squared=x * x;
    return (c1 + x_squared*(c2 + x_squared*(c3 + c4*x_squared)));
}

/*
 *		cos_73s computes cosine (x)
 *
 * Accurate to about 7.3 decimal digits over the range [0, pi/2].
 * The input argument is in radians. 
 *
 * Algorithm:
 *		cos(x)= c1 + c2*x**2 + c3*x**4 + c4*x**6 + c5*x**8
 *  which is the same as:
 *		cos(x)= c1 + x**2(c2 + c3*x**2 + c4*x**4 + c5*x**6)
 *		cos(x)= c1 + x**2(c2 + x**2(c3 + c4*x**2 + c5*x**4))
 *		cos(x)= c1 + x**2(c2 + x**2(c3 + x**2(c4 + c5*x**2)))
 */
real_t cos_73s(real_t x)
{
    const real_t c1= 0.999999953464;
    const real_t c2=-0.499999053455;
    const real_t c3= 0.0416635846769;
    const real_t c4=-0.0013853704264;
    const real_t c5= 0.00002315393167;  	

    real_t x_squared=x * x;
    return (c1 + x_squared*(c2 + x_squared*(c3 + x_squared*(c4 + c5*x_squared))));
}
/*
 *		cos_121s computes cosine (x)
 *
 * Accurate to about 12.1 decimal digits over the range [0, pi/2].
 * The input argument is in radians.
 *
 * Algorithm:
 *      cos(x)= c1 + c2*x**2 + c3*x**4 + c4*x**6 + c5*x**8 + c6*x**10 + c7*x**12
 * which is the same as:
 *      cos(x)= c1 + x**2(c2 + c3*x**2 + c4*x**4 + c5*x**6 + c6*x**8 + c7*x**10)
 *		cos(x)= c1 + x**2(c2 + x**2(c3 + c4*x**2 + c5*x**4 + c6*x**6 + c7*x**8 ))
 *		cos(x)= c1 + x**2(c2 + x**2(c3 + x**2(c4 + c5*x**2 + c6*x**4 + c7*x**6 )))
 *		cos(x)= c1 + x**2(c2 + x**2(c3 + x**2(c4 + x**2(c5 + c6*x**2 + c7*x**4 ))))
 *		cos(x)= c1 + x**2(c2 + x**2(c3 + x**2(c4 + x**2(c5 + x**2(c6 + c7*x**2 )))))
 */
real_t cos_121s(real_t x)
{
    const real_t c1= 0.99999999999925182;
    const real_t c2=-0.49999999997024012;
    const real_t c3= 0.041666666473384543;
    const real_t c4=-0.001388888418000423;
    const real_t c5= 0.0000248010406484558;
    const real_t c6=-0.0000002752469638432;
    const real_t c7= 0.0000000019907856854;

    real_t x_squared=x * x;
    return (c1 + x_squared*(c2 + x_squared*(c3 + x_squared*(c4 + x_squared*(c5 + x_squared*(c6 + c7*x_squared))))));
}