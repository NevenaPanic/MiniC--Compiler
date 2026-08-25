
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$4,-4(%14)
		MOV 	$0,-8(%14)
		ADDS	-4(%14),$1,%0
@switch_begin_1:
		JMP	@switch_check_1
@case_1_0:
		MOV 	$11,-8(%14)
		JMP	@switch_end_1
@default_1:
		MOV 	$99,-8(%14)
		JMP	@switch_end_1
@switch_check_1:
		CMPS	%0,$5
		JEQ	@case_1_0
		JMP	@default_1
@switch_end_1:
		MOV 	-8(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET