var pics = ["bridge.jpg","cliff.jpg","ship.jpg","train.jpg","waterfall.jpg"]

function next()
{
  var current = document.getElementById("Image").src;
  if(current.includes("bridge"))
  {
    document.getElementById("Image").src = pics[1];
  }
  else if(current.includes("cliff"))
  {
    document.getElementById("Image").src = pics[2];
  }
  else if(current.includes("ship"))
  {
    document.getElementById("Image").src = pics[3];
  }
  else if(current.includes("train"))
  {
    document.getElementById("Image").src = pics[4];
  }
  else
  {
    document.getElementById("Image").src = pics[0];
  }
}

function previous()
{
  var current = document.getElementById("Image").src;
  if(current.includes("bridge"))
  {
    document.getElementById("Image").src = pics[4];
  }
  else if(current.includes("cliff"))
  {
    document.getElementById("Image").src = pics[0];
  }
  else if(current.includes("ship"))
  {
    document.getElementById("Image").src = pics[1];
  }
  else if(current.includes("train"))
  {
    document.getElementById("Image").src = pics[2];
  }
  else
  {
    document.getElementById("Image").src = pics[3];
  }
}
