<?php
echo "<link href='style.css' rel='stylesheet' type='text/css'/>";
echo "<link href='https://fonts.googleapis.com/css?family=Sofia' rel='stylesheet'>";
echo "<link href='https://fonts.googleapis.com/css?family=Quicksand&display=swap' rel='stylesheet'>";


echo "<h1> J.P.'s Home Decor</h1>";

$Chair = $_POST["chair"];
$Lamp = $_POST["lamp"];
$Book = $_POST["book"];
$Shipping = $_POST["shipping"];
$User = $_POST["user"];
$Pass = $_POST["pass"];

$Chair_Total = 0;
$Lamp_Total = 0;
$Book_Total = 0;
$Total_Cost = 0;

$Chair_Total = $Chair*150;
$Lamp_Total = $Lamp*30;
$Book_Total = $Book*100;
$Total_Cost = $Chair_Total+$Lamp_Total+$Book_Total+$Shipping;

if($Shipping == 0)
{
  $Shipping_Type = "Free 7 Day";
}
else if($Shipping == 50)
{
  $Shipping_Type = "Overnight";
}
else
{
  $Shipping_Type = "3 Day";
}


// Username and password
echo "<p class='welcome'>Welcome, Thank You For Your Purchase!</p>";
echo "<p class='info'> Username: " . $User . "</p>";
echo "<p class='info'> Password: " . $Pass . "</p>";


//heading for table
echo "<table class='receipt'>";

echo "<col width='200'>";
echo "<col width='200'>";
echo "<col width='200'>";
echo "<col width='200'>";

echo "<tr class='receipt'>";
echo "<th class='receipt text'></td>";
echo "<th class='receipt text'>Quantity</td>";
echo "<th class='receipt text'>Cost Per Item</td>";
echo "<th class='receipt text'>Sub Total</td></tr>";

//chairs
echo "<tr class='receipt'>";
echo "<td class='receipt text'>Set of 4 Chairs</td>";
echo "<td class='receipt number'>" . $Chair . "</td>";
echo "<td class='receipt number'>$150.00</td>";
echo "<td class='receipt number'>$" . $Chair_Total . "</td></tr>";

//lamp
echo "<tr class='receipt'>";
echo "<td class='receipt text'>Table Lamp</td>";
echo "<td class='receipt number'>" . $Lamp . "</td>";
echo "<td class='receipt number'>$30.00</td>";
echo "<td class='receipt number'>$" . $Lamp_Total . "</td></tr>";

//bookshelf
echo "<tr class='receipt'>";
echo "<td class='receipt text'>Bookshelf</td>";
echo "<td class='receipt number'>" . $Book . "</td>";
echo "<td class='receipt number'>$100.00</td>";
echo "<td class='receipt number'>$" . $Book_Total . "</td></tr>";

//Shipping
echo "<tr class='receipt'>";
echo "<td class='receipt text'>Shipping</td>";
echo "<td colspan=2 class='receipt text'>" . $Shipping_Type . "</td>";
echo "<td class='receipt number'>$" . $Shipping . "</td></tr>";

//total cost
echo "<tr class='receipt'>";
echo "<td colspan=3 class='receipt text'>Total Cost</td>";
echo "<td class='receipt total'>$" . $Total_Cost . "</td></tr></table>";
 ?>
