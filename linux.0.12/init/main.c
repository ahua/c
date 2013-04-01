
static long memory_end = 0;           // total memory size byte
static long buffer_memory_end = 0;    // the end of buffer
static long main_memory_start = 0;    // the start of main memory equals the end of buffer

void main(void)
{
  memory_end = (1<<20) + (*(unsigned short *)0x90002);
  memory_end &= 0xfffff000;
  if( memory_end > 16 * 1024 * 1024) 
    memory_end = 16*1024*1024;
  buffer_memory_end = 4*1024*1024;
  main_memory_start = buffer_memory_end;

  mem_init(main_memory_start, memory_end);
  tty_init();

  for(;;);
}
