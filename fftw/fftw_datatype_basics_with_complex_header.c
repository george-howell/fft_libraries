/***********************************************************************************************************************
 * @file    fftw_datatype_basics.c
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
#include <complex.h>

#include "fftw3.h"

/*------------------------------------------- EXTERN VARIABLES -------------------------------------------------------*/
/*------------------------------------------- PRIVATE MACROS AND DEFINES ---------------------------------------------*/

#define FFTW_ARRAY_LEN				5

/*------------------------------------------- PRIVATE TYPEDEFS -------------------------------------------------------*/
/*------------------------------------------- STATIC VARIABLES -------------------------------------------------------*/
/*------------------------------------------- GLOBAL VARIABLES -------------------------------------------------------*/
/*------------------------------------------- STATIC FUNCTION PROTOTYPES ---------------------------------------------*/

static void print_cpx_1d_array(int len, fftw_complex arr[len]);

/*------------------------------------------- STATIC FUNCTIONS -------------------------------------------------------*/

static void print_cpx_1d_array(int len, fftw_complex arr[len])
{
    int i;

    for (i = 0; i < len; i++)
    {
        printf("%.2f + %.2fi\t", crealf(arr[i]), cimag(arr[i]));
    }
    printf("\n\n");
}

/*------------------------------------------- GLOBAL FUNCTIONS -------------------------------------------------------*/

/**
 * @brief 	Write a complex value to fftw_complex datatype
 */
void fftw_basics_init_value_complex_h(void)
{
	fftw_complex data;

	// write complex data
	data = 2 + 3*I;

	printf("fftw_basics_init_value_complex_h\n");
	printf("%.2f + %.2fi\n\n", crealf(data), cimag(data));
}

/**
 * @brief 	Write a complex array to fftw_complex datatype
 */
void fftw_basics_init_array_complex_h(void)
{
	int i;
	fftw_complex data[FFTW_ARRAY_LEN];

	// write complex data
	for (i = 0; i < FFTW_ARRAY_LEN; i++)
	{
		data[i] = (i+1) + (i+2)*I;
	}

	printf("fftw_basics_init_array_complex_h\n");
	print_cpx_1d_array(FFTW_ARRAY_LEN, data);
}

/**
 * @brief 	cast an array to complex format
 */
void fftw_basics_init_cast_array_complex_h(void)
{
	int i;

	float arr[4] = {3.0, 4.3, 6.3, 7.7};

	fftwf_complex *arrCpx;

	arrCpx = (fftwf_complex*)arr;

	printf("fftw_basics_init_cast_array_complex_h\n");
	for (i = 0; i < 2; i++)
	{
		printf("%.2f + %.2fi\t", crealf(arrCpx[i]), cimag(arrCpx[i]));
	}
	printf("\n\n");

	float *pArr = arr;

	fftwf_complex *arrCpxP;

	arrCpxP = (fftwf_complex*)pArr;

	for (i = 0; i < 2; i++)
	{
		printf("%.2f + %.2fi\t", crealf(arrCpxP[i]), cimag(arrCpxP[i]));
	}
	printf("\n\n");
}
