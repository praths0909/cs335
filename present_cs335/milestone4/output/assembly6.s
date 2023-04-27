.data
ptr_fil: .quad 0
.LC0:
.string "%ld "
 .text
.globl	fact2  
.type	fact2,  @function  
fact2:  
endbr64  
pushq	%rbp  
movq	%rsp,  %rbp  
pushq  %rdi  
subq	$1600, %rsp
movq	16(%rbp), %r12
movq	%r12, -16(%rbp)
movq	$0, -24(%rbp)
movq	-16(%rbp), %r12
movq	-24(%rbp), %r13
cmpq	%r12, %r13
sete	%al
movzbq	%al, %r12
movq	%r12, -32(%rbp)
movq	-32(%rbp), %r12
cmpq	$0, %r12
je	.LABEL1
movq	$1, -40(%rbp)
movq	-40(%rbp), %rax
jmp	.LABEL2
.LABEL1:
movq	16(%rbp), %r12
movq	%r12, -48(%rbp)
movq	-48(%rbp), %r12
movq	%r12, -8(%rbp)
movq	-8(%rbp), %r12
movq	%r12, -56(%rbp)
movq	-56(%rbp), %rax
.LABEL2:
popq  %rdi  
leave  
ret  
.globl	fact  
.type	fact,  @function  
fact:  
endbr64  
pushq	%rbp  
movq	%rsp,  %rbp  
pushq  %rdi  
subq	$1600, %rsp
movq	16(%rbp), %r12
movq	%r12, -16(%rbp)
movq	$0, -24(%rbp)
movq	-16(%rbp), %r12
movq	-24(%rbp), %r13
cmpq	%r12, %r13
sete	%al
movzbq	%al, %r12
movq	%r12, -32(%rbp)
movq	-32(%rbp), %r12
cmpq	$0, %r12
je	.LABEL3
movq	$1, -40(%rbp)
movq	-40(%rbp), %rax
jmp	.LABEL4
.LABEL3:
movq	16(%rbp), %r12
movq	%r12, -48(%rbp)
movq	16(%rbp), %r12
movq	%r12, -56(%rbp)
movq	$1, -64(%rbp)
movq	-56(%rbp), %r12
movq	%r12, -72(%rbp)
movq	-64(%rbp), %r13
subq	%r13, -72(%rbp)
pushq	-72(%rbp)
call	fact2
addq	$8, %rsp
movq	-48(%rbp), %r12
movq	%rax, %r13
imulq	%r12, %r13
movq	%r13, -80(%rbp)
movq	-80(%rbp), %r12
movq	%r12, -8(%rbp)
movq	-8(%rbp), %r12
movq	%r12, -88(%rbp)
movq	-88(%rbp), %rax
.LABEL4:
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
movq	$5, -16(%rbp)
movq	-16(%rbp), %r12
movq	%r12, -24(%rbp)
movq	-24(%rbp), %r12
movq	%r12, -32(%rbp)
movq	-32(%rbp), %rax
movq	%rax, %rsi
leaq	.LC0(%rip), %rax
movq	%rax, %rdi
movq	$0, %rax
call printf@PLT
movq	-24(%rbp), %r12
movq	%r12, -40(%rbp)
pushq	-40(%rbp)
call	fact
addq	$8, %rsp
movq	%rax, -24(%rbp)
movq	-24(%rbp), %r12
movq	%r12, -48(%rbp)
movq	-48(%rbp), %rax
movq	%rax, %rsi
leaq	.LC0(%rip), %rax
movq	%rax, %rdi
movq	$0, %rax
call printf@PLT
popq  %rdi  
leave  
ret  
