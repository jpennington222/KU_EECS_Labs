function change()
{
  //border variables
  document.getElementById("border").style.border = "solid"
  var border_red = document.getElementById("border_r");
  var border_green = document.getElementById("border_g");
  var border_blue = document.getElementById("border_b");
  var border_width = document.getElementById("border_w");

  var temp_width = border_width.value+"px";
  document.getElementById("border").style.borderWidth = temp_width;

  var temp_border_color = "rgb("+border_red.value+","+border_green.value+","+border_blue.value+")";
  document.getElementById("border").style.borderColor = temp_border_color;

  //background variables
  var bg_red = document.getElementById("bg_r");
  var bg_green = document.getElementById("bg_g");
  var bg_blue = document.getElementById("bg_b");

  var temp_bg_color = "rgb("+bg_red.value+","+bg_green.value+","+bg_blue.value+")";
  document.getElementById("border").style.backgroundColor = temp_bg_color;
}
