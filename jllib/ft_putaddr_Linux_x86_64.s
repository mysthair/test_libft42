	.file	"ft_putaddr.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	ft_putaddr
	.type	ft_putaddr, @function
ft_putaddr:
.LFB24:
	.cfi_startproc
	movl	$1, %esi
	jmp	ft_putaddr_fd
	.cfi_endproc
.LFE24:
	.size	ft_putaddr, .-ft_putaddr
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.ident	"GCC: (Ubuntu 5.3.1-14ubuntu2) 5.3.1 20160413"
	.section	.note.GNU-stack,"",@progbits
