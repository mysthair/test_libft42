	.file	"ft_exit.c"
	.text
	.p2align 4,,15
	.globl	ft_exit
	.type	ft_exit, @function
ft_exit:
.LFB14:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	exit@PLT
	.cfi_endproc
.LFE14:
	.size	ft_exit, .-ft_exit
	.ident	"GCC: (Debian 6.3.0-18) 6.3.0 20170516"
	.section	.note.GNU-stack,"",@progbits
