
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$24,%15
@main_body:
		MOV 	$1,-4(%14)
		MOV 	$-3,-8(%14)
		MOV 	$98,-12(%14)
		MOV 	$2,-16(%14)
		MOV 	$3,-20(%14)
		MOV 	$87,-24(%14)
		MOV 	-12(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET