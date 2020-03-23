<?php
$mysqli = new mysqli("mysql.eecs.ku.edu", "jpennington222", "Maij7Kah", "jpennington222");

/* check connection */
if ($mysqli->connect_errno)
{
    printf("Connect failed: %s\n", $mysqli->connect_error);
    exit();
}

$query = "SELECT user_id FROM Users";

if ($result = $mysqli->query($query))
{
  echo "<table border='1'><h1>Users<tr>";

    /* fetch associative array */
    while ($row = $result->fetch_assoc())
    {
      //print Users
      echo "<tr>" . "<td>" . $row["user_id"] . "</td></tr>";
    }
    echo "</table>";
}

    /* free result set */
    $result->free();

/* close connection */
$mysqli->close();
?>
