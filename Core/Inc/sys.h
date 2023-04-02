#ifndef _SYS_H
#define _SYS_H

#define Mode_Welcome 1
#define Mode_Password 2
#define Mode_Success 3
#define Mode_Fail 4
#define Mode_Access 5
#define Mode_Get 6
#define Mode_Sure 7
#define Mpde_Admin 8

#include "stdint.h"

extern uint8_t sysMode;

uint8_t switch_keyboard(uint8_t u);
#endif