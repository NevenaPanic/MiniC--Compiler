
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$-5,-4(%14)
		MOV 	$3,-8(%14)
		MOV 	-4(%14),%0
		MOV 	-8(%14),%1
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
		MOV 	%0,-4(%14)
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET