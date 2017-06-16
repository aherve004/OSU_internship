/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    lessOrEqual_token = 258,
    greaterOrEqual_token = 259,
    negative_infinity_token = 260,
    equivalent_token = 261,
    imply_token = 262,
    equal_token = 263,
    nonEqual_token = 264,
    positive_infinity_token = 265,
    forall_token = 266,
    exists_token = 267,
    case_token = 268,
    if_token = 269,
    switch_token = 270,
    then_token = 271,
    else_token = 272,
    otherwise_token = 273,
    sum_token = 274,
    product_token = 275,
    kronDelta_token = 276,
    diracDelta_token = 277,
    uniform_token = 278,
    bernoulli_token = 279,
    discrete_token = 280,
    normal_token = 281,
    poisson_token = 282,
    exponential_token = 283,
    weibull_token = 284,
    gama_token = 285,
    dirichlet_token = 286,
    multinomial_token = 287,
    types_token = 288,
    variables_token = 289,
    cpfs_token = 290,
    cdfs_token = 291,
    reward_token = 292,
    domain_token = 293,
    requirements_token = 294,
    objects_token = 295,
    init_state_token = 296,
    state_action_constraints_token = 297,
    action_preconditions_token = 298,
    state_invariants_token = 299,
    instance_token = 300,
    non_fluents_token = 301,
    discount_token = 302,
    terminate_when_token = 303,
    horizon_token = 304,
    max_nondef_actions_token = 305,
    doubleNum_token = 306,
    id_token = 307,
    variable_token = 308,
    enum_token = 309,
    object_token = 310,
    integer_token = 311,
    real_token = 312,
    bool_token = 313,
    true_token = 314,
    false_token = 315,
    default_token = 316,
    level_token = 317,
    observ_fluent_token = 318,
    action_fluent_token = 319,
    state_fluent_token = 320,
    intermediate_token = 321,
    derived_fluent_token = 322,
    non_fluent_token = 323,
    intNum_token = 324,
    AgregateOperator = 325,
    NEGATIVE = 326
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 27 "parser.ypp" /* yacc.c:1909  */

    double d;
    int i;
    std::string* str;
    std::vector<std::string>* strs;

    RDDLTask* rddlTask;
    Parameter* parameter;
    std::vector<Parameter*>* parameters;
    ParameterList* parameterList;
    ParametrizedVariable* parametrizedVariable;
    std::vector<ParametrizedVariable*>* parametrizedVariables;
    LogicalExpression* logicalExpression;
    Type* type;
    std::vector<Type*>* types;
    std::vector<LogicalExpression*>* logicalExpressions;
    ConditionEffectPair* conditionEffect;
    std::vector<ConditionEffectPair*>* conditionEffects;
    DiscreteDistribution* lConstCaseList;

#line 147 "parser.tab.hh" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HH_INCLUDED  */
