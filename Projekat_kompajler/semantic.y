%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"
  
  #define MAX_SIZE 50

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int gvar_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int var_type = -1;
  int int_par_num = 0;
  int uint_par_num = 0;
  
  int num = 0;
  int param_num = 0;
  
  // help struct for 10-th assignement
  struct paramData{
  	unsigned fun_id; // key to search struct
  	unsigned fun_types[MAX_SIZE]; // za sad sam  ga ogranicila na 50 parametara po funkciji, dok ne smislim nesto pametnije
	unsigned count_param;
  };
  
  struct paramData Fun_params[100]; // 100 functions per program
  
  unsigned num_of_args = 0;
  unsigned type_of_arg = 0;
  int ArgsArray[50]; // stavila sam da f-ja moze da ima 50 argumenata

  bool return_flag = FALSE;
  
  int lab_num = -1;
  int con_num = -1;
  int for_num = -1;
  int for_num_u = 0; // num of multipl fors 
  int max_for_num = -1;
  int var_num_f = 0;
  
  FILE *output;
  
  int branch_num = 0;
  int pow_num = 0;
  
%}


%union {
  int i;
  char *s;
}

%token <i> _TYPE
%token _IF
%token _ELSE
%token _RETURN
%token <s> _ID
%token <s> _INT_NUMBER
%token <s> _UINT_NUMBER
%token _LPAREN
%token _RPAREN
%token _LBRACKET
%token _RBRACKET
%token _ASSIGN
%token _SEMICOLON
%token <i> _AROP
%token _ADD
%token _SUB
%token _MUL
%token _DIV
%token <i> _RELOP
%token _COMMA
%token _INC
%token _FOR
%token _Q_MARK
%token _TWO_DOTS

%token _BRANCH
%token _FIRST
%token _SECOND
%token _THIRD
%token _OTHERWISE
%token _END_BRANCH
%token _POW

%type <i> num_exp exp literal function_call argument arguments rel_exp increment void_function_call if_part conditional_exp con_exp

%nonassoc ONLY_IF
%nonassoc _ELSE

%left _ADD _SUB
%left _MUL _DIV
%left PRIORITY
%right _POW


%%

program
  : global_variable_list function_list
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
  ;
  
global_variable_list
	: /* empty */ 
	| global_variable_list global_variable
	;
	
global_variable
	: _TYPE _ID _SEMICOLON
	  {
		if(lookup_symbol($2, GVAR) == NO_INDEX)
		{
           insert_symbol($2, GVAR, $1, NO_ATR, NO_ATR, NO_ATR, NO_ATR); 
           code("\n%s:\n\t\tWORD\t1", $2);
        }
        else 
           err("redefinition of global '%s'", $2);
	  }
	;

function_list
  : function
  | function_list function
  ;

