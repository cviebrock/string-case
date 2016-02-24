
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "ext/standard/php_string.h"
#include "php_stringcase.h"

/* If you declare any globals in php_stringcase.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(stringcase)
*/

/* True global resources - no need for thread safety here */
static int le_stringcase;

/* {{{ stringcase_functions[]
 *
 * Every user visible function must have an entry in stringcase_functions[].
 */
const zend_function_entry stringcase_functions[] = {
	PHP_FE(confirm_stringcase_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(studly_case,	NULL)
	PHP_FE(snake_case,	NULL)
	PHP_FE(camel_case,	NULL)
	PHP_FE_END	/* Must be the last line in stringcase_functions[] */
};
/* }}} */

/* {{{ stringcase_module_entry
 */
zend_module_entry stringcase_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"stringcase",
	stringcase_functions,
	PHP_MINIT(stringcase),
	PHP_MSHUTDOWN(stringcase),
	PHP_RINIT(stringcase),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(stringcase),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(stringcase),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_STRINGCASE_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_STRINGCASE
ZEND_GET_MODULE(stringcase)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("stringcase.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_stringcase_globals, stringcase_globals)
    STD_PHP_INI_ENTRY("stringcase.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_stringcase_globals, stringcase_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_stringcase_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_stringcase_init_globals(zend_stringcase_globals *stringcase_globals)
{
	stringcase_globals->global_value = 0;
	stringcase_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(stringcase)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(stringcase)
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
PHP_RINIT_FUNCTION(stringcase)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(stringcase)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(stringcase)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "stringcase support", "enabled");
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
/* {{{ proto string confirm_stringcase_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_stringcase_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "stringcase", arg);
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
	char *value;
	int argc = ZEND_NUM_ARGS();
	int value_len;

	if (zend_parse_parameters(argc TSRMLS_CC, "s", &value, &value_len) == FAILURE) 
		return;

  value = estrndup(value, value_len);
	php_strtolower(value, value_len);
	RETURN_STRINGL(value, value_len, 0);

	// php_error(E_WARNING, "studly_case: not yet implemented");
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
