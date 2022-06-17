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

add_library(universal_pddl_parser SHARED ${PARSER_SRC})
set_target_properties( universal_pddl_parser PROPERTIES
  SOVERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
  VERSION "${PROJECT_VERSION}"
  OUTPUT_NAME universal_pddl_parser)

