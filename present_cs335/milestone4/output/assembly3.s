.data
ptr_fil: .quad 0
.LC0:
.string "%ld "
 .text
.globl	factorial  
.type	factorial,  @function  
factorial:  
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
movq	16(%rbp), %r12
movq	%r12, -56(%rbp)
movq	$1, -64(%rbp)
movq	-56(%rbp), %r12
movq	%r12, -72(%rbp)
movq	-64(%rbp), %r13
subq	%r13, -72(%rbp)
pushq	-72(%rbp)
call	factorial
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
.LABEL2:
popq  %rdi  
leave  
ret  
.globl	fibonacci  
.type	fibonacci,  @function  
fibonacci:  
endbr64  
pushq	%rbp  
movq	%rsp,  %rbp  
pushq  %rdi  
subq	$1600, %rsp
movq	16(%rbp), %r12
movq	%r12, -8(%rbp)
movq	$0, -16(%rbp)
movq	-8(%rbp), %r12
movq	-16(%rbp), %r13
cmpq	%r12, %r13
sete	%al
movzbq	%al, %r12
movq	%r12, -24(%rbp)
movq	-24(%rbp), %r12
cmpq	$0, %r12
je	.LABEL5
movq	$1, -32(%rbp)
movq	-32(%rbp), %rax
jmp	.LABEL6
.LABEL5:
movq	16(%rbp), %r12
movq	%r12, -40(%rbp)
movq	$1, -48(%rbp)
movq	-40(%rbp), %r12
movq	-48(%rbp), %r13
cmpq	%r12, %r13
sete	%al
movzbq	%al, %r12
movq	%r12, -56(%rbp)
movq	-56(%rbp), %r12
cmpq	$0, %r12
je	.LABEL3
movq	$1, -64(%rbp)
movq	-64(%rbp), %rax
jmp	.LABEL4
.LABEL3:
movq	16(%rbp), %r12
movq	%r12, -72(%rbp)
movq	$1, -80(%rbp)
movq	-72(%rbp), %r12
movq	%r12, -88(%rbp)
movq	-80(%rbp), %r13
subq	%r13, -88(%rbp)
pushq	-88(%rbp)
call	fibonacci
addq	$8, %rsp
movq	%rax, -96(%rbp)
movq	16(%rbp), %r12
movq	%r12, -104(%rbp)
movq	$2, -112(%rbp)
movq	-104(%rbp), %r12
movq	%r12, -120(%rbp)
movq	-112(%rbp), %r13
subq	%r13, -120(%rbp)
pushq	-120(%rbp)
call	fibonacci
addq	$8, %rsp
movq	%rax, -128(%rbp)
movq	-96(%rbp), %r12
movq	%r12, -136(%rbp)
movq	-128(%rbp), %r12
movq	%r12, -144(%rbp)
movq	-136(%rbp), %r12
movq	%r12, -152(%rbp)
movq	-144(%rbp), %r13
addq	%r13, -152(%rbp)
movq	-152(%rbp), %rax
.LABEL4:
.LABEL6:
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
movq	-32(%rbp), %r12
movq	%r12, -40(%rbp)
movq	-40(%rbp), %r12
movq	%r12, -48(%rbp)
movq	-48(%rbp), %r12
movq	%r12, -72(%rbp)
movq	-72(%rbp), %rax
movq	%rax, %rsi
leaq	.LC0(%rip), %rax
movq	%rax, %rdi
movq	$0, %rax
call printf@PLT
movq	-48(%rbp), %r12
movq	%r12, -80(%rbp)
pushq	-80(%rbp)
call	factorial
addq	$8, %rsp
movq	%rax, -56(%rbp)
movq	-56(%rbp), %r12
movq	%r12, -88(%rbp)
movq	-88(%rbp), %rax
movq	%rax, %rsi
leaq	.LC0(%rip), %rax
movq	%rax, %rdi
movq	$0, %rax
call printf@PLT
movq	$10, -96(%rbp)
movq	$0, -184(%rbp)
movq	-184(%rbp), %r12
movq	%r12, -192(%rbp)
.LABEL7:
movq	-192(%rbp), %r12
movq	%r12, -200(%rbp)
movq	$10, -208(%rbp)
movq	-200(%rbp), %r12
movq	-208(%rbp), %r13
cmpq	%r12, %r13
setg	%al
movzbq	%al, %r12
movq	%r12, -216(%rbp)
movq	-216(%rbp), %r12
cmpq	$0, %r12
je	.LABEL8
movq	-192(%rbp), %r12
movq	%r12, -248(%rbp)
pushq	-248(%rbp)
call	fibonacci
addq	$8, %rsp
movq	%rax, -256(%rbp)
movq	-192(%rbp), %r12
movq	%r12, -264(%rbp)
movq	-264(%rbp), %r12
movq	$8, %r13
imulq	%r12, %r13
movq	%r13, -272(%rbp)
movq	-256(%rbp), %r12
movq	%r12, -280(%rbp)
movq	-280(%rbp), %r12
movq	-272(%rbp), %r13
addq	$104, %r13
imulq	$-1, %r13
movq	%rbp, %r15
addq	%r13, %rbp
movq	%r12, 0(%rbp)
movq	%r15, %rbp
movq	-192(%rbp), %r12
movq	%r12, -288(%rbp)
movq	-288(%rbp), %r12
movq	$8, %r13
imulq	%r12, %r13
movq	%r13, -296(%rbp)
movq	-296(%rbp), %r13
addq	$104, %r13
imulq	$-1, %r13
movq	%rbp, %r15
addq	%r13, %rbp
movq	0(%rbp), %r12
movq	%r15, %rbp
movq	%r12, -304(%rbp)
movq	-304(%rbp), %r12
movq	%r12, -312(%rbp)
movq	-312(%rbp), %rax
movq	%rax, %rsi
leaq	.LC0(%rip), %rax
movq	%rax, %rdi
movq	$0, %rax
call printf@PLT
movq	-192(%rbp), %r12
movq	%r12, -224(%rbp)
movq	$1, -232(%rbp)
movq	-224(%rbp), %r12
movq	%r12, -240(%rbp)
movq	-232(%rbp), %r13
addq	%r13, -240(%rbp)
movq	-240(%rbp), %r12
movq	%r12, -192(%rbp)
jmp	.LABEL7
.LABEL8:
movq	$7, -320(%rbp)
movq	-320(%rbp), %r12
movq	%r12, -56(%rbp)
movq	$5, -328(%rbp)
movq	-328(%rbp), %r12
movq	%r12, -48(%rbp)
.LABEL11:
movq	-48(%rbp), %r12
movq	%r12, -336(%rbp)
movq	$3, -344(%rbp)
movq	-336(%rbp), %rax
movq	-344(%rbp), %r13
cqto
idivq	%r13
movq	%rdx, -352(%rbp)
movq	$1, -360(%rbp)
movq	-352(%rbp), %r12
movq	-360(%rbp), %r13
cmpq	%r12, %r13
sete	%al
movzbq	%al, %r12
movq	%r12, -368(%rbp)
movq	-368(%rbp), %r12
cmpq	$0, %r12
je	.LABEL9
movq	-56(%rbp), %r12
movq	%r12, -376(%rbp)
movq	-56(%rbp), %r12
movq	%r12, -384(%rbp)
movq	-376(%rbp), %r12
movq	-384(%rbp), %r13
imulq	%r12, %r13
movq	%r13, -392(%rbp)
movq	-56(%rbp), %r12
movq	%r12, -400(%rbp)
movq	-392(%rbp), %rax
movq	-400(%rbp), %r13
cqto
idivq	%r13
movq	%rax, -408(%rbp)
movq	$4, -416(%rbp)
movq	-408(%rbp), %r12
movq	-416(%rbp), %r13
andq	%r12, %r13
movq	%r13, -424(%rbp)
movq	$6, -432(%rbp)
movq	$10, -440(%rbp)
movq	-432(%rbp), %r12
movq	-440(%rbp), %r13
xorq	%r12, %r13
movq	%r13, -448(%rbp)
movq	-424(%rbp), %r12
movq	-448(%rbp), %r13
orq	%r12, %r13
movq	%r13, -456(%rbp)
movq	-456(%rbp), %r12
movq	%r12, -56(%rbp)
jmp	.LABEL10
.LABEL9:
movq	-56(%rbp), %r12
movq	%r12, -464(%rbp)
movq	$4, -472(%rbp)
movq	-464(%rbp), %r12
movq	-472(%rbp), %r13
imulq	%r12, %r13
movq	%r13, -480(%rbp)
movq	-56(%rbp), %r12
movq	%r12, -488(%rbp)
movq	-480(%rbp), %rax
movq	-488(%rbp), %r13
cqto
idivq	%r13
movq	%rax, -496(%rbp)
movq	$4, -504(%rbp)
movq	-496(%rbp), %r12
movq	-504(%rbp), %r13
andq	%r12, %r13
movq	%r13, -512(%rbp)
movq	$6, -520(%rbp)
movq	$10, -528(%rbp)
movq	-520(%rbp), %r12
movq	-528(%rbp), %r13
xorq	%r12, %r13
movq	%r13, -536(%rbp)
movq	-512(%rbp), %r12
movq	-536(%rbp), %r13
orq	%r12, %r13
movq	%r13, -544(%rbp)
movq	-544(%rbp), %r12
movq	%r12, -56(%rbp)
.LABEL10:
movq	-48(%rbp), %r12
movq	%r12, -552(%rbp)
movq	$1, -560(%rbp)
movq	-552(%rbp), %r12
movq	%r12, -568(%rbp)
movq	-560(%rbp), %r13
subq	%r13, -568(%rbp)
movq	-568(%rbp), %r12
movq	%r12, -48(%rbp)
movq	-56(%rbp), %r12
movq	%r12, -576(%rbp)
movq	-576(%rbp), %rax
movq	%rax, %rsi
leaq	.LC0(%rip), %rax
movq	%rax, %rdi
movq	$0, %rax
call printf@PLT
movq	-48(%rbp), %r12
movq	%r12, -584(%rbp)
movq	$0, -592(%rbp)
movq	-584(%rbp), %r12
movq	-592(%rbp), %r13
cmpq	%r12, %r13
setl	%al
movzbq	%al, %r12
movq	%r12, -600(%rbp)
movq	-600(%rbp), %r12
cmpq	$0, %r12
jne	.LABEL11
.LABEL12:
movq	$0, -608(%rbp)
movq	-608(%rbp), %r12
movq	%r12, -616(%rbp)
.LABEL19:
movq	-616(%rbp), %r12
movq	%r12, -624(%rbp)
movq	$3, -632(%rbp)
movq	-624(%rbp), %r12
movq	-632(%rbp), %r13
cmpq	%r12, %r13
setg	%al
movzbq	%al, %r12
movq	%r12, -640(%rbp)
movq	-640(%rbp), %r12
cmpq	$0, %r12
je	.LABEL20
movq	$0, -672(%rbp)
movq	-672(%rbp), %r12
movq	%r12, -680(%rbp)
.LABEL17:
movq	-680(%rbp), %r12
movq	%r12, -688(%rbp)
movq	$4, -696(%rbp)
movq	-688(%rbp), %r12
movq	-696(%rbp), %r13
cmpq	%r12, %r13
setg	%al
movzbq	%al, %r12
movq	%r12, -704(%rbp)
movq	-704(%rbp), %r12
cmpq	$0, %r12
je	.LABEL18
movq	$0, -736(%rbp)
movq	-736(%rbp), %r12
movq	%r12, -744(%rbp)
.LABEL15:
movq	-744(%rbp), %r12
movq	%r12, -752(%rbp)
movq	$2, -760(%rbp)
movq	-752(%rbp), %r12
movq	-760(%rbp), %r13
cmpq	%r12, %r13
setg	%al
movzbq	%al, %r12
movq	%r12, -768(%rbp)
movq	-768(%rbp), %r12
cmpq	$0, %r12
je	.LABEL16
movq	$0, -800(%rbp)
movq	-800(%rbp), %r12
movq	%r12, -808(%rbp)
.LABEL13:
movq	-808(%rbp), %r12
movq	%r12, -816(%rbp)
movq	$3, -824(%rbp)
movq	-816(%rbp), %r12
movq	-824(%rbp), %r13
cmpq	%r12, %r13
setg	%al
movzbq	%al, %r12
movq	%r12, -832(%rbp)
movq	-832(%rbp), %r12
cmpq	$0, %r12
je	.LABEL14
movq	-616(%rbp), %r12
movq	%r12, -864(%rbp)
movq	-864(%rbp), %r12
movq	$8, %r13
imulq	%r12, %r13
movq	%r13, -872(%rbp)
movq	-680(%rbp), %r12
movq	%r12, -880(%rbp)
movq	-880(%rbp), %r12
movq	$8, %r13
imulq	%r12, %r13
movq	%r13, -896(%rbp)
movq	-880(%rbp), %r12
movq	%r12, -888(%rbp)
movq	-896(%rbp), %r13
addq	%r13, -888(%rbp)
movq	-744(%rbp), %r12
movq	%r12, -904(%rbp)
movq	-904(%rbp), %r12
movq	$8, %r13
imulq	%r12, %r13
movq	%r13, -920(%rbp)
movq	-904(%rbp), %r12
movq	%r12, -912(%rbp)
movq	-920(%rbp), %r13
addq	%r13, -912(%rbp)
movq	-808(%rbp), %r12
movq	%r12, -928(%rbp)
movq	-928(%rbp), %r12
movq	$8, %r13
imulq	%r12, %r13
movq	%r13, -944(%rbp)
movq	-928(%rbp), %r12
movq	%r12, -936(%rbp)
movq	-944(%rbp), %r13
addq	%r13, -936(%rbp)
movq	-616(%rbp), %r12
movq	%r12, -952(%rbp)
movq	-680(%rbp), %r12
movq	%r12, -960(%rbp)
movq	-952(%rbp), %r12
movq	%r12, -968(%rbp)
movq	-960(%rbp), %r13
addq	%r13, -968(%rbp)
movq	-744(%rbp), %r12
movq	%r12, -976(%rbp)
movq	-968(%rbp), %r12
movq	%r12, -984(%rbp)
movq	-976(%rbp), %r13
addq	%r13, -984(%rbp)
movq	-808(%rbp), %r12
movq	%r12, -992(%rbp)
movq	-984(%rbp), %r12
movq	%r12, -1000(%rbp)
movq	-992(%rbp), %r13
addq	%r13, -1000(%rbp)
movq	-1000(%rbp), %r12
movq	-936(%rbp), %r13
addq	$104, %r13
imulq	$-1, %r13
movq	%rbp, %r15
addq	%r13, %rbp
movq	%r12, 0(%rbp)
movq	%r15, %rbp
movq	-616(%rbp), %r12
movq	%r12, -1008(%rbp)
movq	-1008(%rbp), %r12
movq	$8, %r13
imulq	%r12, %r13
movq	%r13, -1016(%rbp)
movq	-680(%rbp), %r12
movq	%r12, -1024(%rbp)
movq	-1024(%rbp), %r12
movq	$8, %r13
imulq	%r12, %r13
movq	%r13, -1040(%rbp)
movq	-1024(%rbp), %r12
movq	%r12, -1032(%rbp)
movq	-1040(%rbp), %r13
addq	%r13, -1032(%rbp)
movq	-744(%rbp), %r12
movq	%r12, -1048(%rbp)
movq	-1048(%rbp), %r12
movq	$8, %r13
imulq	%r12, %r13
movq	%r13, -1064(%rbp)
movq	-1048(%rbp), %r12
movq	%r12, -1056(%rbp)
movq	-1064(%rbp), %r13
addq	%r13, -1056(%rbp)
movq	-808(%rbp), %r12
movq	%r12, -1072(%rbp)
movq	-1072(%rbp), %r12
movq	$8, %r13
imulq	%r12, %r13
movq	%r13, -1088(%rbp)
movq	-1072(%rbp), %r12
movq	%r12, -1080(%rbp)
movq	-1088(%rbp), %r13
addq	%r13, -1080(%rbp)
movq	-1080(%rbp), %r13
addq	$104, %r13
imulq	$-1, %r13
movq	%rbp, %r15
addq	%r13, %rbp
movq	0(%rbp), %r12
movq	%r15, %rbp
movq	%r12, -1096(%rbp)
movq	-1096(%rbp), %r12
movq	%r12, -1104(%rbp)
movq	-1104(%rbp), %rax
movq	%rax, %rsi
leaq	.LC0(%rip), %rax
movq	%rax, %rdi
movq	$0, %rax
call printf@PLT
movq	-808(%rbp), %r12
movq	%r12, -840(%rbp)
movq	$1, -848(%rbp)
movq	-840(%rbp), %r12
movq	%r12, -856(%rbp)
movq	-848(%rbp), %r13
addq	%r13, -856(%rbp)
movq	-856(%rbp), %r12
movq	%r12, -808(%rbp)
jmp	.LABEL13
.LABEL14:
movq	-744(%rbp), %r12
movq	%r12, -776(%rbp)
movq	$1, -784(%rbp)
movq	-776(%rbp), %r12
movq	%r12, -792(%rbp)
movq	-784(%rbp), %r13
addq	%r13, -792(%rbp)
movq	-792(%rbp), %r12
movq	%r12, -744(%rbp)
jmp	.LABEL15
.LABEL16:
movq	-680(%rbp), %r12
movq	%r12, -712(%rbp)
movq	$1, -720(%rbp)
movq	-712(%rbp), %r12
movq	%r12, -728(%rbp)
movq	-720(%rbp), %r13
addq	%r13, -728(%rbp)
movq	-728(%rbp), %r12
movq	%r12, -680(%rbp)
jmp	.LABEL17
.LABEL18:
movq	-616(%rbp), %r12
movq	%r12, -648(%rbp)
movq	$1, -656(%rbp)
movq	-648(%rbp), %r12
movq	%r12, -664(%rbp)
movq	-656(%rbp), %r13
addq	%r13, -664(%rbp)
movq	-664(%rbp), %r12
movq	%r12, -616(%rbp)
jmp	.LABEL19
.LABEL20:
popq  %rdi  
leave  
ret  
