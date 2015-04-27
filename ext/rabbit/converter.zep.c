
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * Rabbit is Another Zawgyi <=> Unicode Converter.
 * 
 * @author Rabbit-Converter
 */
ZEPHIR_INIT_CLASS(Rabbit_Converter) {

	ZEPHIR_REGISTER_CLASS(Rabbit, Converter, rabbit, converter, rabbit_converter_method_entry, 0);

	/**
	 * Rabbit Converter version.
	 *
	 * @var string
	 */
	zend_declare_class_constant_string(rabbit_converter_ce, SL("VERSION"), "1.0.0" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Convert unicode string to zawgyi.
 *
 * @param  string unicode
 * @return string
 */
PHP_METHOD(Rabbit_Converter, uni2zg) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *unicode_param = NULL, *rules, _0;
	zval *unicode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &unicode_param);

	zephir_get_strval(unicode, unicode_param);


	ZEPHIR_INIT_VAR(rules);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "[ { \"from\": \"\\u1004\\u103a\\u1039\", \"to\": \"\\u1064\" }, { \"from\": \"\\u1039\\u1010\\u103d\", \"to\": \"\\u1096\" }, { \"from\": \"\\u1014(?=[\\u1030\\u103d\\u103e\\u102f\\u1039])\", \"to\": \"\\u108f\" }, { \"from\": \"\\u102b\\u103a\", \"to\": \"\\u105a\" }, { \"from\": \"\\u100b\\u1039\\u100c\", \"to\": \"\\u1092\" }, { \"from\": \"\\u102d\\u1036\", \"to\": \"\\u108e\" }, { \"from\": \"\\u104e\\u1004\\u103a\\u1038\", \"to\": \"\\u104e\" }, { \"from\": \"[\\u1025\\u1009](?=[\\u1039\\u102f\\u1030])\", \"to\": \"\\u106a\" }, { \"from\": \"[\\u1025\\u1009](?=[\\u103a])\", \"to\": \"\\u1025\" }, { \"from\": \"\\u100a(?=[\\u1039\\u102f\\u1030\\u103d])\", \"to\": \"\\u106b\" }, { \"from\": \"(\\u1039[\\u1000-\\u1021])\\u102f\", \"to\": \"$1\\u1033\" }, { \"from\": \"(\\u1039[\\u1000-\\u1021])\\u1030\", \"to\": \"$1\\u1034\" }, { \"from\": \"\\u1039\\u1000\", \"to\": \"\\u1060\" }, { \"from\": \"\\u1039\\u1001\", \"to\": \"\\u1061\" }, { \"from\": \"\\u1039\\u1002\", \"to\": \"\\u1062\" }, { \"from\": \"\\u1039\\u1003\", \"to\": \"\\u1063\" }, { \"from\": \"\\u1039\\u1005\", \"to\": \"\\u1065\" }, { \"from\": \"\\u1039\\u1007\", \"to\": \"\\u1068\" }, { \"from\": \"\\u1039\\u1008\", \"to\": \"\\u1069\" }, { \"from\": \"\\u100a(?=[\\u1039\\u102f\\u1030])\", \"to\": \"\\u106b\" }, { \"from\": \"\\u1039\\u100b\", \"to\": \"\\u106c\" }, { \"from\": \"\\u1039\\u100c\", \"to\": \"\\u106d\" }, { \"from\": \"\\u100d\\u1039\\u100d\", \"to\": \"\\u106e\" }, { \"from\": \"\\u100e\\u1039\\u100d\", \"to\": \"\\u106f\" }, { \"from\": \"\\u1039\\u100f\", \"to\": \"\\u1070\" }, { \"from\": \"\\u1039\\u1010\", \"to\": \"\\u1071\" }, { \"from\": \"\\u1039\\u1011\", \"to\": \"\\u1073\" }, { \"from\": \"\\u1039\\u1012\", \"to\": \"\\u1075\" }, { \"from\": \"\\u1039\\u1013\", \"to\": \"\\u1076\" }, { \"from\": \"\\u1039\\u1013\", \"to\": \"\\u1076\" }, { \"from\": \"\\u1039\\u1014\", \"to\": \"\\u1077\" }, { \"from\": \"\\u1039\\u1015\", \"to\": \"\\u1078\" }, { \"from\": \"\\u1039\\u1016\", \"to\": \"\\u1079\" }, { \"from\": \"\\u1039\\u1017\", \"to\": \"\\u107a\" }, { \"from\": \"\\u1039\\u1018\", \"to\": \"\\u107b\" }, { \"from\": \"\\u1039\\u1019\", \"to\": \"\\u107c\" }, { \"from\": \"\\u1039\\u101c\", \"to\": \"\\u1085\" }, { \"from\": \"\\u103f\", \"to\": \"\\u1086\" }, { \"from\": \"(\\u103c)\\u103e\", \"to\": \"$1\\u1087\" }, { \"from\": \"\\u103d\\u103e\", \"to\": \"\\u108a\" }, { \"from\": \"(\\u1064)([\\u1031]?)([\\u103c]?)([\\u1000-\\u1021])\\u102d\", \"to\": \"$2$3$4\\u108b\" }, { \"from\": \"(\\u1064)([\\u1031]?)([\\u103c]?)([\\u1000-\\u1021])\\u102e\", \"to\": \"$2$3$4\\u108c\" }, { \"from\": \"(\\u1064)([\\u1031]?)([\\u103c]?)([\\u1000-\\u1021])\\u1036\", \"to\": \"$2$3$4\\u108d\" }, { \"from\": \"(\\u1064)([\\u1031]?)([\\u103c]?)([\\u1000-\\u1021])\", \"to\": \"$2$3$4$1\" }, { \"from\": \"\\u101b(?=[\\u102f\\u1030\\u103d\\u108a])\", \"to\": \"\\u1090\" }, { \"from\": \"\\u100f\\u1039\\u100d\", \"to\": \"\\u1091\" }, { \"from\": \"\\u100b\\u1039\\u100b\", \"to\": \"\\u1097\" }, { \"from\": \"([\\u1000-\\u1021\\u1029\\u1090])([\\u1060-\\u1069\\u106c\\u106d\\u1070-\\u107c\\u1085\\u108a])?([\\u103b-\\u103e]*)?\\u1031\", \"to\": \"\\u1031$1$2$3\" }, { \"from\": \"([\\u1000-\\u1021\\u1029])([\\u1060-\\u1069\\u106c\\u106d\\u1070-\\u107c\\u1085])?(\\u103c)\", \"to\": \"$3$1$2\" }, { \"from\": \"\\u103a\", \"to\": \"\\u1039\" }, { \"from\": \"\\u103b\", \"to\": \"\\u103a\" }, { \"from\": \"\\u103c\", \"to\": \"\\u103b\" }, { \"from\": \"\\u103d\", \"to\": \"\\u103c\" }, { \"from\": \"\\u103e\", \"to\": \"\\u103d\" }, { \"from\": \"\\u103d\\u102f\", \"to\": \"\\u1088\" }, { \"from\": \"([\\u102f\\u1030\\u1014\\u101b\\u103c\\u108a\\u103d\\u1088])([\\u1032\\u1036]{0,1})\\u1037\", \"to\": \"$1$2\\u1095\" }, { \"from\": \"\\u102f\\u1095\", \"to\": \"\\u102f\\u1094\" }, { \"from\": \"([\\u1014\\u101b])([\\u1032\\u1036\\u102d\\u102e\\u108b\\u108c\\u108d\\u108e])\\u1037\", \"to\": \"$1$2\\u1095\" }, { \"from\": \"\\u1095\\u1039\", \"to\": \"\\u1094\\u1039\" }, { \"from\": \"([\\u103a\\u103b])([\\u1000-\\u1021])([\\u1036\\u102d\\u102e\\u108b\\u108c\\u108d\\u108e]?)\\u102f\", \"to\": \"$1$2$3\\u1033\" }, { \"from\": \"([\\u103a\\u103b])([\\u1000-\\u1021])([\\u1036\\u102d\\u102e\\u108b\\u108c\\u108d\\u108e]?)\\u1030\", \"to\": \"$1$2$3\\u1034\" }, { \"from\": \"\\u103a\\u102f\", \"to\": \"\\u103a\\u1033\" }, { \"from\": \"\\u103a([\\u1036\\u102d\\u102e\\u108b\\u108c\\u108d\\u108e])\\u102f\", \"to\": \"\\u103a$1\\u1033\" }, { \"from\": \"([\\u103a\\u103b])([\\u1000-\\u1021])\\u1030\", \"to\": \"$1$2\\u1034\" }, { \"from\": \"\\u103a\\u1030\", \"to\": \"\\u103a\\u1034\" }, { \"from\": \"\\u103a([\\u1036\\u102d\\u102e\\u108b\\u108c\\u108d\\u108e])\\u1030\", \"to\": \"\\u103a$1\\u1034\" }, { \"from\": \"\\u103d\\u1030\", \"to\": \"\\u1089\" }, { \"from\": \"\\u103b([\\u1000\\u1003\\u1006\\u100f\\u1010\\u1011\\u1018\\u101a\\u101c\\u101a\\u101e\\u101f])\", \"to\": \"\\u107e$1\" }, { \"from\": \"\\u107e([\\u1000\\u1003\\u1006\\u100f\\u1010\\u1011\\u1018\\u101a\\u101c\\u101a\\u101e\\u101f])([\\u103c\\u108a])([\\u1032\\u1036\\u102d\\u102e\\u108b\\u108c\\u108d\\u108e])\", \"to\": \"\\u1084$1$2$3\" }, { \"from\": \"\\u107e([\\u1000\\u1003\\u1006\\u100f\\u1010\\u1011\\u1018\\u101a\\u101c\\u101a\\u101e\\u101f])([\\u103c\\u108a])\", \"to\": \"\\u1082$1$2\" }, { \"from\": \"\\u107e([\\u1000\\u1003\\u1006\\u100f\\u1010\\u1011\\u1018\\u101a\\u101c\\u101a\\u101e\\u101f])([\\u1033\\u1034]?)([\\u1032\\u1036\\u102d\\u102e\\u108b\\u108c\\u108d\\u108e])\", \"to\": \"\\u1080$1$2$3\" }, { \"from\": \"\\u103b([\\u1000-\\u1021])([\\u103c\\u108a])([\\u1032\\u1036\\u102d\\u102e\\u108b\\u108c\\u108d\\u108e])\", \"to\": \"\\u1083$1$2$3\" }, { \"from\": \"\\u103b([\\u1000-\\u1021])([\\u103c\\u108a])\", \"to\": \"\\u1081$1$2\" }, { \"from\": \"\\u103b([\\u1000-\\u1021])([\\u1033\\u1034]?)([\\u1032\\u1036\\u102d\\u102e\\u108b\\u108c\\u108d\\u108e])\", \"to\": \"\\u107f$1$2$3\" }, { \"from\": \"\\u103a\\u103d\", \"to\": \"\\u103d\\u103a\" }, { \"from\": \"\\u103a([\\u103c\\u108a])\", \"to\": \"$1\\u107d\" }, { \"from\": \"([\\u1033\\u1034])\\u1094\", \"to\": \"$1\\u1095\" }]", 0);
	zephir_json_decode(rules, &(rules), &_0, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replacewithrule", NULL, rules, unicode);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Convert zawgyi string to unicode.
 *
 * @param  string zawgyi
 * @return string
 */
PHP_METHOD(Rabbit_Converter, zg2uni) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *zawgyi_param = NULL, *rules, _0;
	zval *zawgyi = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &zawgyi_param);

	zephir_get_strval(zawgyi, zawgyi_param);


	ZEPHIR_INIT_VAR(rules);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "[ { \"from\": \"(\\u103d|\\u1087)\", \"to\": \"\\u103e\" }, { \"from\": \"\\u103c\", \"to\": \"\\u103d\" }, { \"from\": \"(\\u103b|\\u107e|\\u107f|\\u1080|\\u1081|\\u1082|\\u1083|\\u1084)\", \"to\": \"\\u103c\" }, { \"from\": \"(\\u103a|\\u107d)\", \"to\": \"\\u103b\" }, { \"from\": \"\\u1039\", \"to\": \"\\u103a\" }, { \"from\": \"\\u106a\", \"to\": \"\\u1009\" }, { \"from\": \"\\u106b\", \"to\": \"\\u100a\" }, { \"from\": \"\\u106c\", \"to\": \"\\u1039\\u100b\" }, { \"from\": \"\\u106d\", \"to\": \"\\u1039\\u100c\" }, { \"from\": \"\\u106e\", \"to\": \"\\u100d\\u1039\\u100d\" }, { \"from\": \"\\u106f\", \"to\": \"\\u100d\\u1039\\u100e\" }, { \"from\": \"\\u1070\", \"to\": \"\\u1039\\u100f\" }, { \"from\": \"(\\u1071|\\u1072)\", \"to\": \"\\u1039\\u1010\" }, { \"from\": \"\\u1060\", \"to\": \"\\u1039\\u1000\" }, { \"from\": \"\\u1061\", \"to\": \"\\u1039\\u1001\" }, { \"from\": \"\\u1062\", \"to\": \"\\u1039\\u1002\" }, { \"from\": \"\\u1063\", \"to\": \"\\u1039\\u1003\" }, { \"from\": \"\\u1065\", \"to\": \"\\u1039\\u1005\" }, { \"from\": \"\\u1068\", \"to\": \"\\u1039\\u1007\" }, { \"from\": \"\\u1069\", \"to\": \"\\u1039\\u1008\" }, { \"from\": \"/(\\u1073|\\u1074)/g\", \"to\": \"\\u1039\\u1011\" }, { \"from\": \"\\u1075\", \"to\": \"\\u1039\\u1012\" }, { \"from\": \"\\u1076\", \"to\": \"\\u1039\\u1013\" }, { \"from\": \"\\u1077\", \"to\": \"\\u1039\\u1014\" }, { \"from\": \"\\u1078\", \"to\": \"\\u1039\\u1015\" }, { \"from\": \"\\u1079\", \"to\": \"\\u1039\\u1016\" }, { \"from\": \"\\u107a\", \"to\": \"\\u1039\\u1017\" }, { \"from\": \"\\u107c\", \"to\": \"\\u1039\\u1019\" }, { \"from\": \"\\u1085\", \"to\": \"\\u1039\\u101c\" }, { \"from\": \"\\u1033\", \"to\": \"\\u102f\" }, { \"from\": \"\\u1034\", \"to\": \"\\u1030\" }, { \"from\": \"\\u103f\", \"to\": \"\\u1030\" }, { \"from\": \"\\u1086\", \"to\": \"\\u103f\" }, { \"from\": \"\\u1088\", \"to\": \"\\u103e\\u102f\" }, { \"from\": \"\\u1089\", \"to\": \"\\u103e\\u1030\" }, { \"from\": \"\\u108a\", \"to\": \"\\u103d\\u103e\" }, { \"from\": \"([\\u1000-\\u1021])\\u1064\", \"to\": \"\\u1004\\u103a\\u1039$1\" }, { \"from\": \"([\\u1000-\\u1021])\\u108b\", \"to\": \"\\u1004\\u103a\\u1039$1\\u102d\" }, { \"from\": \"([\\u1000-\\u1021])\\u108c\", \"to\": \"\\u1004\\u103a\\u1039$1\\u102e\" }, { \"from\": \"([\\u1000-\\u1021])\\u108d\", \"to\": \"\\u1004\\u103a\\u1039$1\\u1036\" }, { \"from\": \"\\u108e\", \"to\": \"\\u102d\\u1036\" }, { \"from\": \"\\u108f\", \"to\": \"\\u1014\" }, { \"from\": \"\\u1090\", \"to\": \"\\u101b\" }, { \"from\": \"\\u1091\", \"to\": \"\\u100f\\u1039\\u1091\" }, { \"from\": \"\\u1019\\u102c(\\u107b|\\u1093)\", \"to\": \"\\u1019\\u1039\\u1018\\u102c\" }, { \"from\": \"(\\u107b|\\u1093)\", \"to\": \"\\u103a\\u1018\" }, { \"from\": \"(\\u1094|\\u1095)\", \"to\": \"\\u1037\" }, { \"from\": \"\\u1096\", \"to\": \"\\u1039\\u1010\\u103d\" }, { \"from\": \"\\u1097\", \"to\": \"\\u100b\\u1039\\u100b\" }, { \"from\": \"\\u103c([\\u1000-\\u1021])([\\u1000-\\u1021])?\", \"to\": \"$1\\u103c$2\" }, { \"from\": \"([\\u1000-\\u1021])\\u103c\\u103a\", \"to\": \"\\u103c$1\\u103a\" }, { \"from\": \"\\u1031([\\u1000-\\u1021])(\\u103e)?(\\u103b)?\", \"to\": \"$1$2$3\\u1031\" }, { \"from\": \"([\\u1000-\\u1021])\\u1031([\\u103b\\u103c\\u103d\\u103e]+)\", \"to\": \"$1$2\\u1031\" }, { \"from\": \"\\u1032\\u103d\", \"to\": \"\\u103d\\u1032\" }, { \"from\": \"\\u103d\\u103b\", \"to\": \"\\u103b\\u103d\" }, { \"from\": \"\\u103a\\u1037\", \"to\": \"\\u1037\\u103a\" }, { \"from\": \"\\u102f(\\u102d|\\u102e|\\u1036|\\u1037)\\u102f\", \"to\": \"\\u102f$1\" }, { \"from\": \"\\u102f\\u102f\", \"to\": \"\\u102f\" }, { \"from\": \"(\\u102f|\\u1030)(\\u102d|\\u102e)\", \"to\": \"$2$1\" }, { \"from\": \"(\\u103e)(\\u103b|\\u1037)\", \"to\": \"$2$1\" }, { \"from\": \"\\u1025(\\u103a|\\u102c)\", \"to\": \"\\u1009$1\" }, { \"from\": \"\\u1025\\u102e\", \"to\": \"\\u1026\" }, { \"from\": \"\\u1005\\u103b\", \"to\": \"\\u1008\" }, { \"from\": \"\\u1036(\\u102f|\\u1030)\", \"to\": \"$1\\u1036\" }, { \"from\": \"\\u1031\\u1037\\u103e\", \"to\": \"\\u103e\\u1031\\u1037\" }, { \"from\": \"\\u1031\\u103e\\u102c\", \"to\": \"\\u103e\\u1031\\u102c\" }, { \"from\": \"\\u105a\", \"to\": \"\\u102b\\u103a\" }, { \"from\": \"\\u1031\\u103b\\u103e\", \"to\": \"\\u103b\\u103e\\u1031\" }, { \"from\": \"(\\u102d|\\u102e)(\\u103d|\\u103e)\", \"to\": \"$2$1\" }, { \"from\": \"\\u102c\\u1039([\\u1000-\\u1021])\", \"to\": \"\\u1039$1\\u102c\" }, { \"from\": \"\\u103c\\u1004\\u103a\\u1039([\\u1000-\\u1021])\", \"to\": \"\\u1004\\u103a\\u1039$1\\u103c\" }, { \"from\": \"\\u1039\\u103c\\u103a\\u1039([\\u1000-\\u1021])\", \"to\": \"\\u103a\\u1039$1\\u103c\" }, { \"from\": \"\\u103c\\u1039([\\u1000-\\u1021])\", \"to\": \"\\u1039$1\\u103c\" }, { \"from\": \"\\u1036\\u1039([\\u1000-\\u1021])\", \"to\": \"\\u1039$1\\u1036\" }, { \"from\": \"\\u1092\", \"to\": \"\\u100b\\u1039\\u100c\" }, { \"from\": \"\\u104e\", \"to\": \"\\u104e\\u1004\\u103a\\u1038\" }, { \"from\": \"\\u1040(\\u102b|\\u102c|\\u1036)\", \"to\": \"\\u101d$1\" }, { \"from\": \"\\u1025\\u1039\", \"to\": \"\\u1009\\u1039\" }, { \"from\": \"([\\u1000-\\u1021])\\u103c\\u1031\\u103d\", \"to\": \"$1\\u103c\\u103d\\u1031\" }, { \"from\": \"([\\u1000-\\u1021])\\u103d\\u1031\\u103b\", \"to\": \"$1\\u103b\\u103d\\u1031\" }]", 0);
	zephir_json_decode(rules, &(rules), &_0, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replacewithrule", NULL, rules, zawgyi);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Replace the string with rules.
 *
 * @param  array rules
 * @param  string output
 * @return string
 */
PHP_METHOD(Rabbit_Converter, replaceWithRule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_9 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *rules, *output = NULL, *rule = NULL, *from = NULL, *to = NULL, **_2, *_3 = NULL, *_4, *_5 = NULL, *_6, *_7 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &rules, &output);

	ZEPHIR_SEPARATE_PARAM(output);


	zephir_is_iterable(rules, &_1, &_0, 0, 0, "rabbit/Converter.zep", 65);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(rule, _2);
		ZEPHIR_INIT_NVAR(_3);
		zephir_array_fetch_string(&_4, rule, SL("from"), PH_NOISY | PH_READONLY, "rabbit/Converter.zep", 59 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CONCAT_SVS(_5, "\"", _4, "\"");
		zephir_json_decode(_3, &(_3), _5, 0  TSRMLS_CC);
		ZEPHIR_INIT_NVAR(from);
		ZEPHIR_CONCAT_SVS(from, "~", _3, "~u");
		ZEPHIR_INIT_NVAR(to);
		zephir_array_fetch_string(&_6, rule, SL("to"), PH_NOISY | PH_READONLY, "rabbit/Converter.zep", 60 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_SVS(_7, "\"", _6, "\"");
		zephir_json_decode(to, &(to), _7, 0  TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_8, "preg_replace", &_9, from, to, output);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(output, _8);
	}
	RETVAL_ZVAL(output, 1, 0);
	RETURN_MM();

}

