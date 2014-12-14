
#ifndef PHP_ZISCKY_H
#define PHP_ZISCKY_H

extern zend_module_entry ziscky_module_entry;
#define phpext_ziscky_ptr &ziscky_module_entry

#ifdef PHP_WIN32
# define PHP_ZISCKY_API __declspec(dllexport)
#else
# define PHP_ZISCKY_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(ziscky);
PHP_MSHUTDOWN_FUNCTION(ziscky);
PHP_RINIT_FUNCTION(ziscky);
PHP_RSHUTDOWN_FUNCTION(ziscky);
PHP_MINFO_FUNCTION(ziscky);

ZEND_NAMED_FUNCTION(_wrap_new_Ziscky);
ZEND_NAMED_FUNCTION(_wrap_Ziscky_ParallelSearch);
#endif /* PHP_ZISCKY_H */
