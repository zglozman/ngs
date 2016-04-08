#ifndef AST_H
#define AST_H

typedef struct {
	uint32_t first_line;
	uint32_t first_column;
	uint32_t last_line;
	uint32_t last_column;
	int is_generated;
} ast_node_location;

typedef struct ast_node {
	unsigned int type;
	char *name;
	int number;
	void *data;
	// Chidren
	struct ast_node *first_child;
	struct ast_node *last_child;
	struct ast_node *next_sibling;
	ast_node_location location;
} ast_node;

typedef enum {
	ASSIGNMENT_NODE=1,
	IDENTIFIER_NODE,
	INT_NODE,
	REAL_NODE,
	EXPRESSIONS_NODE,
	FOR_NODE,
	CALL_NODE,
	EMPTY_NODE,
	ARR_LIT_NODE,
	FUNC_NODE,
	PARAMS_NODE,
	PARAM_NODE,
	STR_COMPS_NODE,
	STR_COMP_IMM_NODE,
	NULL_NODE,
	TRUE_NODE,
	FALSE_NODE,
	DEFINED_NODE,
	IF_NODE,
	ASSIGN_DEFAULT_NODE,
	WHILE_NODE,
	ARGS_NODE,
	ARG_NODE,
	LOCAL_NODE,
	HASH_LIT_NODE,
	INDEX_NODE,
	RETURN_NODE,
	AND_NODE,
	OR_NODE,
	ARR_SPLAT_NODE,
	HASH_SPLAT_NODE,
	GUARD_NODE,
	TRY_CATCH_NODE,
	THROW_NODE,
	COMMAND_NODE,
	BREAK_NODE,
	CONTINUE_NODE,
	NUMBER_OF_AST_NODE_TYPES
} ast_node_type;

extern char *NGS_AST_NODE_TYPES_NAMES[NUMBER_OF_AST_NODE_TYPES];

#ifdef DO_NGS_DEBUG
void print_ast(ast_node *node, int level);
#endif

#endif
