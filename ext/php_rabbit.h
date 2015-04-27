
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_RABBIT_H
#define PHP_RABBIT_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_RABBIT_NAME        "Rabbit Converter"
#define PHP_RABBIT_VERSION     "1.0.0"
#define PHP_RABBIT_EXTNAME     "rabbit"
#define PHP_RABBIT_AUTHOR      "Rabbit Converter"
#define PHP_RABBIT_ZEPVERSION  "0.6.2a"
#define PHP_RABBIT_DESCRIPTION "Another Zawgyi <=> Unicode Converter"



ZEND_BEGIN_MODULE_GLOBALS(rabbit)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(rabbit)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(rabbit)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(rabbit_globals_id, zend_rabbit_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (rabbit_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_rabbit_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(rabbit_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(rabbit_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def rabbit_globals
#define zend_zephir_globals_def zend_rabbit_globals

extern zend_module_entry rabbit_module_entry;
#define phpext_rabbit_ptr &rabbit_module_entry

#endif
