--TEST--
Check studly_case
--SKIPIF--
<?php if (!extension_loaded("stringcase")) print "skip"; ?>
--FILE--
<?php
echo studly_case('THIS IS A TEST');
?>
--EXPECT--
this is a test