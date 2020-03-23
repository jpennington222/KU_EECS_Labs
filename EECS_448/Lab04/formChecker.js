function check()
{
  var Item1 = document.getElementById("item1").value;
  var Item2 = document.getElementById("item2").value;
  var Item3 = document.getElementById("item3").value;
  var Ship = document.getElementsByName("Shipping").value;
  var User = document.getElementById("user").value;
  var Pass = document.getElementById("pass").value;

  var Item_Check = false;
  var User_Check = false;
  var Pass_Check = false;

  //check quantity input
  if(Item1 == "" || Item2 == "" || Item2 == "" || Item1 < 0 || Item2 < 0 || Item3 < 0)
  {
    alert("Please selected a quantity for all items");
    Item_Check = false;
  }
  else
  {
    Item_Check = true;
  }

  //check email
  if(validate(User))
  {
    User_Check = true;
  }
  else
  {
    alert("Invalid email")
    User_Check = false;
  }

  //check username
  if(Pass == "")
  {
    alert("Please input your password");
    Pass_Check = false;
  }
  else
  {
    Pass_Check = true;
  }

  //if all true, send to php
  if(Item_Check && User_Check && Pass_Check)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

//checks valid email by a pattern
function validate(Username)
{
  return /^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(Username)
}
