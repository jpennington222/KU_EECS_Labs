<?php
$Q1 = $_POST["q1"];
$Q2 = $_POST["q2"];
$Q3 = $_POST["q3"];
$Q4 = $_POST["q4"];
$Q5 = $_POST["q5"];
$total = 0;

echo "Question 1: What is 1+1?<br>";
echo "You answered: " . $Q1 . "<br>";
echo "Correct answer: 2<br><br>";

echo "Question 2: What is 4x2?<br>";
echo "You answered: " . $Q2 . "<br>";
echo "Correct answer: 8<br><br>";

echo "Question 3: What is 880/80?<br>";
echo "You answered: " . $Q3 . "<br>";
echo "Correct answer: 11<br><br>";

echo "Question 4: What is 4x4?<br>";
echo "You answered: " . $Q4 . "<br>";
echo "Correct answer: 16<br><br>";

echo "Question 5: What is (1+7)(5+3)?<br>";
echo "You answered: " . $Q5 . "<br>";
echo "Correct answer: 64<br><br>";

if($Q1 == 2)
{
  $total = $total +1;
}
if($Q2 == 8)
{
  $total = $total +1;
}
if($Q3 == 11)
{
  $total = $total +1;
}
if($Q4 == 16)
{
  $total = $total +1;
}
if($Q5 == 64)
{
  $total = $total +1;
}

echo "Total correct: " . $total . "<br>";
echo "Percent correct: " . ($total/5)*100 . "%";
 ?>
