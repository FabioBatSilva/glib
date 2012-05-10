<?php
use G\Enum;

class Fruit extends Enum {
    const Apple = 1;
    const Pear = 2;
    const Banana = 3;
    const Orange = 4;
    const Peach = 5;
}

class Exotic extends Fruit {
    const Papaya = 1;
    const Starfruit = 6;
    const Mango = 7;
}

$lunch1 = new Fruit('Apple');
$lunch2 = new Fruit(Fruit::Orange);

$dinner1 = new Exotic('Mango');
$dinner2 = new Exotic(Fruit::Papaya);

echo $lunch1;
echo $lunch2->getValue();
echo $lunch2->getName();

echo $dinner1;
echo $dinner2->getValue();
echo $dinner2->getName();

$values = Fruit::getElements();
foreach($values as $key => $value) {
     echo "My fruit $key is $value", PHP_EOL;
}

$values = Exotic::getElements();
foreach($values as $key => $value) {
     echo "My exotic fruit $key is $value", PHP_EOL;
}
