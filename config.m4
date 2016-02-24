dnl $Id$
dnl config.m4 for extension string-case

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(string-case, for string-case support,
dnl Make sure that the comment is aligned:
dnl [  --with-string-case             Include string-case support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(string-case, whether to enable string-case support,
dnl Make sure that the comment is aligned:
dnl [  --enable-string-case           Enable string-case support])

if test "$PHP_STRING-CASE" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-string-case -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/string-case.h"  # you most likely want to change this
  dnl if test -r $PHP_STRING-CASE/$SEARCH_FOR; then # path given as parameter
  dnl   STRING-CASE_DIR=$PHP_STRING-CASE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for string-case files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       STRING-CASE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$STRING-CASE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the string-case distribution])
  dnl fi

  dnl # --with-string-case -> add include path
  dnl PHP_ADD_INCLUDE($STRING-CASE_DIR/include)

  dnl # --with-string-case -> check for lib and symbol presence
  dnl LIBNAME=string-case # you may want to change this
  dnl LIBSYMBOL=string-case # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $STRING-CASE_DIR/$PHP_LIBDIR, STRING-CASE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_STRING-CASELIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong string-case lib version or lib not found])
  dnl ],[
  dnl   -L$STRING-CASE_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(STRING-CASE_SHARED_LIBADD)

  PHP_NEW_EXTENSION(string-case, string-case.c, $ext_shared)
fi
