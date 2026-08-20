
fun1:
		PUSH	%14
		MOV 	%15,%14
@fun1_body:
		ADDS	8(%14),$1,%0
		MOV 	%0,%13
		JMP 	@fun1_exit
@fun1_exit:
		MOV 	%14,%15
		POP 	%14
		RET
fun2:
		PUSH	%14
		MOV 	%15,%14
@fun2_body:
		ADDU	12(%14),12(%14),%0
		MOV 	%0,%13
		JMP 	@fun2_exit
@fun2_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$3,-4(%14)
		MOV 	$2,-8(%14)
			PUSH	%0
			PUSH	-4(%14)
			CALL	fun1
			ADDS	%15,$4,%15
		MOV 	%13,%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET