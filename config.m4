dnl
dnl $Id$
dnl

PHP_ARG_WITH(g, G tools,
[  --with-g             Enable g support], yes)

if test "$PHP_G" != "no"; then
	export OLD_CPPFLAGS="$CPPFLAGS"
	export CPPFLAGS="$CPPFLAGS $INCLUDES -DHAVE_G"

	AC_MSG_CHECKING(PHP version)
	AC_TRY_COMPILE([#include <php_version.h>], [
	#if PHP_VERSION_ID < 50400
	#error this extension requires at least PHP version 5.4.0
	#endif
	],
 	[AC_MSG_RESULT(ok)],
	[AC_MSG_ERROR([need at least PHP 5.4.0])])

	export CPPFLAGS="$OLD_CPPFLAGS"

  PHP_SUBST(G_SHARED_LIBADD)
  AC_DEFINE(HAVE_G, 1, [ ])

  PHP_NEW_EXTENSION(g, g.c enum.c, $ext_shared)

  EXT_GI_HEADERS="php_g.h"

  ifdef([PHP_INSTALL_HEADERS], [
    PHP_INSTALL_HEADERS(ext/g, $EXT_G_HEADERS)
  ])

fi
