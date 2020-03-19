function authenticate(password){
 if validate(pass){
	 console.log("Make a GET request to /hidden/nextstep.php");
}

function validate(pass){
return pass.length >= 5 && pass.includes("$");
}
