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

zend_class_entry *ce_g_enum;

/* ----------------------------------------------------------------
    G\Enum class API
------------------------------------------------------------------*/

ZEND_BEGIN_ARG_INFO(Enum___construct_args, ZEND_SEND_BY_VAL)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(Enum_getName_args, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(Enum_getValue_args, ZEND_SEND_BY_VAL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(Enum_setValue_args, ZEND_SEND_BY_VAL)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(Enum_getElements_args, ZEND_SEND_BY_VAL)
ZEND_END_ARG_INFO()

/* {{{ proto void Enum->__construct(mixed value)
constructor for enum class */
PHP_METHOD(Enum, __construct)
{
	zval *member;

	PHP_G_EXCEPTIONS
	if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &member)) {
		return;
	}
	PHP_G_RESTORE_ERRORS
}
/* }}} */

/* {{{ proto string Enum->getName()
get member name of current enum value */
PHP_METHOD(Enum, getName)
{
	PHP_G_EXCEPTIONS
	if (FAILURE == zend_parse_parameters_none()) {
		return;
	}
	PHP_G_RESTORE_ERRORS
}
/* }}} */

/* {{{ proto mixed Enum->getValue()
get value of current enum*/
PHP_METHOD(Enum, getValue)
{
	PHP_G_EXCEPTIONS
	if (FAILURE == zend_parse_parameters_none()) {
		return;
	}
	PHP_G_RESTORE_ERRORS
}
/* }}} */

/* {{{ proto mixed Enum->setValue(mixed newvalue)
                   changes the enum to a new value */
PHP_METHOD(Enum, setValue)
{
	zval *member;

	PHP_G_EXCEPTIONS
	if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &member)) {
		return;
	}
	PHP_G_RESTORE_ERRORS
}
/* }}} */

/* {{{ proto array Enum::getElements()
get array of available name => value pairs */
PHP_METHOD(Enum, getElements)
{
	PHP_G_EXCEPTIONS
	if (FAILURE == zend_parse_parameters_none()) {
		return;
	}
	PHP_G_RESTORE_ERRORS
}
/* }}} */

/* ----------------------------------------------------------------
    G\Enum Definition and registration
------------------------------------------------------------------*/

static const zend_function_entry g_enum_methods[] = {
	PHP_ME(Enum, __construct, Enum___construct_args, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	PHP_ME(Enum, getName, Enum_getName_args, ZEND_ACC_PUBLIC)
	PHP_ME(Enum, getValue, Enum_getValue_args, ZEND_ACC_PUBLIC)
	PHP_ME(Enum, setValue, Enum_setValue_args, ZEND_ACC_PUBLIC)
	PHP_ME(Enum, getElements, Enum_getElements_args, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_FE_END
};

PHP_MINIT_FUNCTION(Enum)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, ZEND_NS_NAME(G_NAMESPACE, "Enum"), g_enum_methods);
	ce_g_enum = zend_register_internal_class(&ce TSRMLS_CC);
	ce_g_enum->ce_flags |= ZEND_ACC_EXPLICIT_ABSTRACT_CLASS;

	return SUCCESS;
}


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
