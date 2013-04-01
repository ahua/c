#include <linux/tty.h>

struct tty_struct tty_table[256];
#define con_table tty_table


void tty_init(void)
{
  
}
