# cmp.s - By furzoom @ Mar 7, 2015
.section .text
.globl _start
_start:
  nop
  movl $15, %eax
  movl $10, %ebx
  cmp %eax, %ebx
  jge greater
  movl $1, %eax
  int $0x80
greater:
  movl $20, %ebx
  movl $1, %eax
  int $0x80