function
  : _TYPE _ID
      {
        fun_idx = lookup_symbol($2, FUN);
        if(fun_idx == NO_INDEX)
        {
          fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR, NO_ATR, NO_ATR);
          Fun_params[num].fun_id = fun_idx;  //  i need this to find it again
        }
        else 
          err("redefinition of function '%s'", $2);
          
        code("\n%s:", $2);
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
    _LPAREN parameter _RPAREN body
      {
      	if(get_type(fun_idx) != VOID && return_flag == FALSE)
      		warn("Function %s should return value!", get_name(fun_idx));
      	
      	// print_symtab();	
      	Fun_params[num].count_param = param_num;
      		
        clear_symbols(fun_idx + 1);
        var_num = 0;
        num++;
        param_num = 0;
        return_flag = FALSE;
        int_par_num = 0;
        uint_par_num = 0;
        
        code("\n@%s_exit:", $2);
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
  ;

parameter
  : /* empty */
      {
      	 set_atr1(fun_idx, 0);
      	 set_atr3(fun_idx, 0);
      }
  | parameters
  ;
  
parameters
  : _TYPE _ID
      {
      	if ($1 == VOID)
      		err("Parametar can't be void type, redefine %s!", $2);
    	
    	if(lookup_symbol($2, PAR) == NO_INDEX)
    	{
      		if( $1 == INT ) // This is for one par type int
      		{
      			Fun_params[num].fun_types[param_num] = $1;
      			++int_par_num;
				insert_symbol($2, PAR, $1, int_par_num + uint_par_num, NO_ATR, NO_ATR, NO_ATR);
				set_atr1(fun_idx, int_par_num);
				set_atr2(fun_idx, $1);

			}
		    else if ( $1 == UINT ) // this is for one par type unsigned
		    {
		    	Fun_params[num].fun_types[param_num] = $1;
		    	++uint_par_num;
		    	insert_symbol($2, PAR, $1, int_par_num + uint_par_num, NO_ATR, NO_ATR, NO_ATR);
				set_atr3(fun_idx, uint_par_num);
				set_atr4(fun_idx, $1);
		    }
		    
		    param_num++;
        }
        else
        	err("Parameter already exist in function %s, change parametar %s!", get_name(fun_idx), $2);
      }
  | parameters _COMMA _TYPE _ID		// ovo moras da popravis, jer mozes da prepoznas parametar kao empty pa zrez pa type id, to ne sme, to je greska
  		{
		  	if ($3 == VOID)
		  		err("Parametar can't be void type, redefine %s!", $4);
		  	if (lookup_symbol($4, PAR) == NO_INDEX)
		  	{
			  	if ( $3 == INT)
			  	{	
			  		Fun_params[num].fun_types[param_num] = $3;
			  		++int_par_num;
					insert_symbol($4, PAR, $3, int_par_num + uint_par_num, NO_ATR, NO_ATR, NO_ATR);
					set_atr1(fun_idx, int_par_num);
					set_atr2(fun_idx, INT);
				}
				else if ( $3 == UINT )
				{	
					Fun_params[num].fun_types[param_num] = $3;
					++uint_par_num;
					insert_symbol($4, PAR, $3, int_par_num + uint_par_num, NO_ATR, NO_ATR, NO_ATR);
					set_atr3(fun_idx, uint_par_num);
					set_atr4(fun_idx, UINT);
				}
				
				param_num++;
			}
			else
				err("Parametar %s already exist in function %s!", $4, get_name(fun_idx));

      }
  ;

body
  : _LBRACKET variable_list
  	  {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
      }
       statement_list _RBRACKET
  ;

variable_list
  : /* empty */
  | variable_list variable
  ;
  
variable
	: _TYPE { var_type = $1; } vars _SEMICOLON;  
vars 
	: _ID
		{
        if(lookup_symbol($1, VAR|PAR) == NO_INDEX && var_type != VOID)
           insert_symbol($1, VAR, var_type, ++var_num, NO_ATR, NO_ATR, NO_ATR);
        else 
      	{
      		if(var_type == VOID)
      			err("Can't be void type: '%s'", $1);
      		else
      			err("Redefinition of '%s'", $1);
      	}
      }
	| vars _COMMA _ID
		{
        if(lookup_symbol($3, VAR|PAR) == NO_INDEX && var_type != VOID)
           insert_symbol($3, VAR, var_type, ++var_num, NO_ATR, NO_ATR, NO_ATR);
        else 
         {
      		if(var_type == VOID)
      			err("Can't be void type: '%s'", $3);
      		else
      			err("Redefinition of '%s'", $3);
      	}
      }
	;

statement_list
  : /* empty */
  | statement_list statement
  ;

statement
  : compound_statement
  | assignment_statement
  | if_statement
  | return_statement
  | increment_statement
  | for_statement
  | branch_statement
  | void_function_call
  ;

compound_statement
  : _LBRACKET statement_list _RBRACKET
  ;

assignment_statement
  : _ID _ASSIGN num_exp _SEMICOLON
      {
        int idx = lookup_symbol($1, VAR|PAR|GVAR);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", $1);
        else
          if(get_type(idx) != get_type($3))
            err("incompatible types in assignment");
        
        gen_mov($3, idx);
      }
  ;
  
for_statement
  : _FOR _LPAREN _TYPE _ID _SEMICOLON
  	{
  		if(lookup_symbol($4, VAR|PAR|GVAR) == NO_INDEX) // dodala sam gvar, brojac mora biti jedinstven za svaku for petlju
  			{ 
  				insert_symbol($4, VAR, $3, ++var_num, NO_ATR, NO_ATR, NO_ATR);
  				/*for_index = lookup_symbol($4, VAR);
  				for_reg = take_reg();
  				code("\n\t\tMOV\t");
  				code("$1");
  				code(",");
  				gen_sym_name(for_reg);
  				*/
  				var_num_f = var_num;
  				++for_num;
  				++for_num_u;
  				if(for_num > max_for_num)
  					max_for_num = for_num;
  				// stavljam iterator petlje na stack
  				code("\n\t\tSUBS\t%%15,$4,%%15");
  				code("\n\t\tMOV $1, %d(%%14)", -var_num_f*4); 
  				code("\n@for_begins%d:", for_num );
  			}
  		else 
  			err("Already exists '%s' can't use it for iteration through for loop, change it!", $4);
  	}
    rel_exp
    	{ code("\n\t\t%s\t@for_end%d", opp_jumps[$7], for_num);  } // uslov nije ispunjen, idi na kraj, uskov dobar, propadam dalje
     _SEMICOLON _ID _INC
      _RPAREN statement  
      {
      	
      	if(get_type($3) == INT)
			code("\n\t\tADDS\t");	
		else
			code("\n\t\tADDU\t");	
			
			code("%d(%%14)", -var_num_f*4); 
			code(",");
			code("$1");
			code(",");
			code("%d(%%14)", -var_num_f*4); 
		
		code("\n\t\tJMP\t\t@for_begins%d", for_num);
		code("\n@for_end%d:", for_num);
		code("\n\t\tADDS\t%%15,$4,%%15");
	
		// code za numerisanje labela
		if(--for_num_u)
			--for_num;
		else
			for_num = max_for_num;
		--var_num_f;
		
      } 
  ;

branch_statement
  : _BRANCH _LPAREN _ID _SEMICOLON literal _COMMA literal _COMMA literal _RPAREN
  	{
  		int id_index = lookup_symbol($3, VAR|PAR|GVAR);
  		if( id_index == NO_INDEX)
  			err("Variable '%s' have to be declared beforhand, to bu used in baranch statement! ", $3);
  			
  		if(get_type(id_index) != get_type($5) || get_type(id_index) != get_type($7) || get_type(id_index) != get_type($9))
  			err("Incompatible types in branch statement, all numbers have to be the same type as %s !" , $3);
  		
  		// generisanje koda za branch

  		gen_cmp(id_index, $5);
  		code("\n\t\tJEQ\t@first%d", branch_num);
  		

  		gen_cmp(id_index, $7);
  		code("\n\t\tJEQ\t@second%d", branch_num);
  		

  		gen_cmp(id_index, $9);
  		code("\n\t\tJEQ\t@third%d", branch_num);
  		code("\n\t\tJMP\t@otherwise%d", branch_num);  
  		
  	}
  	
  	_FIRST { code("\n@first%d:", branch_num); }
  		 statement { code("\n\t\tJMP\t@end_branch%d", branch_num);}
  	_SECOND { code("\n@second%d:", branch_num); } 
  		statement  { code("\n\t\tJMP\t@end_branch%d", branch_num);}
  	_THIRD { code("\n@third%d:", branch_num); }
  		 statement { code("\n\t\tJMP\t@end_branch%d", branch_num);}
  	_OTHERWISE { code("\n@otherwise%d:", branch_num); } 
  		statement
  	_END_BRANCH { code("\n@end_branch%d:", branch_num); 
  	
  	branch_num++;
  	}
  ;


conditional_exp
	:	_LPAREN rel_exp _RPAREN _Q_MARK con_exp _TWO_DOTS con_exp
		{	
			if(get_type($5) != get_type($7))
				err("\nOperands are different types in conditional expression!");
			
			//  cmp  je izgenerisao rel_exp
			++con_num;
			code("\n\t\t%s\t@con_false%d", opp_jumps[$2], con_num); 
			code("\n@con_true%d:", con_num);
			
			int reg = take_reg();

            gen_mov($5, reg);
            code("\n\t\tJMP \t@con_exit%d", con_num);

            code("\n@con_false%d:", con_num);
            gen_mov($7 , reg);

            $$ = reg;
            code("\n@con_exit%d:", con_num);
		}
	;

con_exp
	: literal
	| _ID
	 {
		int index = lookup_symbol($1, VAR|PAR|GVAR);
		if(index == NO_INDEX)
			err("\nId %s is not declared!", get_name(index));
		$$ = index;
	 }
	;

num_exp
  : exp
  	{ $$ = $1; }
  ;
  
exp
  : literal
  | _ID
	  {
	    $$ = lookup_symbol($1, VAR|PAR|GVAR);
	    if($$ == NO_INDEX)
	    	err("[%s] undeclared", $1);
	  }
  | function_call
      {
      	$$ = take_reg();
      	gen_mov(FUN_REG, $$);
      }
  | _LPAREN num_exp _RPAREN
   	  { $$ = $2; }
  | increment
  	  { 
  	  	int t1 = get_type($1);
  	  	$$ = take_reg();
  	  	set_type($$, t1);
  	  	gen_mov($1, $$);
  	  	if(t1 == INT)
			code("\n\t\tADDS\t");
		else
			code("\n\t\tADDU\t");
		gen_sym_name($1);
		code(", $1, ");
		gen_sym_name($1);
		free_if_reg($1);
  	  }
  | conditional_exp
  	  { $$ = $1; }
  | exp _ADD exp
      {		
        if(get_type($1) != get_type($3))
          err("Invalid operands: arithmetic operation!");
        int t1 = get_type($1);  
        if(get_type($1) == INT)
			code("\n\t\tADDS\t");
		else
			code("\n\t\tADDU\t");
        gen_sym_name($1);
        code(",");
        gen_sym_name($3);
        code(",");
        free_if_reg($3);
        free_if_reg($1);
        $$ = take_reg();
        gen_sym_name($$);
        set_type($$, t1);
      }
  | exp _SUB exp
      {		
        if(get_type($1) != get_type($3))
          err("Invalid operands: arithmetic operation!");
        int t1 = get_type($1);  
        if(get_type($1) == INT)
			code("\n\t\tSUBS\t");
		else
			code("\n\t\tSUBU\t");
        gen_sym_name($1);
        code(",");
        gen_sym_name($3);
        code(",");
        free_if_reg($3);
        free_if_reg($1);
        $$ = take_reg();
        gen_sym_name($$);
        set_type($$, t1);
      }
  | exp _MUL exp
      {		
        if(get_type($1) != get_type($3))
          err("Invalid operands: arithmetic operation!");
        int t1 = get_type($1);  
        if(get_type($1) == INT)
			code("\n\t\tMULS\t");
		else
			code("\n\t\tMULU\t");
        gen_sym_name($1);
        code(",");
        gen_sym_name($3);
        code(",");
        free_if_reg($3);
        free_if_reg($1);
        $$ = take_reg();
        gen_sym_name($$);
        set_type($$, t1);
      }
  | exp _DIV exp
      {		
        if(get_type($1) != get_type($3))
          err("Invalid operands: arithmetic operation!");
        int t1 = get_type($1);  
        if(get_type($1) == INT)
			code("\n\t\tDIVS\t");
		else
			code("\n\t\tDIVU\t");
        gen_sym_name($1);
        code(",");
        gen_sym_name($3);
        code(",");
        free_if_reg($3);
        free_if_reg($1);
        $$ = take_reg();
        gen_sym_name($$);
        set_type($$, t1);
      }
  | _SUB exp %prec PRIORITY
  	  { 
  	  	int t1 = get_type($2);  
        int pom_reg = take_reg();
        set_type(pom_reg, t1);
        if(t1 == INT)
        	code("\n\t\tSUBS\t");
        else
        	code("\n\t\tSUBU\t");
        gen_sym_name(pom_reg);
        code(" , ");
        gen_sym_name(pom_reg);
        code(" , ");
        gen_sym_name(pom_reg); 
        if(t1 == INT)
			code("\n\t\tSUBS\t");
		else
			code("\n\t\tSUBU\t");
        gen_sym_name(pom_reg);
        code(",");
        gen_sym_name($2);
        code(",");
        free_if_reg($2);
        $$ = pom_reg;
        gen_sym_name($$);

  	  }
  | exp _POW exp   //   5^3
      {
         if(get_type($1) != get_type($3))
          err("Invalid operands in power operation");
        int t1 = get_type($1);  
        int idx = take_reg();          // reg_rezultat_stepena;
        int br = take_reg();		  // reg_brojac;
        gen_mov($1, idx);				// reg_rezultat_stepena =  5;
        gen_mov($3, br);				// reg_brojac = 3;
        
        // provera da li je stepen nula
        if(get_type($3) == INT)
            code("\n\t\tCMPS\t");
        else
            code("\n\t\tCMPU\t");
        gen_sym_name(br);
        code(", $0");
        code("\n\t\tJEQ\t@pow_is_zero%d" , pow_num);
        
        // dekrement, umanjujemo brojac za jedan  -> reg_brojac = 2; zato sto mi se u rez vec nalazi vrednost osnove stepena
        if(get_type($3) == INT)
            code("\n\t\tSUBS\t");
        else					
            code("\n\t\tSUBU\t");
        gen_sym_name(br);
        code(", $1, ");
        gen_sym_name(br);
        // pocinje petlja stepena ako je stepen veci od 1
        code("\n@pow_loop%d:" , pow_num);
        // provera da li mi je brojac = 0
        if(get_type($1) == INT)
            code("\n\t\tCMPS\t");
        else
            code("\n\t\tCMPU\t");
        gen_sym_name(br);
        code(", $0");
        // ako jeste, skaci na kraj
        code("\n\t\tJEQ\t@pow_exit%d" , pow_num);
        // ako nije mnozi rezultat osnovom stepena
        if(get_type($1) == INT)
            code("\n\t\tMULS\t");
        else
            code("\n\t\tMULU\t");
        gen_sym_name($1);
        code(",");
        gen_sym_name(idx);
        code(",");
        gen_sym_name(idx);
        // smanjim brojac
        if(get_type($3) == INT)
            code("\n\t\tSUBS\t");
        else
            code("\n\t\tSUBU\t");
        gen_sym_name(br);
        code(", $1, ");
        gen_sym_name(br);
        // bezuslovno skocim na pocetak radi provere brojaca
        code("\n\t\tJMP\t@pow_loop%d" , pow_num);
        // na ovu labelu ce doci samo kad je stepen nula , npr. 5^0 ili a^0 i tada je rezultat uvek 1
        code("\n@pow_is_zero%d:", pow_num);
        code("\n\t\tMOV\t$1,");
        gen_sym_name(idx);
        code("\n@pow_exit%d:", pow_num);
        free_if_reg($3);
        free_if_reg($1);
        free_if_reg(br);
        $$ = idx;
        set_type(idx, t1);
        pow_num++;
      }
  ;
  ;

literal
  : _INT_NUMBER
      { $$ = insert_literal($1, INT); }

  | _UINT_NUMBER
      { $$ = insert_literal($1, UINT); }
  ;

increment_statement
	: increment _SEMICOLON
		{
			if(get_type($1) == INT)
				code("\n\t\tADDS\t");
			else
				code("\n\t\tADDU\t");
			gen_sym_name($1);
			code(",");
			code("$1");
			code(",");
			gen_sym_name($1);
			free_if_reg($1);
		}
	;

increment
	: _ID _INC 
		{
			if(lookup_symbol($1, FUN) != NO_INDEX)
				err("Function can't be incremented '%s'!", $1 );
			else if(lookup_symbol($1, VAR|PAR|GVAR) == NO_INDEX)
				err("Not defined variable or parametar, can't use increment on '%s'! \n", $1 );
			else
				$$ = lookup_symbol($1, VAR|PAR|GVAR);
		}
	;

void_function_call
  : _ID 
      {
        fcall_idx = lookup_symbol($1, FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", $1);
        if(get_type(fcall_idx) != VOID)
        	err("Function '%s' is not void function, can't call it like this!", $1);
      }
    _LPAREN argument _RPAREN _SEMICOLON
      {
        if((get_atr1(fcall_idx) + get_atr3(fcall_idx)) != $4)  // count of all atributs == atributes entered
          err("Wrong number of arguments to function '%s'", get_name(fcall_idx));
        
        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if($4 > 0)
        code("\n\t\t\tADDS\t%%15,$%d,%%15", $4 * 4);
        
        set_type(FUN_REG, get_type(fcall_idx));
        num_of_args = 0;
        $$ = FUN_REG;
      }
  ;


function_call
  : _ID 
      {
        fcall_idx = lookup_symbol($1, FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", $1);
      }
    _LPAREN argument _RPAREN
      {
        if((get_atr1(fcall_idx) + get_atr3(fcall_idx)) != $4)  // count of all atributs == atributes entered
          err("Wrong number of arguments to function '%s'", get_name(fcall_idx));
        
        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if($4 > 0)
        code("\n\t\t\tADDS\t%%15,$%d,%%15", $4 * 4);
          
        set_type(FUN_REG, get_type(fcall_idx));
        num_of_args = 0;
        $$ = FUN_REG;
      }
  ;

argument
  : /* empty */
    { $$ = 0; }
  | arguments 
  	{
  		$$ = $1;
  		for(int i = num_of_args; i >= 0; i--)
  		{
  			code("\n\t\t\tPUSH\t");
        	gen_sym_name(ArgsArray[i]);
  		}
  	}
  ;

arguments
  : num_exp
    { 

      type_of_arg = get_type($1);
      for(int i = 0; i < get_last_element(); i++)
      {
      	if(fcall_idx == Fun_params[i].fun_id)
      	{
      		if(Fun_params[i].fun_types[num_of_args] == type_of_arg)
			{}
      		else
      			err("Wrong arguments in function call '%s'", get_name(fcall_idx));     	
      	}
      }

      if(get_type($1) == INT)
      {
      	if(get_atr2(fcall_idx) != get_type($1))
      		err("Incompatible type for argument in function call '%s' ", get_name(fcall_idx));
      } else
      {
      	if(get_atr4(fcall_idx) != get_type($1))
      		err("Incompatible type for argument in function call '%s' ", get_name(fcall_idx));
      }
	  
	  free_if_reg($1);
	  ArgsArray[num_of_args] = $1;
	  
      num_of_args++;
      $$ = num_of_args;
    }
  | arguments _COMMA num_exp
  	{	
  	  type_of_arg = get_type($3);
      for(int i = 0; i < get_last_element(); i++)
      {
      	if(fcall_idx == Fun_params[i].fun_id)
      	{
      		if(Fun_params[i].fun_types[num_of_args] == type_of_arg)
      			{}
      		else
      			err("Wrong arguments in function call '%s'", get_name(fcall_idx)); 
	
      	}
      }
      	
      	free_if_reg($3);
      	ArgsArray[num_of_args] = $3;
      	
  		num_of_args++;
  		$$ = num_of_args;
  	}
  ;
  
if_statement
  : if_part %prec ONLY_IF
  	{ code("\n@exit%d:", $1); }
  | if_part _ELSE statement
  	{ code("\n@exit%d:", $1); }
  ;

if_part
  : _IF _LPAREN
  	{
        $<i>$ = ++lab_num;
        code("\n@if%d:", lab_num);
    }
     rel_exp 
     {
        code("\n\t\t%s\t@false%d", opp_jumps[$4], $<i>3); 
        code("\n@true%d:", $<i>3);
     }
      _RPAREN statement
      {
        code("\n\t\tJMP \t@exit%d", $<i>3);
        code("\n@false%d:", $<i>3);
        $$ = $<i>3;
      }
  ;

rel_exp
  : num_exp _RELOP num_exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: relational operator");
        $$ = $2 + ((get_type($1) - 1) * RELOP_NUMBER);
        gen_cmp($1, $3);
      }
  ;

return_statement
   : _RETURN _SEMICOLON 
  	{	
  		return_flag = TRUE;
  		if(get_type(fun_idx) != VOID)
          warn("This function returns value! Missing return expression!");
  	}
  | _RETURN num_exp _SEMICOLON
      {
      	return_flag = TRUE;
        if(get_type(fun_idx) != get_type($2))
          err("incompatible types in return");
        else if (get_type(fun_idx) == VOID)
        	err("Void function can't have return value!");
        gen_mov($2, FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));
          
      }
  ;

%%

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}

