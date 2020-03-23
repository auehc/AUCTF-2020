<?php
function evaluate(){
	$in = "echo " . $_POST['statement'] . ";";
	$flag = "auctf{p6p_1nj3c7i0n_iz_k3wl}";
	$value = eval($in);
	return $value;
}

?>

<html>
</body>
<title>Calc Online</title>
<center><h1>Online Calculator</h1></center>
<form action="" method="post">
<center><h3>Input your expression</h3></center></br>
<center><input type="text" name="statement" /></center>
<center><input type="submit"/><center>
</form>
</br>
</br>
<div>
<?php
if (isset($_POST['statement'])){
		echo "<h2>Result</h2>";
		echo evaluate();
}
?>
</div>

</body>
</html>
