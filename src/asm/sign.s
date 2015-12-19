# sign.s - By furzoom @ Mar 7, 2015
.section .data
value:
  .int 1, 2, 3, 4
output:
  .asciz "The value is: %d\n"
.section .text
.globl _start
_start:
  movl $3, %edi
loop:
  pushl value(, %edi, 4)
  pushl $output
  call printf
  addl $8, %esp
  dec %edi
  jns loop
  movl $1, %eax
  movl $0, %ebx
  int $0x80
