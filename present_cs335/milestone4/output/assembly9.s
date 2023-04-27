.data
ptr_fil: .quad 0
.LC0:
.string "%ld "
 .text
.globl	call  
.type	call,  @function  
call:  
endbr64  
pushq	%rbp  
movq	%rsp,  %rbp  
pushq  %rdi  
subq	$1600, %rsp
movq	$2, -8(%rbp)
movq	16(%rbp), %r12
movq	%r12, -16(%rbp)
movq	-8(%rbp), %r12
movq	-16(%rbp), %r13
imulq	%r12, %r13
movq	%r13, -24(%rbp)
movq	-24(%rbp), %rax
popq  %rdi  
leave  
ret  
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
.LABEL1:
movq	-24(%rbp), %r12
movq	%r12, -32(%rbp)
movq	$0, -40(%rbp)
movq	-32(%rbp), %r12
movq	-40(%rbp), %r13
cmpq	%r12, %r13
setl	%al
movzbq	%al, %r12
movq	%r12, -48(%rbp)
movq	-48(%rbp), %r12
cmpq	$0, %r12
je	.LABEL2
movq	-24(%rbp), %r12
movq	%r12, -56(%rbp)
movq	$1, -64(%rbp)
movq	-56(%rbp), %r12
movq	%r12, -72(%rbp)
movq	-64(%rbp), %r13
subq	%r13, -72(%rbp)
movq	-72(%rbp), %r12
movq	%r12, -24(%rbp)
jmp	.LABEL1
.LABEL2:
movq	-24(%rbp), %r12
movq	%r12, -80(%rbp)
pushq	-80(%rbp)
call	call
addq	$8, %rsp
movq	%rax, -24(%rbp)
movq	-24(%rbp), %r12
movq	%r12, -88(%rbp)
movq	-88(%rbp), %rax
movq	%rax, %rsi
leaq	.LC0(%rip), %rax
movq	%rax, %rdi
movq	$0, %rax
call printf@PLT
popq  %rdi  
leave  
ret  
