# loop.s - By furzoom @ Mar 8, 2015
.section .data
output:
  .asciz "The value is: %d\n"
.section .text
.globl _start
_start:
  movl $0, %ecx
  movl $0, %eax
loop1:
  addl %ecx, %eax
  loop loop1
  pushl %eax
  pushl $output
  call printf
  addl $8, %esp
  movl $1, %eax
  movl $0, %ebx
  int $0x80
