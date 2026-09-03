
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$12,%15
@main_body:
		MOV 	$1,-4(%14)
		MOV 	$2,-8(%14)
		MOV 	$0,-12(%14)
@switch_begin_0:
		JMP	@switch_check_0
@case_0_0:
@switch_begin_1:
		JMP	@switch_check_1
@case_1_0:
		MOV 	$7,-12(%14)
		JMP	@switch_end_1
@default_1:
		MOV 	$90,-12(%14)
		JMP	@switch_end_1
@switch_check_1:
		CMPS	-8(%14),$2
		JEQ	@case_1_0
		JMP	@default_1
@switch_end_1:
		ADDS	-12(%14),$10,%0
		MOV 	%0,-12(%14)
		JMP	@switch_end_0
@default_0:
		MOV 	$99,-12(%14)
		JMP	@switch_end_0
@switch_check_0:
		CMPS	-4(%14),$1
		JEQ	@case_0_0
		JMP	@default_0
@switch_end_0:
		MOV 	-12(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET