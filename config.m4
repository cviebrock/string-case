dnl $Id$
dnl config.m4 for extension stringcase

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(stringcase, for stringcase support,
dnl Make sure that the comment is aligned:
dnl [  --with-stringcase             Include stringcase support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(stringcase, whether to enable stringcase support,
dnl Make sure that the comment is aligned:
dnl [  --enable-stringcase           Enable stringcase support])

if test "$PHP_STRINGCASE" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-stringcase -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/stringcase.h"  # you most likely want to change this
  dnl if test -r $PHP_STRINGCASE/$SEARCH_FOR; then # path given as parameter
  dnl   STRINGCASE_DIR=$PHP_STRINGCASE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for stringcase files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       STRINGCASE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$STRINGCASE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the stringcase distribution])
  dnl fi

  dnl # --with-stringcase -> add include path
  dnl PHP_ADD_INCLUDE($STRINGCASE_DIR/include)

  dnl # --with-stringcase -> check for lib and symbol presence
  dnl LIBNAME=stringcase # you may want to change this
  dnl LIBSYMBOL=stringcase # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $STRINGCASE_DIR/$PHP_LIBDIR, STRINGCASE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_STRINGCASELIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong stringcase lib version or lib not found])
  dnl ],[
  dnl   -L$STRINGCASE_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(STRINGCASE_SHARED_LIBADD)

  PHP_NEW_EXTENSION(stringcase, stringcase.c, $ext_shared)
fi
