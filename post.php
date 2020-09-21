<?php
$time = time();
$post = $_POST["post"];
$file = 'post.html';
$data = $time."  -  ".$post;
file_put_contents($file, $post);
?>