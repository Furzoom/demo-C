# sse.s - By furzoom @ Mar 15, 2015
.section .data
values1:
  .int 1, -1, 0, 135246
values2:
  .quad 1, -1
.section .text
.globl _start
_start:
  nop
  movdqu values1, %xmm0
  movdqu values2, %xmm1

  movl $1, %eax
  movl $0, %ebx
  int $0x80
