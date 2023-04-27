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
movq	$0, -16(%rbp)
movq	-16(%rbp), %r12
movq	%r12, -24(%rbp)
movq	$0, -32(%rbp)
movq	-32(%rbp), %r12
movq	%r12, -40(%rbp)
.LABEL1:
movq	-40(%rbp), %r12
movq	%r12, -48(%rbp)
movq	$5, -56(%rbp)
movq	-48(%rbp), %r12
movq	-56(%rbp), %r13
cmpq	%r12, %r13
setg	%al
movzbq	%al, %r12
movq	%r12, -64(%rbp)
movq	-64(%rbp), %r12
cmpq	$0, %r12
je	.LABEL2
movq	-24(%rbp), %r12
movq	%r12, -96(%rbp)
movq	$1, -104(%rbp)
movq	-96(%rbp), %r12
movq	%r12, -112(%rbp)
movq	-104(%rbp), %r13
addq	%r13, -112(%rbp)
movq	-112(%rbp), %r12
movq	%r12, -24(%rbp)
movq	-40(%rbp), %r12
movq	%r12, -72(%rbp)
movq	$1, -80(%rbp)
movq	-72(%rbp), %r12
movq	%r12, -88(%rbp)
movq	-80(%rbp), %r13
addq	%r13, -88(%rbp)
movq	-88(%rbp), %r12
movq	%r12, -40(%rbp)
jmp	.LABEL1
.LABEL2:
movq	-24(%rbp), %r12
movq	%r12, -120(%rbp)
movq	-120(%rbp), %rax
movq	%rax, %rsi
leaq	.LC0(%rip), %rax
movq	%rax, %rdi
movq	$0, %rax
call printf@PLT
popq  %rdi  
leave  
ret  
