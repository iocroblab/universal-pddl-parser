set(PARSER_SRC Action.cpp
	And.cpp
	CMakeLists.txt
	Derived.cpp
	Equals.cpp
	Exists.cpp
	Expression.cpp
	Forall.cpp
	Function.cpp
	FunctionModifier.cpp
	Ground.cpp
	GroundFunc.cpp
	Lifted.cpp
	Not.cpp
	Oneof.cpp
	Or.cpp
	ParamCond.cpp
	TemporalAction.cpp
	TypeGround.cpp
	When.cpp)

add_library(pddl_parser_shared SHARED ${PARSER_SRC})
set_target_properties( pddl_parser_shared PROPERTIES
  SOVERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
  VERSION "${PROJECT_VERSION}"
  OUTPUT_NAME pddl_parser)

add_library(pddl_parser_static STATIC ${PARSER_SRC})
set_target_properties( pddl_parser_static PROPERTIES
  OUTPUT_NAME pddl_parser)
