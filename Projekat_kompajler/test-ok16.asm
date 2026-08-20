
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$20,%15
@main_body:
		MOV 	$-5,-4(%14)
		MOV 	$3,-8(%14)
		MOV 	$0,-12(%14)
		MOV 	-4(%14),%0
		MOV 	-12(%14),%1
		CMPS	%1, $0
		JEQ	@pow_is_zero0
		SUBS	%1, $1, %1
@pow_loop0:
		CMPS	%1, $0
		JEQ	@pow_exit0
		MULS	-4(%14),%0,%0
		SUBS	%1, $1, %1
		JMP	@pow_loop0
@pow_is_zero0:
		MOV	$1,%0
@pow_exit0:
		MOV 	%0,-16(%14)
		MOV 	-8(%14),%0
		MOV 	$0,%1
		CMPS	%1, $0
		JEQ	@pow_is_zero1
		SUBS	%1, $1, %1
@pow_loop1:
		CMPS	%1, $0
		JEQ	@pow_exit1
		MULS	-8(%14),%0,%0
		SUBS	%1, $1, %1
		JMP	@pow_loop1
@pow_is_zero1:
		MOV	$1,%0
@pow_exit1:
		MOV 	%0,-20(%14)
		ADDS	-16(%14),-20(%14),%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET