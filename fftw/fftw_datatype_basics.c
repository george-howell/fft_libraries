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
        printf("%.2f + %.2fi\t", arr[i][0], arr[i][1]);
    }
    printf("\n\n");
}

/*------------------------------------------- GLOBAL FUNCTIONS -------------------------------------------------------*/

/**
 * @brief 	Write a complex value to fftw_complex datatype
 */
void fftw_basics_value_init(void)
{
	fftw_complex data;

	// write real part
	data[0] = 2;

	// write imaginary part
	data[1] = 3;

	printf("fftw_datatypes_basics_init\n");
	printf("%.2f + %.2fi\n\n", data[0], data[1]);
}

/**
 * @brief 	Write a complex array to fftw_complex datatype
 */
void fftw_basics_array_init(void)
{
	int i;
	fftw_complex data[FFTW_ARRAY_LEN];

	// write complex data
	for (i = 0; i < FFTW_ARRAY_LEN; i++)
	{
		data[i][0] = i+1;
		data[i][1] = i+2;
	}

	printf("fftw_datatypes_basics_array_init\n");
	print_cpx_1d_array(FFTW_ARRAY_LEN, data);
}
