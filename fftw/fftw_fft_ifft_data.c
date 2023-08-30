/***********************************************************************************************************************
 * @file    fftw_fft_ifft_data.c
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
#include <math.h>
#include <complex.h>

#include "fftw3.h"

/*------------------------------------------- EXTERN VARIABLES -------------------------------------------------------*/
/*------------------------------------------- PRIVATE MACROS AND DEFINES ---------------------------------------------*/

#define FFT_IFFT_N					(16U)

/*------------------------------------------- PRIVATE TYPEDEFS -------------------------------------------------------*/
/*------------------------------------------- STATIC VARIABLES -------------------------------------------------------*/

static float din[FFT_IFFT_N] =
{
	#include "din.dat"
};

static float doutRef[2*FFT_IFFT_N] =
{
	#include "doutRef.dat"
};

/*------------------------------------------- GLOBAL VARIABLES -------------------------------------------------------*/
/*------------------------------------------- STATIC FUNCTION PROTOTYPES ---------------------------------------------*/
/*------------------------------------------- STATIC FUNCTIONS -------------------------------------------------------*/
/*------------------------------------------- GLOBAL FUNCTIONS -------------------------------------------------------*/

/**
 * @brief 	fftw 1d fft
 */
void fftw_fft_1d_array(void)
{
	int i;

	fftw_plan fftP = NULL;
	fftw_complex dinCpx[FFT_IFFT_N] = {0};
	fftw_complex doutCpx[FFT_IFFT_N] = {0};
	fftw_complex doutCpxRef[FFT_IFFT_N] = {0};
	fftw_complex err = 0;

	// convert din to complex array
	for (i = 0; i < FFT_IFFT_N; i++)
	{
		dinCpx[i] = din[i] + 0*I;
	}

	// create fft plan
	fftP = fftw_plan_dft_1d(FFT_IFFT_N, dinCpx, doutCpx, FFTW_FORWARD, FFTW_ESTIMATE);

	// run fft
	fftw_execute(fftP);

	// destroys the fft plan
	fftw_destroy_plan(fftP);

	// verify results
	for (i = 0; i < (2*FFT_IFFT_N); i += 2)
	{
		doutCpxRef[i>>1] = doutRef[i] + doutRef[i+1]*I;
	}
	for (i = 0; i < FFT_IFFT_N; i++)
	{
		err += doutCpxRef[i] - doutCpx[i];
	}
	printf("fftw_fft_1d_array\n");
	printf("err: %f\n", cabs(err));
}

/**
 * @brief 	fftw 1d ifft
 */
void fftw_ifft_1d_array(void)
{
	int i;

	fftw_plan ifftP = NULL;
	fftw_complex dinCpx[FFT_IFFT_N] = {0};
	fftw_complex doutCpx[FFT_IFFT_N] = {0};
	float dout[FFT_IFFT_N] = {0};
	float err = 0;

	// convert doutRef to complex array
	for (i = 0; i < (2*FFT_IFFT_N); i += 2)
	{
		dinCpx[i>>1] = doutRef[i] + doutRef[i+1]*I;
	}

	// create ifft plan
	ifftP = fftw_plan_dft_1d(FFT_IFFT_N, dinCpx, doutCpx, FFTW_BACKWARD, FFTW_ESTIMATE);

	// run fft
	fftw_execute(ifftP);

	// destroys the fft plan
	fftw_destroy_plan(ifftP);

	// convert dout complex to float
	for (i = 0; i < FFT_IFFT_N; i++)
	{
		dout[i] = crealf(doutCpx[i]) / FFT_IFFT_N;
	}

	// verify results
	for (i = 0; i < FFT_IFFT_N; i++)
	{
		err += fabs(din[i] - dout[i]);
	}
	printf("fftw_ifft_1d_array\n");
	printf("err: %f\n", err);
}
