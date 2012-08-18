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

#ifndef PHP_G_PUBLIC_H
#define PHP_G_PUBLIC_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#ifdef ZTS
# include "TSRM.h"
#endif

#include <php.h>

#ifdef PHP_WIN32
#  ifdef G_EXPORTS
#    define PHP_G_API __declspec(dllexport)
#  elif defined(COMPILE_DL_G)
#    define PHP_G_API __declspec(dllimport)
#  else
#    define PHP_G_API /* nothing special */
#  endif
#elif defined(__GNUC__) && __GNUC__ >= 4
#  define PHP_G_API __attribute__ ((visibility("default")))
#else
#  define PHP_G_API
#endif

#define PHP_G_VERSION "0.1.0-dev"
#define G_NAMESPACE "G"

extern zend_class_entry *ce_g_enum;
extern zend_class_entry *ce_g_struct;
extern zend_class_entry *ce_g_exception;
extern zend_class_entry *ce_g_string;
extern zend_class_entry *ce_g_unicode;

/* enum struct object */
typedef struct _g_enum_object g_enum_object;

/* so we don't have to include glib.h for one define */
typedef struct _GError GError;

PHP_G_API zend_bool php_g_handle_gerror(GError **error TSRMLS_DC);
PHP_G_API long php_g_get_enum_value(zval** enumclass TSRMLS_DC);

#endif /* PHP_G_PUBLIC_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
