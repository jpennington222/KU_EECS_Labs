<?php
error_reporting(E_ALL);
ini_set("display_errors", 1);
$Username = $_POST["user"];
$mysqli = new mysqli("mysql.eecs.ku.edu", "jpennington222", "Maij7Kah", "jpennington222");

/* check connection */
if ($mysqli->connect_errno)
{
    printf("Connect failed: %s\n", $mysqli->connect_error);
    exit();
}

$query = "SELECT author_id,content FROM Posts";

if ($result = $mysqli->query($query))
{
  echo "<table border='1'><tr>";

    /* fetch associative array */
    while ($row = $result->fetch_assoc())
    {
      if($row["author_id"] == $Username)
      {
        echo "<tr>" . "<td>" . $row["author_id"] . "</td>";
        echo "<td>" . $row["content"] . "</td></tr>";
      }
    }
    echo "</table>";
}

    /* free result set */
    $result->free();

/* close connection */
$mysqli->close();
?>
