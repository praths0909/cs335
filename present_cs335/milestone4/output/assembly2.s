.data
ptr_fil: .quad 0
ptr_sum: .quad 0
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
movq	$0, -16(%rbp)
movq	$8, %rdi
call malloc
movq	%rax, ptr_sum
movq	$0, %rax
movq	ptr_sum, %rdi
movq	-16(%rbp), %r14
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
.LABEL7:
movq	-24(%rbp), %r12
movq	%r12, -32(%rbp)
movq	$5, -40(%rbp)
movq	-32(%rbp), %r12
movq	-40(%rbp), %r13
cmpq	%r12, %r13
setg	%al
movzbq	%al, %r12
movq	%r12, -48(%rbp)
movq	-48(%rbp), %r12
cmpq	$0, %r12
je	.LABEL8
movq	$0, -80(%rbp)
movq	-80(%rbp), %r12
movq	%r12, -88(%rbp)
.LABEL5:
movq	-88(%rbp), %r12
movq	%r12, -96(%rbp)
movq	$5, -104(%rbp)
movq	-96(%rbp), %r12
movq	-104(%rbp), %r13
cmpq	%r12, %r13
setg	%al
movzbq	%al, %r12
movq	%r12, -112(%rbp)
movq	-112(%rbp), %r12
cmpq	$0, %r12
je	.LABEL6
movq	$0, -120(%rbp)
movq	-120(%rbp), %r12
movq	%r12, -128(%rbp)
.LABEL3:
movq	-128(%rbp), %r12
movq	%r12, -136(%rbp)
movq	$2, -144(%rbp)
movq	-136(%rbp), %rax
movq	-144(%rbp), %r13
cqto
idivq	%r13
movq	%rdx, -152(%rbp)
movq	$0, -160(%rbp)
movq	-152(%rbp), %r12
movq	-160(%rbp), %r13
cmpq	%r12, %r13
sete	%al
movzbq	%al, %r12
movq	%r12, -168(%rbp)
movq	-168(%rbp), %r12
cmpq	$0, %r12
je	.LABEL1
movq	$0, %rax
movq	ptr_sum, %rdi
movq	(%rdi,%rax), %r14
movq	%r14, -176(%rbp)
movq	$2, -184(%rbp)
movq	-176(%rbp), %r12
movq	%r12, -192(%rbp)
movq	-184(%rbp), %r13
addq	%r13, -192(%rbp)
movq	$0, %rax
movq	ptr_sum, %rdi
movq	-192(%rbp), %r14
movq	%r14, (%rdi,%rax)
jmp	.LABEL2
.LABEL1:
movq	$0, %rax
movq	ptr_sum, %rdi
movq	(%rdi,%rax), %r14
movq	%r14, -200(%rbp)
movq	$3, -208(%rbp)
movq	-200(%rbp), %r12
movq	%r12, -216(%rbp)
movq	-208(%rbp), %r13
addq	%r13, -216(%rbp)
movq	$0, %rax
movq	ptr_sum, %rdi
movq	-216(%rbp), %r14
movq	%r14, (%rdi,%rax)
.LABEL2:
movq	-128(%rbp), %r12
movq	%r12, -224(%rbp)
movq	$1, -232(%rbp)
movq	-224(%rbp), %r12
movq	%r12, -240(%rbp)
movq	-232(%rbp), %r13
addq	%r13, -240(%rbp)
movq	-240(%rbp), %r12
movq	%r12, -128(%rbp)
movq	-128(%rbp), %r12
movq	%r12, -248(%rbp)
movq	$5, -256(%rbp)
movq	-248(%rbp), %r12
movq	-256(%rbp), %r13
cmpq	%r12, %r13
setg	%al
movzbq	%al, %r12
movq	%r12, -264(%rbp)
movq	-264(%rbp), %r12
cmpq	$0, %r12
jne	.LABEL3
.LABEL4:
movq	-88(%rbp), %r12
movq	%r12, -272(%rbp)
movq	$1, -280(%rbp)
movq	-272(%rbp), %r12
movq	%r12, -288(%rbp)
movq	-280(%rbp), %r13
addq	%r13, -288(%rbp)
movq	-288(%rbp), %r12
movq	%r12, -88(%rbp)
jmp	.LABEL5
.LABEL6:
movq	-24(%rbp), %r12
movq	%r12, -56(%rbp)
movq	$1, -64(%rbp)
movq	-56(%rbp), %r12
movq	%r12, -72(%rbp)
movq	-64(%rbp), %r13
addq	%r13, -72(%rbp)
movq	-72(%rbp), %r12
movq	%r12, -24(%rbp)
jmp	.LABEL7
.LABEL8:
movq	$0, %rax
movq	ptr_sum, %rdi
movq	(%rdi,%rax), %r14
movq	%r14, -296(%rbp)
movq	-296(%rbp), %rax
movq	%rax, %rsi
leaq	.LC0(%rip), %rax
movq	%rax, %rdi
movq	$0, %rax
call printf@PLT
popq  %rdi  
leave  
ret  
