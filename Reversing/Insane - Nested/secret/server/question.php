<?php
$my_headers = apache_request_headers();
$hello = $_SERVER['HTTP_HELLO'];
$hand = $_SERVER['HTTP_COOKIE'];

if ($hello ==  "hello can you hear me?"){
	header("COOKIE:you_found_me");
	echo "Ahh. I see you've found me... here comes the flag :)\n";
}
if ($hand == "you_found_me"){
		echo "auctf{r3s0urc3_h4cK1Ng_1S_n3at0_1021}\n";
	}
?>
