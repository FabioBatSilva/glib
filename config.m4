PHP_ARG_WITH(glib, GLib (G Namespace) support,
[  --with-glib             Enable glib support], yes)

if test "$PHP_GLIB" != "no"; then
	export OLD_CPPFLAGS="$CPPFLAGS"
	export CPPFLAGS="$CPPFLAGS $INCLUDES -DHAVE_GLIB"

	AC_MSG_CHECKING(PHP version)
	AC_TRY_COMPILE([#include <php_version.h>], [
	#if PHP_VERSION_ID < 50400
	#error this extension requires at least PHP version 5.4.0
	#endif
	],
	[AC_MSG_RESULT(ok)],
	[AC_MSG_ERROR([need at least PHP 5.4.0])])

	export CPPFLAGS="$OLD_CPPFLAGS"

	PHP_SUBST(GLIB_SHARED_LIBADD)
	AC_DEFINE(HAVE_GLIB, 1, [ ])

	PHP_NEW_EXTENSION(glib, php_glib.c enum.c error.c struct.c string.c unicode.c, $ext_shared)

	EXT_G_HEADERS="php_glib_public.h"

	ifdef([PHP_INSTALL_HEADERS], [
		PHP_INSTALL_HEADERS(ext/glib, $EXT_GLIB_HEADERS)
	])

	AC_MSG_CHECKING(for pkg-config)

	if test ! -f "$PKG_CONFIG"; then
		PKG_CONFIG=`which pkg-config`
	fi

	if test -f "$PKG_CONFIG"; then
		AC_MSG_RESULT(found)
		AC_MSG_CHECKING(for glib)

	if $PKG_CONFIG --exists glib-2.0; then
		glib_version_full=`$PKG_CONFIG --modversion glib-2.0`
		AC_MSG_RESULT([found $glib_version_full])
		GLIB_LIBS="$LDFLAGS `$PKG_CONFIG --libs glib-2.0`"
		GLIB_INCS="$CFLAGS `$PKG_CONFIG --cflags-only-I glib-2.0`"
		PHP_EVAL_INCLINE($GLIB_INCS)
		PHP_EVAL_LIBLINE($GLIB_LIBS, GLIB_SHARED_LIBADD)
		AC_DEFINE(HAVE_GLIB, 1, [whether glib exists in the system])
	else
		AC_MSG_RESULT(not found)
		AC_MSG_ERROR(Ooops ! no glib found or detected in the system)
	fi
	else
		AC_MSG_RESULT(not found)
		AC_MSG_ERROR(Ooops ! no pkg-config found .... )
	fi

fi
