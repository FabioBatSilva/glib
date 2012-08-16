--TEST--
g class listing
--SKIPIF--
<?php
if(!extension_loaded('g')) die('skip - G extension not available');
?>
--FILE--
<?php
$ext = new ReflectionExtension('g');
var_dump($ext->getClassNames());
?>
= DONE =
--EXPECT--
array(5) {
  [0]=>
  string(6) "G\Enum"
  [1]=>
  string(8) "G\Struct"
  [2]=>
  string(7) "G\Error"
  [3]=>
  string(8) "G\String"
  [4]=>
  string(9) "G\Unicode"
}
= DONE =