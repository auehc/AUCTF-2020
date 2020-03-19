<?php
if (rand() % 2 == 0){
	header("ROT13:".str_rot13("Make a POST request to /api/final.php"));
}
else{
	header("BAS64:".base64_encode("Make a POST request to /api/final.php"));
}
?>
