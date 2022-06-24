#include <builtins.h>
#include <shell.h>
#include <stdio.h>

static int myhello(WORD_LIST *list) {
	puts("hello");
	fflush(stdout);
	return EXECUTION_SUCCESS;
}

static char *desc[] = {
	"Show a greeting message",
	"",
	"It's far faster than launching a new process",
	(char *)NULL
};

struct builtin myhello_struct = {
	"myhello",		// command name
	myhello,		// handler
	BUILTIN_ENABLED,	// initial flag
	desc,			// long description
	"myhello",		// short description
	0,
};
