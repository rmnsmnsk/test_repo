	.file	"sort.c"
	.text
	.p2align 4
	.globl	sort
	.type	sort, @function
sort:
	endbr64
	pushq	%r13
	pushq	%r12
	pushq	%rbp
	pushq	%rbx
	testl	%esi, %esi
	jle	.L10
	xorl	%ebp, %ebp
	leaq	4(%rdi), %r10
	movq	%rdi, %r11
	xorl	%r13d, %r13d
	leal	1(%rbp), %ebx
	movl	-4(%r10), %r12d
	cmpl	%ebx, %esi
	jle	.L3
	.p2align 4,,10
	.p2align 3
.L19:
	movq	%r10, %rax
	movl	%r12d, %edi
	movl	%ebx, %edx
	movl	%ebp, %r9d
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L18:
	movslq	%r9d, %rcx
	addl	$1, %edx
	addq	$4, %rax
	leaq	(%r11,%rcx,4), %r8
	cmpl	%edx, %esi
	je	.L17
.L5:
	movl	(%rax), %ecx
	movq	%rax, %r8
	cmpl	%edi, %ecx
	jge	.L18
	movl	%edx, %r9d
	addl	$1, %edx
	movl	%ecx, %edi
	addq	$4, %rax
	cmpl	%edx, %esi
	jne	.L5
.L17:
	movl	%r12d, (%r8)
	movl	%edi, -4(%r10)
	cmpl	%ebp, %r9d
	je	.L15
	addl	$2, %r13d
.L15:
	movl	%ebx, %ebp
	addq	$4, %r10
	movl	-4(%r10), %r12d
	leal	1(%rbp), %ebx
	cmpl	%ebx, %esi
	jg	.L19
.L3:
	jne	.L15
	popq	%rbx
	movl	%r13d, %eax
	popq	%rbp
	popq	%r12
	popq	%r13
	ret
.L10:
	xorl	%r13d, %r13d
	popq	%rbx
	popq	%rbp
	movl	%r13d, %eax
	popq	%r12
	popq	%r13
	ret
	.size	sort, .-sort
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
