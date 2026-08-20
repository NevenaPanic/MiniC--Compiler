
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$15,-4(%14)
		MOV 	$12,-8(%14)
		CMPS 	-4(%14),-8(%14)
		JNE 	@con_false0
@con_true0:
		MOV 	-4(%14),%0
		JMP 	@con_exit0
@con_false0:
		MOV 	$0,%0
@con_exit0:
		MOV 	%0,-4(%14)
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET