/***********************************************************************************************************************
 * Copyright Audioscenic 2023 - All rights reserved
 * 
 * @file    mufft_1d.c
 *
 * @brief   brief description
 * 
 * detailed description
 *  
 * @par
 * @author 	george_howell
 **********************************************************************************************************************/

/*------------------------------------------- INCLUDES ---------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "fft.h"
#include "fft_internal.h"

#include "main.h"

/*------------------------------------------- EXTERN VARIABLES -------------------------------------------------------*/
/*------------------------------------------- PRIVATE MACROS AND DEFINES ---------------------------------------------*/

#define MUFFT_N					(16U)				/** length of time domain data */
#define MUFFT_FFTN				(MUFFT_N/2U + 1U)	/** number of positive frequency values */

/*------------------------------------------- PRIVATE TYPEDEFS -------------------------------------------------------*/
/*------------------------------------------- STATIC VARIABLES -------------------------------------------------------*/
/*------------------------------------------- GLOBAL VARIABLES -------------------------------------------------------*/

static float din[MUFFT_N] =
{
	#include "din.dat"
};

/*------------------------------------------- STATIC FUNCTION PROTOTYPES ---------------------------------------------*/
/*------------------------------------------- STATIC FUNCTIONS -------------------------------------------------------*/
/*------------------------------------------- GLOBAL FUNCTIONS -------------------------------------------------------*/

/**
 * @brief 	1d real to complex fft and ifft
 * 
 * runs a 1d real to complex fft then ifft, flags used to specifiy various run options
 * 
 * @param   flags     varDescription1
 */
void mufft_1d_real(uint32_t flags)
{
	uint32_t i;
	float err = 0;

    float *dinTD;
    cfloat *doutFD;
    float *doutTD;

    // allocate memory for buffers
    dinTD = mufft_alloc(MUFFT_N * sizeof(float));
    doutFD = mufft_alloc(MUFFT_N * sizeof(float));
    doutTD = mufft_alloc(MUFFT_N * sizeof(cfloat)); // only allocate enough memory for positive freq's

    // load input data to buffer
    for (i = 0; i < MUFFT_N; i++)
    {
    	dinTD[i] = din[i];
    }

    // set up mufft plans
    mufft_plan_1d *muplan_r2c = mufft_create_plan_1d_r2c(MUFFT_N, flags);
    mufft_plan_1d *muplan_c2r = mufft_create_plan_1d_c2r(MUFFT_N, flags);

    // execute plans, perform fft then dft.
	mufft_execute_plan_1d(muplan_r2c, doutFD, dinTD);
	mufft_execute_plan_1d(muplan_c2r, doutTD, doutFD);

	// check output data is same as input
	for (i = 0; i < MUFFT_N; i++)
	{
		err += dinTD[i] - doutTD[i];
	}
	printf("err: %.4f\n", err);

	// free buffers and data
    mufft_free(dinTD);
    mufft_free(doutFD);
    mufft_free(doutTD);
    mufft_free_plan_1d(muplan_r2c);
    mufft_free_plan_1d(muplan_c2r);
}
