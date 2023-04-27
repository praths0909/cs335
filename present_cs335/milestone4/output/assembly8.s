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
movq	$3, -16(%rbp)
movq	$3, -24(%rbp)
movq	$0, -104(%rbp)
movq	-104(%rbp), %r12
movq	%r12, -112(%rbp)
movq	$0, -120(%rbp)
movq	-120(%rbp), %r12
movq	%r12, -128(%rbp)
.LABEL3:
movq	-128(%rbp), %r12
movq	%r12, -136(%rbp)
movq	$3, -144(%rbp)
movq	-136(%rbp), %r12
movq	-144(%rbp), %r13
cmpq	%r12, %r13
setg	%al
movzbq	%al, %r12
movq	%r12, -152(%rbp)
movq	-152(%rbp), %r12
cmpq	$0, %r12
je	.LABEL4
movq	$0, -184(%rbp)
movq	-184(%rbp), %r12
movq	%r12, -192(%rbp)
.LABEL1:
movq	-192(%rbp), %r12
movq	%r12, -200(%rbp)
movq	$3, -208(%rbp)
movq	-200(%rbp), %r12
movq	-208(%rbp), %r13
cmpq	%r12, %r13
setg	%al
movzbq	%al, %r12
movq	%r12, -216(%rbp)
movq	-216(%rbp), %r12
cmpq	$0, %r12
je	.LABEL2
movq	-128(%rbp), %r12
movq	%r12, -248(%rbp)
movq	-248(%rbp), %r12
movq	$24, %r13
imulq	%r12, %r13
movq	%r13, -256(%rbp)
movq	-192(%rbp), %r12
movq	%r12, -264(%rbp)
movq	-264(%rbp), %r12
movq	$8, %r13
imulq	%r12, %r13
movq	%r13, -280(%rbp)
movq	-264(%rbp), %r12
movq	%r12, -272(%rbp)
movq	-280(%rbp), %r13
addq	%r13, -272(%rbp)
movq	-128(%rbp), %r12
movq	%r12, -288(%rbp)
movq	-192(%rbp), %r12
movq	%r12, -296(%rbp)
movq	-288(%rbp), %r12
movq	%r12, -304(%rbp)
movq	-296(%rbp), %r13
addq	%r13, -304(%rbp)
movq	-304(%rbp), %r12
movq	-272(%rbp), %r13
addq	$32, %r13
imulq	$-1, %r13
movq	%rbp, %r15
addq	%r13, %rbp
movq	%r12, 0(%rbp)
movq	%r15, %rbp
movq	-192(%rbp), %r12
movq	%r12, -224(%rbp)
movq	$1, -232(%rbp)
movq	-224(%rbp), %r12
movq	%r12, -240(%rbp)
movq	-232(%rbp), %r13
addq	%r13, -240(%rbp)
movq	-240(%rbp), %r12
movq	%r12, -192(%rbp)
jmp	.LABEL1
.LABEL2:
movq	-128(%rbp), %r12
movq	%r12, -160(%rbp)
movq	$1, -168(%rbp)
movq	-160(%rbp), %r12
movq	%r12, -176(%rbp)
movq	-168(%rbp), %r13
addq	%r13, -176(%rbp)
movq	-176(%rbp), %r12
movq	%r12, -128(%rbp)
jmp	.LABEL3
.LABEL4:
movq	$0, -312(%rbp)
movq	-312(%rbp), %r12
movq	$24, %r13
imulq	%r12, %r13
movq	%r13, -320(%rbp)
movq	$0, -328(%rbp)
movq	-328(%rbp), %r12
movq	$8, %r13
imulq	%r12, %r13
movq	%r13, -344(%rbp)
movq	-328(%rbp), %r12
movq	%r12, -336(%rbp)
movq	-344(%rbp), %r13
addq	%r13, -336(%rbp)
movq	-336(%rbp), %r13
addq	$32, %r13
imulq	$-1, %r13
movq	%rbp, %r15
addq	%r13, %rbp
movq	0(%rbp), %r12
movq	%r15, %rbp
movq	%r12, -352(%rbp)
movq	-352(%rbp), %r12
movq	%r12, -360(%rbp)
movq	-360(%rbp), %rax
movq	%rax, %rsi
leaq	.LC0(%rip), %rax
movq	%rax, %rdi
movq	$0, %rax
call printf@PLT
popq  %rdi  
leave  
ret  
