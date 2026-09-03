
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$8,-4(%14)
		MOV 	$7,-8(%14)
@switch_begin_0:
		JMP	@switch_check_0
@case_0_0:
		MOV 	$10,-8(%14)
		JMP	@switch_end_0
@case_0_1:
		MOV 	$20,-8(%14)
		JMP	@switch_end_0
@switch_check_0:
		CMPS	-4(%14),$1
		JEQ	@case_0_0
		CMPS	-4(%14),$2
		JEQ	@case_0_1
@switch_end_0:
		MOV 	-8(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET