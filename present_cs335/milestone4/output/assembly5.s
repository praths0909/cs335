.data
ptr_fil: .quad 0
.LC0:
.string "%ld "
 .text
.globl	main  
.type	main,  @function  
main:  
endbr64  
pushq	%rbp  
movq	%rsp,  %rbp  
pushq  %rdi  
subq	$1600, %rsp
movq	$7, -8(%rbp)
movq	$8, %rdi
call malloc
movq	%rax, ptr_fil
movq	$0, %rax
movq	ptr_fil, %rdi
movq	-8(%rbp), %r14
movq	%r14, (%rdi,%rax)
movq	$0, %rax
movq	ptr_fil, %rdi
movq	(%rdi,%rax), %r14
movq	%r14, -8(%rbp)
movq	-8(%rbp), %rax
movq	%rax, %rsi
leaq	.LC0(%rip), %rax
movq	%rax, %rdi
movq	$0, %rax
call printf@PLT
movq	-8(%rbp), %r12
movq	%r12, -16(%rbp)
movq	-8(%rbp), %r12
movq	%r12, -24(%rbp)
movq	$30, -32(%rbp)
movq	-32(%rbp), %r12
movq	%r12, -40(%rbp)
movq	$1, -48(%rbp)
movq	-48(%rbp), %r12
movq	%r12, -56(%rbp)
movq	-8(%rbp), %r12
movq	%r12, -64(%rbp)
movq	-8(%rbp), %r12
movq	%r12, -72(%rbp)
movq	-64(%rbp), %r12
movq	%r12, -80(%rbp)
movq	-72(%rbp), %r13
addq	%r13, -80(%rbp)
movq	-80(%rbp), %r12
movq	%r12, -88(%rbp)
movq	-56(%rbp), %r12
movq	%r12, -88(%rbp)
movq	-40(%rbp), %r12
movq	%r12, -96(%rbp)
movq	-88(%rbp), %r12
movq	%r12, -104(%rbp)
movq	-96(%rbp), %r13
addq	%r13, -104(%rbp)
movq	-104(%rbp), %rax
movq	%rax, %rsi
leaq	.LC0(%rip), %rax
movq	%rax, %rdi
movq	$0, %rax
call printf@PLT
popq  %rdi  
leave  
ret  
