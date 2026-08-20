
f:
		PUSH	%14
		MOV 	%15,%14
@f_body:
		ADDS	8(%14),$1,8(%14)
@f_exit:
		MOV 	%14,%15
		POP 	%14
		RET
f1:
		PUSH	%14
		MOV 	%15,%14
@f1_body:
		ADDS	8(%14),12(%14),%0
		MOV 	%0,8(%14)
@f1_exit:
		MOV 	%14,%15
		POP 	%14
		RET
f2:
		PUSH	%14
		MOV 	%15,%14
@f2_body:
		MOV 	8(%14),%13
		JMP 	@f2_exit
@f2_exit:
		MOV 	%14,%15
		POP 	%14
		RET
f5:
		PUSH	%14
		MOV 	%15,%14
@f5_body:
		MOV 	8(%14),%13
		JMP 	@f5_exit
@f5_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$20,%15
@main_body:
		MOV 	$20,-4(%14)
		MOV 	$3,-8(%14)
			PUSH	%0
			PUSH	$5
			CALL	f
			ADDS	%15,$4,%15
			PUSH	%0
			PUSH	-4(%14)
			CALL	f
			ADDS	%15,$4,%15
			PUSH	%0
			PUSH	$5
			PUSH	$1
			CALL	f1
			ADDS	%15,$8,%15
			PUSH	%0
			PUSH	-8(%14)
			PUSH	-4(%14)
			CALL	f1
			ADDS	%15,$8,%15
			PUSH	-8(%14)
			PUSH	$2
			CALL	f2
			ADDS	%15,$4,%15
		MOV 	%13,%0
		MOV 	%0,-4(%14)
			PUSH	-8(%14)
			PUSH	-4(%14)
			CALL	f2
			ADDS	%15,$4,%15
		MOV 	%13,%0
		MOV 	%0,-8(%14)
		MOV 	-8(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET