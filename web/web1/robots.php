<?php
$my_headers = apache_request_headers();
$adage = strtoupper($_SERVER['HTTP_ANSWER']);
if ($adage = "FEAR THE OLD BLOOD"){
	echo "Master Willem was right.";
	echo "auctf{f3ar_z_olD3_8l0oD}";
}
else {
	echo "VIDEO GAME TRIVIA: What is the adage of Byrgenwerth scholars?";
	echo "\n\n";
	echo "MAKE a GET request to this page with a header named 'answer' to submit your answer.";
}
?>
