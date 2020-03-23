<?php
error_reporting(E_ALL);
ini_set("display_errors", 1);
$mysqli = new mysqli("mysql.eecs.ku.edu", "jpennington222", "Maij7Kah", "jpennington222");

/* check connection */
if ($mysqli->connect_errno)
{
    printf("Connect failed: %s\n", $mysqli->connect_error);
    exit();
}

foreach($_POST['box'] as $ID)
{
  $sql = "DELETE FROM Posts WHERE post_id=$ID";
  $mysqli->query($sql);
  echo "Post with post_id " . $ID . " was deleted<br>";
}

/* close connection */
$mysqli->close();
?>
