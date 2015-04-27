<?php

/**
 * Unit test for Rabbit Converter.
 */
class RabbitUnitTest extends PHPUnit_Framework_TestCase
{

	private $sampleStrings = array();

	private $rabbit;

	public function setUp()
	{
		$this->rabbit = new \Rabbit\Converter();

		$this->sampleStrings = json_decode(file_get_contents(__DIR__.'/sample.json'), true);
	}

	public function tearDown()
	{
		$this->sampleStrings = array();

		$this->rabbit = null;
	}

	/**
	 * Test Zawgyi to Unicode converting.
	 */
	public function testZg2uniConverting()
	{
		foreach ($this->sampleStrings['zg'] as $index => $zawgyi) {
			$unicode = $this->sampleStrings['uni'][$index];

			$this->assertSame($unicode, $this->rabbit->zg2uni($zawgyi));
		}
	}

	/**
	 * Test Unicode to Zawgyi converting.
	 */
	public function testUni2zgConverting()
	{
		foreach ($this->sampleStrings['uni'] as $index => $unicode) {
			$zawgyi = $this->sampleStrings['zg'][$index];

			$this->assertSame($zawgyi, $this->rabbit->uni2zg($unicode));
		}
	}
}