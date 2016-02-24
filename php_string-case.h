
#ifndef PHP_STRING-CASE_H
#define PHP_STRING-CASE_H

extern zend_module_entry string-case_module_entry;
#define phpext_string-case_ptr &string-case_module_entry

#define PHP_STRING-CASE_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_STRING-CASE_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_STRING-CASE_API __attribute__ ((visibility("default")))
#else
#	define PHP_STRING-CASE_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(string-case);
PHP_MSHUTDOWN_FUNCTION(string-case);
PHP_RINIT_FUNCTION(string-case);
PHP_RSHUTDOWN_FUNCTION(string-case);
PHP_MINFO_FUNCTION(string-case);

PHP_FUNCTION(confirm_string-case_compiled);	/* For testing, remove later. */
PHP_FUNCTION(studly_case);
PHP_FUNCTION(snake_case);
PHP_FUNCTION(camel_case);

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(string-case)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(string-case)
*/

/* In every utility function you add that needs to use variables 
   in php_string-case_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as STRING-CASE_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define STRING-CASE_G(v) TSRMG(string-case_globals_id, zend_string-case_globals *, v)
#else
#define STRING-CASE_G(v) (string-case_globals.v)
#endif

#endif	/* PHP_STRING-CASE_H */

