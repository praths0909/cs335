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
movq	$5, -16(%rbp)
movq	$0, -64(%rbp)
movq	-64(%rbp), %r12
movq	%r12, -72(%rbp)
.LABEL5:
movq	-72(%rbp), %r12
movq	%r12, -80(%rbp)
movq	$5, -88(%rbp)
movq	-80(%rbp), %r12
movq	-88(%rbp), %r13
cmpq	%r12, %r13
setg	%al
movzbq	%al, %r12
movq	%r12, -96(%rbp)
movq	-96(%rbp), %r12
cmpq	$0, %r12
je	.LABEL6
movq	-72(%rbp), %r12
movq	%r12, -128(%rbp)
movq	-128(%rbp), %r12
movq	%r12, -136(%rbp)
.LABEL3:
movq	-136(%rbp), %r12
movq	%r12, -144(%rbp)
movq	$5, -152(%rbp)
movq	-144(%rbp), %r12
movq	-152(%rbp), %r13
cmpq	%r12, %r13
setg	%al
movzbq	%al, %r12
movq	%r12, -160(%rbp)
movq	-160(%rbp), %r12
cmpq	$0, %r12
je	.LABEL4
movq	$0, -192(%rbp)
movq	-192(%rbp), %r12
movq	%r12, -200(%rbp)
.LABEL1:
movq	-200(%rbp), %r12
movq	%r12, -208(%rbp)
movq	$5, -216(%rbp)
movq	-208(%rbp), %r12
movq	-216(%rbp), %r13
cmpq	%r12, %r13
setg	%al
movzbq	%al, %r12
movq	%r12, -224(%rbp)
movq	-224(%rbp), %r12
cmpq	$0, %r12
je	.LABEL2
movq	-200(%rbp), %r12
movq	%r12, -232(%rbp)
movq	$1, -240(%rbp)
movq	-232(%rbp), %r12
movq	%r12, -248(%rbp)
movq	-240(%rbp), %r13
addq	%r13, -248(%rbp)
movq	-248(%rbp), %r12
movq	%r12, -200(%rbp)
jmp	.LABEL1
.LABEL2:
movq	-200(%rbp), %r12
movq	%r12, -256(%rbp)
movq	-256(%rbp), %rax
movq	%rax, %rsi
leaq	.LC0(%rip), %rax
movq	%rax, %rdi
movq	$0, %rax
call printf@PLT
movq	-136(%rbp), %r12
movq	%r12, -168(%rbp)
movq	$1, -176(%rbp)
movq	-168(%rbp), %r12
movq	%r12, -184(%rbp)
movq	-176(%rbp), %r13
addq	%r13, -184(%rbp)
movq	-184(%rbp), %r12
movq	%r12, -136(%rbp)
jmp	.LABEL3
.LABEL4:
movq	-72(%rbp), %r12
movq	%r12, -104(%rbp)
movq	$1, -112(%rbp)
movq	-104(%rbp), %r12
movq	%r12, -120(%rbp)
movq	-112(%rbp), %r13
addq	%r13, -120(%rbp)
movq	-120(%rbp), %r12
movq	%r12, -72(%rbp)
jmp	.LABEL5
.LABEL6:
popq  %rdi  
leave  
ret  
