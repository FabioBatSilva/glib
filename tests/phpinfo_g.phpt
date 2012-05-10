--TEST--
g phpinfo information
--SKIPIF--
<?php
if(!extension_loaded('g')) die('skip - G extension not available');
?>
--FILE--
<?php
ob_start();
phpinfo(INFO_MODULES);
$data = ob_get_clean();
$data = explode("\n\n", $data);
foreach($data as $key => $info) {
	if ($info === 'g') {
		break;
	}
}
$data = $data[$key + 1];
var_dump($data);
?>
--EXPECTF--
string(30) "G Namespace support => enabled"
