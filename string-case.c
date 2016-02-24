
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_string-case.h"

/* If you declare any globals in php_string-case.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(string-case)
*/

/* True global resources - no need for thread safety here */
static int le_string-case;

/* {{{ string-case_functions[]
 *
 * Every user visible function must have an entry in string-case_functions[].
 */
const zend_function_entry string-case_functions[] = {
	PHP_FE(confirm_string-case_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(studly_case,	NULL)
	PHP_FE(snake_case,	NULL)
	PHP_FE(camel_case,	NULL)
	PHP_FE_END	/* Must be the last line in string-case_functions[] */
};
/* }}} */

/* {{{ string-case_module_entry
 */
zend_module_entry string-case_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"string-case",
	string-case_functions,
	PHP_MINIT(string-case),
	PHP_MSHUTDOWN(string-case),
	PHP_RINIT(string-case),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(string-case),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(string-case),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_STRING-CASE_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_STRING-CASE
ZEND_GET_MODULE(string-case)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("string-case.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_string-case_globals, string-case_globals)
    STD_PHP_INI_ENTRY("string-case.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_string-case_globals, string-case_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_string-case_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_string-case_init_globals(zend_string-case_globals *string-case_globals)
{
	string-case_globals->global_value = 0;
	string-case_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(string-case)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(string-case)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(string-case)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(string-case)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(string-case)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "string-case support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_string-case_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_string-case_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "string-case", arg);
	RETURN_STRINGL(strg, len, 0);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/

/* {{{ proto string studly_case(string value)
   Convert a value to studly caps case. */
PHP_FUNCTION(studly_case)
{
	char *value = NULL;
	int argc = ZEND_NUM_ARGS();
	int value_len;

	if (zend_parse_parameters(argc TSRMLS_CC, "s", &value, &value_len) == FAILURE) 
		return;

	php_error(E_WARNING, "studly_case: not yet implemented");
}
/* }}} */

/* {{{ proto string snake_case(string value, string delimiter)
   Convert a string to snake case. */
PHP_FUNCTION(snake_case)
{
	char *value = NULL;
	char *delimiter = NULL;
	int argc = ZEND_NUM_ARGS();
	int value_len;
	int delimiter_len;

	if (zend_parse_parameters(argc TSRMLS_CC, "ss", &value, &value_len, &delimiter, &delimiter_len) == FAILURE) 
		return;

	php_error(E_WARNING, "snake_case: not yet implemented");
}
/* }}} */

/* {{{ proto string camel_case(string value)
   Convert a value to camel case. */
PHP_FUNCTION(camel_case)
{
	char *value = NULL;
	int argc = ZEND_NUM_ARGS();
	int value_len;

	if (zend_parse_parameters(argc TSRMLS_CC, "s", &value, &value_len) == FAILURE) 
		return;

	php_error(E_WARNING, "camel_case: not yet implemented");
}
/* }}} */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
