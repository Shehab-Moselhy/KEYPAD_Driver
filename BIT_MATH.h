/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(Reg,BITNO)          (Reg) |=  (1 << (BITNO))
#define CLR_BIT(Reg,BITNO)          (Reg) &= ~(1 << (BITNO))
#define TOG_BIT(Reg,BITNO) 			(Reg) ^=  (1 << (BITNO))
#define GET_BIT(Reg,BITNO) 			(((Reg) >> (BITNO)) & 0x01)

#define  CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0)           CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define  CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)    	 0b##b7##b6##b5##b4##b3##b2##b1##b0


#endif
