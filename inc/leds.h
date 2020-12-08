/*!
 *	File:	leds.h
 *	Author:	Martin Mello Teggia
 *  Date:	2020-11-04
 *
 */

#ifndef MISCODIGOS_SEMAPHORE_INC_LEDS_H_
#define MISCODIGOS_SEMAPHORE_INC_LEDS_H_


// EDU-CIAA-NXP V1.1 primer tirada (abajo dice ASSISI)
#define edu_ciaa_nxp_v_1_1_1

// EDU-CIAA-NXP V1.1 segunda tirada (abajo dice ASEMBLI)
//#define edu_ciaa_nxp_v_1_1_1

#if defined(edu_ciaa_nxp_v_1_1_0)
   #define LUZ_ROJA     LED2
   #define LUZ_AMARILLA LED1
   #define LUZ_VERDE    LEDG
#elif defined(edu_ciaa_nxp_v_1_1_1)
   #define LUZ_ROJA     LED2
   #define LUZ_AMARILLA LED1
   #define LUZ_VERDE    LED3
   #define LUZ_ROJA_RGB     LEDR
   #define LUZ_AMARILLA_RGB LEDB
   #define LUZ_VERDE_RGB    LEDG
#endif

void apagarLeds(void);
void apagarLedsRGB(void);
inline void encenderVerde();
inline void encenderRojo();
inline void encenderAmarillo();
inline void encenderVerdeRGB();
inline void encenderRojoRGB();
inline void encenderAmarilloRGB();
inline void _encenderLed(gpioMap_t);

#endif /* MISCODIGOS_SEMAPHORE_INC_LEDS_H_ */
