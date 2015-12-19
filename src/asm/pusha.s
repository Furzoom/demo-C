# pusha.s - By furzoom @ Mar 4, 2015
.section .text
.globl _start
_start:
  nop
  movl $1, %eax
  movl $4, %edi
  pusha
  movl $5, %eax
  popa
  movl $1, %eax
  movl $0, %ebx
  int $0x80
