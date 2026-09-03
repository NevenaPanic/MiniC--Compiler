
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$12,%15
@main_body:
		MOV 	$9,-4(%14)
		MOV 	$2,-8(%14)
		MOV 	-4(%14),-12(%14)
@switch_begin_0:
		JMP	@switch_check_0
@case_0_0:
		MULS	-4(%14),$2,%0
		MOV 	%0,-4(%14)
		JMP	@switch_end_0
@case_0_1:
		ADDS	-4(%14),$9,%0
		MOV 	%0,-4(%14)
		JMP	@switch_end_0
@case_0_2:
		MULS	-4(%14),$7,%0
		ADDS	%0,$7,%0
		MOV 	%0,-4(%14)
		JMP	@switch_end_0
@default_0:
		MOV 	$24,-4(%14)
		JMP	@switch_end_0
@switch_check_0:
		CMPS	-12(%14),$2
		JEQ	@case_0_0
		CMPS	-12(%14),$9
		JEQ	@case_0_1
		CMPS	-12(%14),$7
		JEQ	@case_0_2
		JMP	@default_0
@switch_end_0:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET