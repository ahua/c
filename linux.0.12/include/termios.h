#ifndef _TERMIOS_H
#define _TERMIOS_H

struct termios{
  unsigned long c_iflag;
  unsigned long c_oflag;
  unsigned long c_cflag;
  unsigned long c_lflag;
  unsigned char c_line;
  unsigned char c_cc[17];
};

#endif
