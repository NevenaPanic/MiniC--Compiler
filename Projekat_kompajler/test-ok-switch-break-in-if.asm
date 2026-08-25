
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$1,-4(%14)
		MOV 	$5,-8(%14)
@switch_begin_1:
		JMP	@switch_check_1
@case_1_0:
@if0:
		CMPS 	-4(%14),$1
		JNE 	@false0
@true0:
		JMP	@switch_end_1
		JMP 	@exit0
@false0:
@exit0:
		MOV 	$99,-8(%14)
@default_1:
		MOV 	$88,-8(%14)
		JMP	@switch_end_1
@switch_check_1:
		CMPS	-4(%14),$1
		JEQ	@case_1_0
		JMP	@default_1
@switch_end_1:
		MOV 	-8(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET