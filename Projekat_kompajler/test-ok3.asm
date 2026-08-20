
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$12,%15
@main_body:
		MOV 	$5,-4(%14)
		MOV 	$3,-8(%14)
		MOV 	$7,-12(%14)
		MOV 	-4(%14),%0
		ADDS	-4(%14), $1, -4(%14)
		ADDS	-4(%14),%0,%0
		SUBS	%0,-8(%14),%0
		MOV 	%0,-4(%14)
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET