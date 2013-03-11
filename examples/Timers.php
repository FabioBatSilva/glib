<?php
use Glib\Timer;

$timer = new Timer;

$timer->stop();

var_dump($timer->elapsed());

$timer->continue();