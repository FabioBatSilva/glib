--TEST--
G\Enum->__construct();
--SKIPIF--
<?php
if(!extension_loaded('g')) die('skip - G extension not available');
?>
--FILE--
<?php
use G\Enum as Enum;

class Test extends Enum {}

try {
    $item = new Test;
} catch (InvalidArgumentException $e) {
    echo $e->getMessage(), PHP_EOL;
}

class Fruit extends Enum {
    const Apple = 1;
    const Pear = 2;
}

try {
    $badfruit = new Fruit('apple');
} catch (InvalidArgumentException $e) {
    echo $e->getMessage(), PHP_EOL;
}

var_dump(new Fruit('Apple'));
var_dump(new Fruit(Fruit::Apple));

var_dump(new Fruit('Pear'));
var_dump(new Fruit(Fruit::Pear));

?>
--EXPECTF--
G\Enum::__construct() expects exactly 1 parameter, 0 given
(integer) 1
(integer) 1
(integer) 2
(integer) 2

