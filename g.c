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

#include "php_g.h"

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(g)
{
	PHP_MINIT(g_Enum)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(g_Struct)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(g_Error)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(g_String)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(g_Unicode)(INIT_FUNC_ARGS_PASSTHRU);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(g)
{
	char output_buf[58];
	snprintf(output_buf, sizeof(output_buf), "%d.%d.%d", glib_major_version, glib_minor_version, glib_micro_version);

	php_info_print_table_start();
	php_info_print_table_header(2, "G Support Objects", "enabled");
	php_info_print_table_row(2, "Glib Library Version", output_buf);
	php_info_print_table_row(2, "Extension Version", PHP_G_VERSION);
	php_info_print_table_end();
}
/* }}} */

/* {{{ g_module_entry */
zend_module_entry g_module_entry = {
	STANDARD_MODULE_HEADER,
	"g",
	NULL,
	PHP_MINIT(g),
	NULL,
	NULL,
	NULL,
	PHP_MINFO(g),
	PHP_G_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_G
ZEND_GET_MODULE(g)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */