--TEST--
G\Enum cast handler;
--SKIPIF--
<?php
if(!extension_loaded('g')) die('skip - G extension not available');
?>
--FILE--
<?php
use G\Enum as Enum;

class Fruit extends Enum {
    const Apple = 1;
    const Pear = 2;
}

$fruit = new Fruit(Fruit::Apple);

var_dump((string)$fruit);
var_dump((int)$fruit);
var_dump((array)$fruit);
var_dump((object)$fruit);
var_dump((float)$fruit);
var_dump((bool)$fruit);
?>
= DONE =
--EXPECTF--
string(1) "1"
int(1)
array(0) {
}
object(Fruit)#1 (2) {
  ["__elements"]=>
  array(2) {
    ["Apple"]=>
    int(1)
    ["Pear"]=>
    int(2)
  }
  ["__value"]=>
  int(1)
}
float(1)
bool(true)
= DONE =