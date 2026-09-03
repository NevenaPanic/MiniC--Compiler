
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$11,-4(%14)
		MOV 	$0,-8(%14)
@switch_begin_0:
		JMP	@switch_check_0
@case_0_0:
		MOV 	$1,-8(%14)
		JMP	@switch_end_0
@case_0_1:
		MOV 	$2,-8(%14)
		JMP	@switch_end_0
@case_0_2:
		MOV 	$3,-8(%14)
		JMP	@switch_end_0
@case_0_3:
		MOV 	$4,-8(%14)
		JMP	@switch_end_0
@case_0_4:
		MOV 	$5,-8(%14)
		JMP	@switch_end_0
@case_0_5:
		MOV 	$6,-8(%14)
		JMP	@switch_end_0
@case_0_6:
		MOV 	$7,-8(%14)
		JMP	@switch_end_0
@case_0_7:
		MOV 	$8,-8(%14)
		JMP	@switch_end_0
@case_0_8:
		MOV 	$9,-8(%14)
		JMP	@switch_end_0
@case_0_9:
		MOV 	$10,-8(%14)
		JMP	@switch_end_0
@case_0_10:
		MOV 	$11,-8(%14)
		JMP	@switch_end_0
@default_0:
		MOV 	$99,-8(%14)
		JMP	@switch_end_0
@switch_check_0:
		CMPS	-4(%14),$1
		JEQ	@case_0_0
		CMPS	-4(%14),$2
		JEQ	@case_0_1
		CMPS	-4(%14),$3
		JEQ	@case_0_2
		CMPS	-4(%14),$4
		JEQ	@case_0_3
		CMPS	-4(%14),$5
		JEQ	@case_0_4
		CMPS	-4(%14),$6
		JEQ	@case_0_5
		CMPS	-4(%14),$7
		JEQ	@case_0_6
		CMPS	-4(%14),$8
		JEQ	@case_0_7
		CMPS	-4(%14),$9
		JEQ	@case_0_8
		CMPS	-4(%14),$10
		JEQ	@case_0_9
		CMPS	-4(%14),$11
		JEQ	@case_0_10
		JMP	@default_0
@switch_end_0:
		MOV 	-8(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET