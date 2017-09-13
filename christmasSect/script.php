<?php
$fichier = fopen('resultat.txt','r');
$i=0;
while($ligne = fgets($fichier))
{
    $liste[$i] = $ligne;
    $i++;
}
sort($liste);
$i=0;
while(isset($liste[$i]))
{
    echo $liste[$i],"<br />";
    if ($i == 0) {
        $to = ''; //B
    }
    if ($i == 1) {
        $to = ''; //C
    }
    if ($i == 2) {
        $to = ''; //G
    }
    if ($i == 3) {
        $to = ''; //P
    }
    if ($i == 4) {
        $to = ''; //T
    }
    if ($i == 5) {
        $to = ''; //V
    }
    $subject = '2ème Édition du Noël de la Secte';
    $headers=htmlspecialchars("From: Père Noël\r\n");  
    $headers.='Content-Type: text/plain; charset="utf-8"'." ";
    $headers.='Content-Transfer-Encoding: 8bit';  
    $message = stripslashes(htmlspecialchars($liste[$i]));
    mail($to, $subject, $message, $headers);
    $i++;
}
fclose($fichier)
?>