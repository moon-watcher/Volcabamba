#include "dev.h"


void dev_init ( unsigned int dev, unsigned int inv )
{
	DEV          = dev;
	INVULNERABLE = inv;

	devs0 = devs1 = devs2 = devs3 = devs4 = devs5 = 0;
	devu0 = devu1 = devu2 = devu3 = devu4 = devu5 = 0;
}
