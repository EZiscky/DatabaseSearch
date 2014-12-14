<?php


// Try to load our extension if it's not already loaded.
if (!extension_loaded('ziscky')) {
  if (strtolower(substr(PHP_OS, 0, 3)) === 'win') {
    if (!dl('php_ziscky.dll')) return;
  } else {
    // PHP_SHLIB_SUFFIX gives 'dylib' on MacOS X but modules are 'so'.
    if (PHP_SHLIB_SUFFIX === 'dylib') {
      if (!dl('ziscky.so')) return;
    } else {
      if (!dl('ziscky.'.PHP_SHLIB_SUFFIX)) return;
    }
  }
}



/* PHP Proxy Classes */
class Ziscky {
	public $_cPtr=null;
	protected $_pData=array();

	function __set($var,$value) {
		if ($var === 'thisown') return swig_ziscky_alter_newobject($this->_cPtr,$value);
		$this->_pData[$var] = $value;
	}

	function __get($var) {
		if ($var === 'thisown') return swig_ziscky_get_newobject($this->_cPtr);
		return $this->_pData[$var];
	}

	function __isset($var) {
		if ($var === 'thisown') return true;
		return array_key_exists($var, $this->_pData);
	}

	function __construct($server,$uname,$pass) {
		if (is_resource($server) && get_resource_type($server) === '_p_Ziscky') {
			$this->_cPtr=$server;
			return;
		}
		$this->_cPtr=new_Ziscky($server,$uname,$pass);
	}

	function ParallelSearch($databases,$crossReference,$searchParam,$searchCondition,$regex) {
		return Ziscky_ParallelSearch($this->_cPtr,$databases,$crossReference,$searchParam,$searchCondition,$regex);
	}
}


?>
