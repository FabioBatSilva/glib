--TEST--
phpversion('g') value
--SKIPIF--
<?php
if(!extension_loaded('g')) die('skip - G extension not available');
?>
--FILE--
<?php
var_dump(phpversion('g'));
?>
--EXPECTF--
string(%d) "%d.%d.%d%s"