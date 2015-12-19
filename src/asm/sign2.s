# sign2.s - By furzoom @ Mar 7, 2015
.section .text
.globl _start
_start:
  nop
  movl $1, %eax
#  movl $0x10000000, %edi
  movl $0x0, %edi
  subl $1, %edi
  js overhere
  movl $1, %ebx
  int $0x80
overhere:
  movl $0, %ebx
  int $0x80
