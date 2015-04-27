# Rabbit-Zephir

![Logo](https://avatars3.githubusercontent.com/u/11961573?v=3&s=100)


**Another Zawgyi <=> Unicode Converter for [Zephir](http://zephir-lang.com)**

## What is Zephir

Zephir - Ze(nd Engine) Ph(p) I(nt)r(mediate) - is a high level language that eases the creation and maintainability of extensions for PHP. Zephir extensions are exported to C code that can be compiled and optimized by major C compilers such as gcc/clang/vc++. Functionality is exposed to the PHP language.

## About

Zawgyi to Unicode has been written in [2011](https://github.com/saturngod/ZG2Uni_JS/commits/master). Now, unicode to zawgyi has been finished.

## Motivation. Why another converter ?

When I was writting [ZG2uni](https://github.com/saturngod/ZG2Uni_JS/), [Parabaik](https://github.com/ngwestar/parabaik) was not opensource. At that time, I need to use for [MYSTERY ZILLION](http://www.mysteryzillion.org) for converting the whole database to Unicode.

For Unicode to Zawgyi, Parabaik is under the ~~GPL license and cannot use in iOS app and Android App~~ LGPL. So, I decided to write new one with **WTFPL license**. This library is under MIT License.

> I cannot promise , it's correct 100% after converting.

> If you are not using in app or program and just for converting the text , please use [Parabaik](https://github.com/ngwestar/parabaik)

## Compilation

** See datail usage of zephir at [Zephir Github](https://github.com/phalcon/zephir) **

Follow these instructions to generate a binary extension for your platform:

```bash
git clone git@github.com:Rabbit-Converter/Rabbit-Zephir.git
cd Rabbit-Zephir
zephir build
```

Add the extension to your php.ini:

```bash
extension=rabbit.so
```

## Usage

```php

(new Rabbit\Converter)->zg2uni("သီဟိုဠ္မွ ဉာဏ္ႀကီးရွင္သည္ အာယုဝဍ္ဎနေဆးၫႊန္းစာကို ဇလြန္ေဈးေဘးဗာဒံပင္ထက္ အဓိ႒ာန္လ်က္ ဂဃနဏဖတ္ခဲ့သည္။");

(new Rabbit\Converter)->uni2zg("သီဟိုဠ်မှ ဉာဏ်ကြီးရှင်သည် အာယုဝဍ်ဎနဆေးညွှန်းစာကို ဇလွန်ဈေးဘေးဗာဒံပင်ထက် အဓိဋ္ဌာန်လျက် ဂဃနဏဖတ်ခဲ့သည်။");

```

## How to run Unit Test

** After install the rabbit extension for your PHP. Don't forget to add rabbit.so extension in cli/php.ini **

```bash
composer install
vendor/bin/phpunit
```

## Run Example

Run `http://rabbit.dev/tests/web.php` in you browser.

## Contributing

1. Fork it ( https://github.com/Rabbit-Converter/Rabbit-Zephir )
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## License

MIT
