
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$9,-8(%14)
		MOV 	$5,-4(%14)
		CMPS 	-4(%14),$1
		JEQ	@first0
		CMPS 	-4(%14),$3
		JEQ	@second0
		CMPS 	-4(%14),$5
		JEQ	@third0
		JMP	@otherwise0
@first0:
		ADDS	-4(%14),$1,%0
		MOV 	%0,-4(%14)
		JMP	@end_branch0
@second0:
		ADDS	-4(%14),$3,%0
		MOV 	%0,-4(%14)
		JMP	@end_branch0
@third0:
		ADDS	-4(%14),$5,%0
		MOV 	%0,-4(%14)
		JMP	@end_branch0
@otherwise0:
		SUBS	-4(%14),$3,%0
		MOV 	%0,-4(%14)
@end_branch0:
		CMPU 	-8(%14),$1
		JEQ	@first1
		CMPU 	-8(%14),$9
		JEQ	@second1
		CMPU 	-8(%14),$5
		JEQ	@third1
		JMP	@otherwise1
@first1:
		ADDU	-8(%14),$1,%0
		MOV 	%0,-8(%14)
		JMP	@end_branch1
@second1:
		ADDU	-8(%14),$3,%0
		MOV 	%0,-8(%14)
		JMP	@end_branch1
@third1:
		ADDU	-8(%14),$5,%0
		MOV 	%0,-8(%14)
		JMP	@end_branch1
@otherwise1:
		SUBU	-8(%14),$3,%0
		MOV 	%0,-8(%14)
@end_branch1:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET