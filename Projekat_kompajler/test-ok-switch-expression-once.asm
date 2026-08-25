
counter:
		WORD	1
nextvalue:
		PUSH	%14
		MOV 	%15,%14
@nextvalue_body:
		ADDS	counter,$1,%0
		MOV 	%0,counter
		MOV 	counter,%13
		JMP 	@nextvalue_exit
@nextvalue_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@main_body:
		MOV 	$0,counter
		MOV 	$0,-4(%14)
			CALL	nextvalue
		MOV 	%13,%0
@switch_begin_1:
		JMP	@switch_check_1
@case_1_0:
		MOV 	counter,-4(%14)
		JMP	@switch_end_1
@default_1:
		MOV 	$99,-4(%14)
		JMP	@switch_end_1
@switch_check_1:
		CMPS	%0,$1
		JEQ	@case_1_0
		JMP	@default_1
@switch_end_1:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET