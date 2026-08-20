
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$9,-4(%14)
		MOV 	$2,-8(%14)
@switch_1:

		JMP @switch_check_1

@case_1_0:
		MULS	-4(%14),$2,%0
		MOV 	%0,-4(%14)
		JMP @switch_end_1

@case_1_1:
		ADDS	-4(%14),$9,%0
		MOV 	%0,-4(%14)
		JMP @switch_end_1

@case_1_2:
		MULS	-4(%14),$7,%0
		ADDS	%0,$7,%0
		MOV 	%0,-4(%14)
		JMP @switch_end_1

@default_1:

		MOV 	$24,-4(%14)
		JMP @switch_end_1

@switch_check_1:

		CMPS 	-4(%14),$2
		JEQ @case_1_0
		CMPS 	-4(%14),$9
		JEQ @case_1_1
		CMPS 	-4(%14),$7
		JEQ @case_1_2
		JMP @default_1
@switch_end_1:

		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET