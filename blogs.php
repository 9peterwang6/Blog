<?php
// a php script that opens the blog directory and read the title of the blogs
$dir = 'myblogs/';
?>

<!DOCTYPE html>
<html>
<head>
<title>My Blogs</title>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://9peterwang6.github.io/w3.css">
</head>
<body>

<!Header>
<div class="w3-container w3-black w3-center w3-animate-top">
  	<h1>My Blogs</h1>
</div>

<!Blogs>
<div class="w3-container w3-black w3-animate-opacity">
<?php
$dh = opendir($dir);
 while (($file = readdir($dh)) !== false)
{
?>
<div class="w3-panel w3-light-grey w3-leftbar w3-border-white w3-hover-border-blue">
    <a href = "<?=$dir . $file ?>">
	    <p><?=$file ?></p>
	</a>   
</div>
<?php
}
closedir($dh);
?>
</div>

<div class="w3-container w3-black w3-center w3-animate-opacity">
	<p> you can contact me via e-mail</p>
</div>

</body>
</html>
