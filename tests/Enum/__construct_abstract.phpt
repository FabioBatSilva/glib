--TEST--
G\Enum is abstract
--SKIPIF--
<?php
if(!extension_loaded('g')) die('skip - G extension not available');
?>
--FILE--
<?php
use G\Enum as Enum;

$item = new Enum;

?>
--EXPECTF--
Fatal error: Cannot instantiate abstract class G\Enum in %s on line %d
