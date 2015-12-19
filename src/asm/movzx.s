# movzx.s - By furzoom @ Mar 12, 2015
.section .text
.globl _start
_start:
  nop
  movl $279, %ecx
  movzx %cl, %ebx
  movl $1, %eax
  int $0x80
