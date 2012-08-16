--TEST--
g phpinfo information
--SKIPIF--
<?php
if(!extension_loaded('g')) die('skip - G extension not available');
?>
--FILE--
<?php
$ext = new ReflectionExtension('g');
$ext->info();
?>
= DONE =
--EXPECTF--
g

G Support Objects => enabled
Glib Library Version => 2.%d.%d
Extension Version => %d.%d.%d%s
= DONE =