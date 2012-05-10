/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Elizabeth M Smith <auroraeosrose@php.net>                    |
  +----------------------------------------------------------------------+
*/

#ifndef PHP_G_PRIVATE_EXT_H
#define PHP_G_PRIVATE_EXT_H

#include "php_g.h"
#include <zend_exceptions.h>
#include <ext/spl/spl_exceptions.h>

/* Lifecycle - Extension */
PHP_MINIT_FUNCTION(g);
PHP_MINFO_FUNCTION(g);

/* Class lifecycle */
PHP_MINIT_FUNCTION(Enum);

#define PHP_G_EXCEPTIONS \
	zend_error_handling error_handling; \
	zend_replace_error_handling(EH_THROW, spl_ce_InvalidArgumentException, &error_handling TSRMLS_CC);

#define PHP_G_RESTORE_ERRORS \
	zend_restore_error_handling(&error_handling TSRMLS_CC);

PHP_G_API zend_class_entry *ce_g_enum;

#endif /* PHP_G_PRIVATE_EXT_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
