
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$1,-4(%14)
		MOV 	$5,-8(%14)
@switch_begin_0:
		JMP	@switch_check_0
@case_0_0:
@if0:
		CMPS 	-4(%14),$1
		JNE 	@false0
@true0:
		JMP	@switch_end_0
		JMP 	@exit0
@false0:
@exit0:
		MOV 	$99,-8(%14)
@default_0:
		MOV 	$88,-8(%14)
		JMP	@switch_end_0
@switch_check_0:
		CMPS	-4(%14),$1
		JEQ	@case_0_0
		JMP	@default_0
@switch_end_0:
		MOV 	-8(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET