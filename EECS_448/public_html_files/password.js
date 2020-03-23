function check()
{
  var pass1 = document.getElementById("password1");
  var pass2 = document.getElementById("password2");

  if(pass1.value.length < 8)
  {
    alert("Password 1 is not at least 8 characters long");
  }
  else if(pass2.value.length < 8)
  {
    alert("Password 2 is not at least 8 characters long");
  }
  else if(pass1.value != pass2.value)
  {
    alert("Passwords entered do not match");
  }
  else if(pass1.value == pass2.value)
  {
    alert("Congrats! The passwords match");
  }
}
