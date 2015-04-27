
extern zend_class_entry *rabbit_converter_ce;

ZEPHIR_INIT_CLASS(Rabbit_Converter);

PHP_METHOD(Rabbit_Converter, uni2zg);
PHP_METHOD(Rabbit_Converter, zg2uni);
PHP_METHOD(Rabbit_Converter, replaceWithRule);

ZEND_BEGIN_ARG_INFO_EX(arginfo_rabbit_converter_uni2zg, 0, 0, 1)
	ZEND_ARG_INFO(0, unicode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rabbit_converter_zg2uni, 0, 0, 1)
	ZEND_ARG_INFO(0, zawgyi)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rabbit_converter_replacewithrule, 0, 0, 2)
	ZEND_ARG_INFO(0, rules)
	ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(rabbit_converter_method_entry) {
	PHP_ME(Rabbit_Converter, uni2zg, arginfo_rabbit_converter_uni2zg, ZEND_ACC_PUBLIC)
	PHP_ME(Rabbit_Converter, zg2uni, arginfo_rabbit_converter_zg2uni, ZEND_ACC_PUBLIC)
	PHP_ME(Rabbit_Converter, replaceWithRule, arginfo_rabbit_converter_replacewithrule, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
