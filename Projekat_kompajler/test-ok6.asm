
fun:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@fun_body:
		ADDS	8(%14),8(%14),%0
		MOV 	%0,-4(%14)
@fun_exit:
		MOV 	%14,%15
		POP 	%14
		RET
fun2:
		PUSH	%14
		MOV 	%15,%14
@fun2_body:
		ADDU	8(%14),8(%14),%0
		MOV 	%0,8(%14)
@fun2_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$12,%15
@main_body:
		MOV 	$9,-12(%14)
		MOV 	$4,-4(%14)
		MOV 	$9,-8(%14)
			PUSH	%0
			PUSH	-8(%14)
			CALL	fun
			ADDS	%15,$4,%15
			PUSH	%0
			PUSH	$2
			CALL	fun
			ADDS	%15,$4,%15
			PUSH	%0
			PUSH	-12(%14)
			CALL	fun2
			ADDS	%15,$4,%15
			PUSH	%0
			PUSH	$8
			CALL	fun2
			ADDS	%15,$4,%15
		ADDS	-8(%14),-4(%14),%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET