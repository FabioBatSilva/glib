--TEST--
glib phpinfo information
--SKIPIF--
<?php
include __DIR__ . '/skipif.inc';
?>
--FILE--
<?php
$ext = new ReflectionExtension('glib');
$ext->info();
?>
= DONE =
--EXPECTF--
glib

GLib extension (G namespace) => enabled
Glib Library Version => 2.32.3
Extension Version => 0.1.0-dev
= DONE =