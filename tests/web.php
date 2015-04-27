<?php

$sampleStrings = json_decode(file_get_contents(__DIR__.'/sample.json'), true);

echo '<h3>Zawgyi to Unicode</h3>';

foreach ($sampleStrings['zg'] as $index => $zawgyi) {
	$unicode = $sampleStrings['uni'][$index];

	echo '<p style="font-family:myanmar3">' . (new \Rabbit\Converter)->zg2uni($zawgyi) .'</p>';
}

echo '<h3>Unicode to Zawgyi</h3>';

foreach ($sampleStrings['uni'] as $index => $zawgyi) {
	$unicode = $sampleStrings['zg'][$index];

	echo '<p style="font-family:zawgyi-one">' . (new \Rabbit\Converter)->uni2zg($zawgyi) .'</p>';
}