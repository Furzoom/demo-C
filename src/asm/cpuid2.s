#cpuid2.s - By furzoom @ Mar 1, 2015
.section .data
output:
  .asciz "The processor vendor ID is '%s'\n"
.section .bss
  .lcomm buffer, 12
.section .text
.globl _start
_start:
  nop
  movl $0, %eax
  cpuid
  movl $buffer, %edi
  movl %ebx, (%edi)
  movl %edx, 4(%edi)
  movl %ecx, 8(%edi)
  pushl $buffer
  pushl $output
  call printf
  
  movl $1, %eax
  movl $0, %ebx
  int $0x80
