#ifndef _TTY_H
#define _TTY_H

#include <termios.h>

struct tty_queue{
  unsigned long data;
  unsigned long head;
  unsigned long tail;
  //struct task_struct *proc_list;
  char buf[1024];
};

struct tty_struct{
  struct termios termios;
  int pgrp;
  int session;
  int stopped;
  void (*write)(struct tty_struct *tty);
  struct tty_queue *read_q;
  struct tty_queue *write_q;
  struct tty_queue *secondary;
};

#endif
