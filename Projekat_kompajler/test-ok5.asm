
inc:
		PUSH	%14
		MOV 	%15,%14
@inc_body:
		ADDS	8(%14),$1,8(%14)
		MOV 	8(%14),%13
		JMP 	@inc_exit
@inc_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$24,%15
@main_body:
		MOV 	$0,-4(%14)
		MOV 	$0,-8(%14)
		MOV 	$1,-16(%14)
		MOV 	$2,-20(%14)
		ADDS	-4(%14),$1,-4(%14)
		MOV 	-4(%14),%0
		ADDS	-4(%14), $1, -4(%14)
		MOV 	%0,-8(%14)
		MOV 	-8(%14),%0
		ADDS	-8(%14), $1, -8(%14)
		ADDS	-4(%14),%0,%0
		MOV 	%0,-12(%14)
		ADDU	-16(%14),$1,-16(%14)
		ADDU	-20(%14),$1,-20(%14)
		MOV 	-16(%14),%0
		ADDU	-16(%14), $1, -16(%14)
		MOV 	-20(%14),%1
		ADDU	-20(%14), $1, -20(%14)
		ADDU	%0,%1,%0
		MOV 	%0,-24(%14)
		ADDS	-4(%14),-8(%14),%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET