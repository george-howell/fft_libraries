/***********************************************************************************************************************
 * @file    main.h
 *
 * @brief   brief description
 * 
 * detailed description
 *  
 * @par
 * @author 	george_howell
 **********************************************************************************************************************/

#ifndef _MAIN_H_
#define _MAIN_H_

#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------- INCLUDES ---------------------------------------------------------------*/
/*------------------------------------------- MACROS AND DEFINES -----------------------------------------------------*/
/*------------------------------------------- TYPEDEFS ---------------------------------------------------------------*/
/*------------------------------------------- EXPORTED VARIABLES -----------------------------------------------------*/
/*------------------------------------------- GLOBAL FUNCTION PROTOTYPES ---------------------------------------------*/

/*
 * Basic - No Complex.h
 */

void fftw_basics_value_init(void);
void fftw_basics_array_init(void);
void fftw_basics_init_cast_array_complex_h(void);

/*
 * Basic - With Complex.h
 */

void fftw_basics_init_value_complex_h(void);
void fftw_basics_init_array_complex_h(void);

/*
 * FFT
 */

void fftw_fft_1d_array(void);
void fftw_ifft_1d_array(void);


#ifdef __cplusplus
}
#endif

#endif /* _MAIN_H_ */
