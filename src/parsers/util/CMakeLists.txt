z3_add_component(parser_util
  SOURCES
    cost_parser.cpp
    pattern_validation.cpp
    scanner.cpp
    simple_parser.cpp
  COMPONENT_DEPENDENCIES
    ast
  PYG_FILES
    parser_params.pyg
)
