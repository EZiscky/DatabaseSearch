
#define SWIGPHP

#define SWIG_PREFIX ""
#define SWIG_PREFIX_LEN 0

#ifdef __cplusplus
/* SwigValueWrapper is described in swig.swg */
template<typename T> class SwigValueWrapper {
  struct SwigMovePointer {
    T *ptr;
    SwigMovePointer(T *p) : ptr(p) { }
    ~SwigMovePointer() { delete ptr; }
    SwigMovePointer& operator=(SwigMovePointer& rhs) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = rhs.ptr; rhs.ptr = 0; return *this; }
  } pointer;
  SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
  SwigValueWrapper(const SwigValueWrapper<T>& rhs);
public:
  SwigValueWrapper() : pointer(0) { }
  SwigValueWrapper& operator=(const T& t) { SwigMovePointer tmp(new T(t)); pointer = tmp; return *this; }
  operator T&() const { return *pointer.ptr; }
  T *operator&() { return pointer.ptr; }
};

template <typename T> T SwigValueInit() {
  return T();
}
#endif

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif


/* -----------------------------------------------------------------------------
 * swigrun.swg
 *
 * This file contains generic C API SWIG runtime support for pointer
 * type checking.
 * ----------------------------------------------------------------------------- */

/* This should only be incremented when either the layout of swig_type_info changes,
   or for whatever reason, the runtime changes incompatibly */
#define SWIG_RUNTIME_VERSION "4"

/* define SWIG_TYPE_TABLE_NAME as "SWIG_TYPE_TABLE" */
#ifdef SWIG_TYPE_TABLE
# define SWIG_QUOTE_STRING(x) #x
# define SWIG_EXPAND_AND_QUOTE_STRING(x) SWIG_QUOTE_STRING(x)
# define SWIG_TYPE_TABLE_NAME SWIG_EXPAND_AND_QUOTE_STRING(SWIG_TYPE_TABLE)
#else
# define SWIG_TYPE_TABLE_NAME
#endif

/*
  You can use the SWIGRUNTIME and SWIGRUNTIMEINLINE macros for
  creating a static or dynamic library from the SWIG runtime code.
  In 99.9% of the cases, SWIG just needs to declare them as 'static'.

  But only do this if strictly necessary, ie, if you have problems
  with your compiler or suchlike.
*/

#ifndef SWIGRUNTIME
# define SWIGRUNTIME SWIGINTERN
#endif

#ifndef SWIGRUNTIMEINLINE
# define SWIGRUNTIMEINLINE SWIGRUNTIME SWIGINLINE
#endif

/*  Generic buffer size */
#ifndef SWIG_BUFFER_SIZE
# define SWIG_BUFFER_SIZE 1024
#endif

/* Flags for pointer conversions */
#define SWIG_POINTER_DISOWN        0x1
#define SWIG_CAST_NEW_MEMORY       0x2

/* Flags for new pointer objects */
#define SWIG_POINTER_OWN           0x1


/*
   Flags/methods for returning states.

   The SWIG conversion methods, as ConvertPtr, return an integer
   that tells if the conversion was successful or not. And if not,
   an error code can be returned (see swigerrors.swg for the codes).

   Use the following macros/flags to set or process the returning
   states.

   In old versions of SWIG, code such as the following was usually written:

     if (SWIG_ConvertPtr(obj,vptr,ty.flags) != -1) {
       // success code
     } else {
       //fail code
     }

   Now you can be more explicit:

    int res = SWIG_ConvertPtr(obj,vptr,ty.flags);
    if (SWIG_IsOK(res)) {
      // success code
    } else {
      // fail code
    }

   which is the same really, but now you can also do

    Type *ptr;
    int res = SWIG_ConvertPtr(obj,(void **)(&ptr),ty.flags);
    if (SWIG_IsOK(res)) {
      // success code
      if (SWIG_IsNewObj(res) {
        ...
	delete *ptr;
      } else {
        ...
      }
    } else {
      // fail code
    }

   I.e., now SWIG_ConvertPtr can return new objects and you can
   identify the case and take care of the deallocation. Of course that
   also requires SWIG_ConvertPtr to return new result values, such as

      int SWIG_ConvertPtr(obj, ptr,...) {
        if (<obj is ok>) {
          if (<need new object>) {
            *ptr = <ptr to new allocated object>;
            return SWIG_NEWOBJ;
          } else {
            *ptr = <ptr to old object>;
            return SWIG_OLDOBJ;
          }
        } else {
          return SWIG_BADOBJ;
        }
      }

   Of course, returning the plain '0(success)/-1(fail)' still works, but you can be
   more explicit by returning SWIG_BADOBJ, SWIG_ERROR or any of the
   SWIG errors code.

   Finally, if the SWIG_CASTRANK_MODE is enabled, the result code
   allows to return the 'cast rank', for example, if you have this

       int food(double)
       int fooi(int);

   and you call

      food(1)   // cast rank '1'  (1 -> 1.0)
      fooi(1)   // cast rank '0'

   just use the SWIG_AddCast()/SWIG_CheckState()
*/

#define SWIG_OK                    (0)
#define SWIG_ERROR                 (-1)
#define SWIG_IsOK(r)               (r >= 0)
#define SWIG_ArgError(r)           ((r != SWIG_ERROR) ? r : SWIG_TypeError)

/* The CastRankLimit says how many bits are used for the cast rank */
#define SWIG_CASTRANKLIMIT         (1 << 8)
/* The NewMask denotes the object was created (using new/malloc) */
#define SWIG_NEWOBJMASK            (SWIG_CASTRANKLIMIT  << 1)
/* The TmpMask is for in/out typemaps that use temporal objects */
#define SWIG_TMPOBJMASK            (SWIG_NEWOBJMASK << 1)
/* Simple returning values */
#define SWIG_BADOBJ                (SWIG_ERROR)
#define SWIG_OLDOBJ                (SWIG_OK)
#define SWIG_NEWOBJ                (SWIG_OK | SWIG_NEWOBJMASK)
#define SWIG_TMPOBJ                (SWIG_OK | SWIG_TMPOBJMASK)
/* Check, add and del mask methods */
#define SWIG_AddNewMask(r)         (SWIG_IsOK(r) ? (r | SWIG_NEWOBJMASK) : r)
#define SWIG_DelNewMask(r)         (SWIG_IsOK(r) ? (r & ~SWIG_NEWOBJMASK) : r)
#define SWIG_IsNewObj(r)           (SWIG_IsOK(r) && (r & SWIG_NEWOBJMASK))
#define SWIG_AddTmpMask(r)         (SWIG_IsOK(r) ? (r | SWIG_TMPOBJMASK) : r)
#define SWIG_DelTmpMask(r)         (SWIG_IsOK(r) ? (r & ~SWIG_TMPOBJMASK) : r)
#define SWIG_IsTmpObj(r)           (SWIG_IsOK(r) && (r & SWIG_TMPOBJMASK))

/* Cast-Rank Mode */
#if defined(SWIG_CASTRANK_MODE)
#  ifndef SWIG_TypeRank
#    define SWIG_TypeRank             unsigned long
#  endif
#  ifndef SWIG_MAXCASTRANK            /* Default cast allowed */
#    define SWIG_MAXCASTRANK          (2)
#  endif
#  define SWIG_CASTRANKMASK          ((SWIG_CASTRANKLIMIT) -1)
#  define SWIG_CastRank(r)           (r & SWIG_CASTRANKMASK)
SWIGINTERNINLINE int SWIG_AddCast(int r) {
  return SWIG_IsOK(r) ? ((SWIG_CastRank(r) < SWIG_MAXCASTRANK) ? (r + 1) : SWIG_ERROR) : r;
}
SWIGINTERNINLINE int SWIG_CheckState(int r) {
  return SWIG_IsOK(r) ? SWIG_CastRank(r) + 1 : 0;
}
#else /* no cast-rank mode */
#  define SWIG_AddCast(r) (r)
#  define SWIG_CheckState(r) (SWIG_IsOK(r) ? 1 : 0)
#endif


#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void *(*swig_converter_func)(void *, int *);
typedef struct swig_type_info *(*swig_dycast_func)(void **);

/* Structure to store information on one type */
typedef struct swig_type_info {
  const char             *name;			/* mangled name of this type */
  const char             *str;			/* human readable name of this type */
  swig_dycast_func        dcast;		/* dynamic cast function down a hierarchy */
  struct swig_cast_info  *cast;			/* linked list of types that can cast into this type */
  void                   *clientdata;		/* language specific type data */
  int                    owndata;		/* flag if the structure owns the clientdata */
} swig_type_info;

/* Structure to store a type and conversion function used for casting */
typedef struct swig_cast_info {
  swig_type_info         *type;			/* pointer to type that is equivalent to this type */
  swig_converter_func     converter;		/* function to cast the void pointers */
  struct swig_cast_info  *next;			/* pointer to next cast in linked list */
  struct swig_cast_info  *prev;			/* pointer to the previous cast */
} swig_cast_info;

/* Structure used to store module information
 * Each module generates one structure like this, and the runtime collects
 * all of these structures and stores them in a circularly linked list.*/
typedef struct swig_module_info {
  swig_type_info         **types;		/* Array of pointers to swig_type_info structures that are in this module */
  size_t                 size;		        /* Number of types in this module */
  struct swig_module_info *next;		/* Pointer to next element in circularly linked list */
  swig_type_info         **type_initial;	/* Array of initially generated type structures */
  swig_cast_info         **cast_initial;	/* Array of initially generated casting structures */
  void                    *clientdata;		/* Language specific module data */
} swig_module_info;

/*
  Compare two type names skipping the space characters, therefore
  "char*" == "char *" and "Class<int>" == "Class<int >", etc.

  Return 0 when the two name types are equivalent, as in
  strncmp, but skipping ' '.
*/
SWIGRUNTIME int
SWIG_TypeNameComp(const char *f1, const char *l1,
		  const char *f2, const char *l2) {
  for (;(f1 != l1) && (f2 != l2); ++f1, ++f2) {
    while ((*f1 == ' ') && (f1 != l1)) ++f1;
    while ((*f2 == ' ') && (f2 != l2)) ++f2;
    if (*f1 != *f2) return (*f1 > *f2) ? 1 : -1;
  }
  return (int)((l1 - f1) - (l2 - f2));
}

/*
  Check type equivalence in a name list like <name1>|<name2>|...
  Return 0 if equal, -1 if nb < tb, 1 if nb > tb
*/
SWIGRUNTIME int
SWIG_TypeCmp(const char *nb, const char *tb) {
  int equiv = 1;
  const char* te = tb + strlen(tb);
  const char* ne = nb;
  while (equiv != 0 && *ne) {
    for (nb = ne; *ne; ++ne) {
      if (*ne == '|') break;
    }
    equiv = SWIG_TypeNameComp(nb, ne, tb, te);
    if (*ne) ++ne;
  }
  return equiv;
}

/*
  Check type equivalence in a name list like <name1>|<name2>|...
  Return 0 if not equal, 1 if equal
*/
SWIGRUNTIME int
SWIG_TypeEquiv(const char *nb, const char *tb) {
  return SWIG_TypeCmp(nb, tb) == 0 ? 1 : 0;
}

/*
  Check the typename
*/
SWIGRUNTIME swig_cast_info *
SWIG_TypeCheck(const char *c, swig_type_info *ty) {
  if (ty) {
    swig_cast_info *iter = ty->cast;
    while (iter) {
      if (strcmp(iter->type->name, c) == 0) {
        if (iter == ty->cast)
          return iter;
        /* Move iter to the top of the linked list */
        iter->prev->next = iter->next;
        if (iter->next)
          iter->next->prev = iter->prev;
        iter->next = ty->cast;
        iter->prev = 0;
        if (ty->cast) ty->cast->prev = iter;
        ty->cast = iter;
        return iter;
      }
      iter = iter->next;
    }
  }
  return 0;
}

/*
  Identical to SWIG_TypeCheck, except strcmp is replaced with a pointer comparison
*/
SWIGRUNTIME swig_cast_info *
SWIG_TypeCheckStruct(swig_type_info *from, swig_type_info *ty) {
  if (ty) {
    swig_cast_info *iter = ty->cast;
    while (iter) {
      if (iter->type == from) {
        if (iter == ty->cast)
          return iter;
        /* Move iter to the top of the linked list */
        iter->prev->next = iter->next;
        if (iter->next)
          iter->next->prev = iter->prev;
        iter->next = ty->cast;
        iter->prev = 0;
        if (ty->cast) ty->cast->prev = iter;
        ty->cast = iter;
        return iter;
      }
      iter = iter->next;
    }
  }
  return 0;
}

/*
  Cast a pointer up an inheritance hierarchy
*/
SWIGRUNTIMEINLINE void *
SWIG_TypeCast(swig_cast_info *ty, void *ptr, int *newmemory) {
  return ((!ty) || (!ty->converter)) ? ptr : (*ty->converter)(ptr, newmemory);
}

/*
   Dynamic pointer casting. Down an inheritance hierarchy
*/
SWIGRUNTIME swig_type_info *
SWIG_TypeDynamicCast(swig_type_info *ty, void **ptr) {
  swig_type_info *lastty = ty;
  if (!ty || !ty->dcast) return ty;
  while (ty && (ty->dcast)) {
    ty = (*ty->dcast)(ptr);
    if (ty) lastty = ty;
  }
  return lastty;
}

/*
  Return the name associated with this type
*/
SWIGRUNTIMEINLINE const char *
SWIG_TypeName(const swig_type_info *ty) {
  return ty->name;
}

/*
  Return the pretty name associated with this type,
  that is an unmangled type name in a form presentable to the user.
*/
SWIGRUNTIME const char *
SWIG_TypePrettyName(const swig_type_info *type) {
  /* The "str" field contains the equivalent pretty names of the
     type, separated by vertical-bar characters.  We choose
     to print the last name, as it is often (?) the most
     specific. */
  if (!type) return NULL;
  if (type->str != NULL) {
    const char *last_name = type->str;
    const char *s;
    for (s = type->str; *s; s++)
      if (*s == '|') last_name = s+1;
    return last_name;
  }
  else
    return type->name;
}

/*
   Set the clientdata field for a type
*/
SWIGRUNTIME void
SWIG_TypeClientData(swig_type_info *ti, void *clientdata) {
  swig_cast_info *cast = ti->cast;
  /* if (ti->clientdata == clientdata) return; */
  ti->clientdata = clientdata;

  while (cast) {
    if (!cast->converter) {
      swig_type_info *tc = cast->type;
      if (!tc->clientdata) {
	SWIG_TypeClientData(tc, clientdata);
      }
    }
    cast = cast->next;
  }
}
SWIGRUNTIME void
SWIG_TypeNewClientData(swig_type_info *ti, void *clientdata) {
  SWIG_TypeClientData(ti, clientdata);
  ti->owndata = 1;
}

/*
  Search for a swig_type_info structure only by mangled name
  Search is a O(log #types)

  We start searching at module start, and finish searching when start == end.
  Note: if start == end at the beginning of the function, we go all the way around
  the circular list.
*/
SWIGRUNTIME swig_type_info *
SWIG_MangledTypeQueryModule(swig_module_info *start,
                            swig_module_info *end,
		            const char *name) {
  swig_module_info *iter = start;
  do {
    if (iter->size) {
      size_t l = 0;
      size_t r = iter->size - 1;
      do {
	/* since l+r >= 0, we can (>> 1) instead (/ 2) */
	size_t i = (l + r) >> 1;
	const char *iname = iter->types[i]->name;
	if (iname) {
	  int compare = strcmp(name, iname);
	  if (compare == 0) {
	    return iter->types[i];
	  } else if (compare < 0) {
	    if (i) {
	      r = i - 1;
	    } else {
	      break;
	    }
	  } else if (compare > 0) {
	    l = i + 1;
	  }
	} else {
	  break; /* should never happen */
	}
      } while (l <= r);
    }
    iter = iter->next;
  } while (iter != end);
  return 0;
}

/*
  Search for a swig_type_info structure for either a mangled name or a human readable name.
  It first searches the mangled names of the types, which is a O(log #types)
  If a type is not found it then searches the human readable names, which is O(#types).

  We start searching at module start, and finish searching when start == end.
  Note: if start == end at the beginning of the function, we go all the way around
  the circular list.
*/
SWIGRUNTIME swig_type_info *
SWIG_TypeQueryModule(swig_module_info *start,
                     swig_module_info *end,
		     const char *name) {
  /* STEP 1: Search the name field using binary search */
  swig_type_info *ret = SWIG_MangledTypeQueryModule(start, end, name);
  if (ret) {
    return ret;
  } else {
    /* STEP 2: If the type hasn't been found, do a complete search
       of the str field (the human readable name) */
    swig_module_info *iter = start;
    do {
      size_t i = 0;
      for (; i < iter->size; ++i) {
	if (iter->types[i]->str && (SWIG_TypeEquiv(iter->types[i]->str, name)))
	  return iter->types[i];
      }
      iter = iter->next;
    } while (iter != end);
  }

  /* neither found a match */
  return 0;
}

/*
   Pack binary data into a string
*/
SWIGRUNTIME char *
SWIG_PackData(char *c, void *ptr, size_t sz) {
  static const char hex[17] = "0123456789abcdef";
  const unsigned char *u = (unsigned char *) ptr;
  const unsigned char *eu =  u + sz;
  for (; u != eu; ++u) {
    unsigned char uu = *u;
    *(c++) = hex[(uu & 0xf0) >> 4];
    *(c++) = hex[uu & 0xf];
  }
  return c;
}

/*
   Unpack binary data from a string
*/
SWIGRUNTIME const char *
SWIG_UnpackData(const char *c, void *ptr, size_t sz) {
  unsigned char *u = (unsigned char *) ptr;
  const unsigned char *eu = u + sz;
  for (; u != eu; ++u) {
    char d = *(c++);
    unsigned char uu;
    if ((d >= '0') && (d <= '9'))
      uu = ((d - '0') << 4);
    else if ((d >= 'a') && (d <= 'f'))
      uu = ((d - ('a'-10)) << 4);
    else
      return (char *) 0;
    d = *(c++);
    if ((d >= '0') && (d <= '9'))
      uu |= (d - '0');
    else if ((d >= 'a') && (d <= 'f'))
      uu |= (d - ('a'-10));
    else
      return (char *) 0;
    *u = uu;
  }
  return c;
}

/*
   Pack 'void *' into a string buffer.
*/
SWIGRUNTIME char *
SWIG_PackVoidPtr(char *buff, void *ptr, const char *name, size_t bsz) {
  char *r = buff;
  if ((2*sizeof(void *) + 2) > bsz) return 0;
  *(r++) = '_';
  r = SWIG_PackData(r,&ptr,sizeof(void *));
  if (strlen(name) + 1 > (bsz - (r - buff))) return 0;
  strcpy(r,name);
  return buff;
}

SWIGRUNTIME const char *
SWIG_UnpackVoidPtr(const char *c, void **ptr, const char *name) {
  if (*c != '_') {
    if (strcmp(c,"NULL") == 0) {
      *ptr = (void *) 0;
      return name;
    } else {
      return 0;
    }
  }
  return SWIG_UnpackData(++c,ptr,sizeof(void *));
}

SWIGRUNTIME char *
SWIG_PackDataName(char *buff, void *ptr, size_t sz, const char *name, size_t bsz) {
  char *r = buff;
  size_t lname = (name ? strlen(name) : 0);
  if ((2*sz + 2 + lname) > bsz) return 0;
  *(r++) = '_';
  r = SWIG_PackData(r,ptr,sz);
  if (lname) {
    strncpy(r,name,lname+1);
  } else {
    *r = 0;
  }
  return buff;
}

SWIGRUNTIME const char *
SWIG_UnpackDataName(const char *c, void *ptr, size_t sz, const char *name) {
  if (*c != '_') {
    if (strcmp(c,"NULL") == 0) {
      memset(ptr,0,sz);
      return name;
    } else {
      return 0;
    }
  }
  return SWIG_UnpackData(++c,ptr,sz);
}

#ifdef __cplusplus
}
#endif

/* -----------------------------------------------------------------------------
 * phprun.swg
 *
 * PHP runtime library
 * ----------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif
#include "zend.h"
#include "zend_API.h"
#include "zend_exceptions.h"
#include "php.h"
#include "ext/standard/php_string.h"
#include <stdlib.h> /* for abort(), used in generated code. */

#ifdef ZEND_RAW_FENTRY
/* ZEND_RAW_FENTRY was added somewhere between 5.2.0 and 5.2.3 */
# define SWIG_ZEND_NAMED_FE(ZN, N, A) ZEND_RAW_FENTRY((char*)#ZN, N, A, 0)
#else
/* This causes warnings from GCC >= 4.2 (assigning a string literal to char*).
 * But this seems to be unavoidable without directly assuming knowledge of
 * the structure, which changed between PHP4 and PHP5. */
# define SWIG_ZEND_NAMED_FE(ZN, N, A) ZEND_NAMED_FE(ZN, N, A)
#endif

#ifndef Z_SET_ISREF_P
/* For PHP < 5.3 */
# define Z_SET_ISREF_P(z) (z)->is_ref = 1
#endif
#ifndef Z_SET_REFCOUNT_P
/* For PHP < 5.3 */
# define Z_SET_REFCOUNT_P(z, rc) (z)->refcount = (rc)
#endif

#define SWIG_LONG_CONSTANT(N, V) zend_register_long_constant((char*)#N, sizeof(#N), V, CONST_CS | CONST_PERSISTENT, module_number TSRMLS_CC)
#define SWIG_DOUBLE_CONSTANT(N, V) zend_register_double_constant((char*)#N, sizeof(#N), V, CONST_CS | CONST_PERSISTENT, module_number TSRMLS_CC)
#define SWIG_STRING_CONSTANT(N, V) zend_register_stringl_constant((char*)#N, sizeof(#N), (char*)(V), strlen(V), CONST_CS | CONST_PERSISTENT, module_number TSRMLS_CC)
#define SWIG_CHAR_CONSTANT(N, V) do {\
    static char swig_char = (V);\
    zend_register_stringl_constant((char*)#N, sizeof(#N), &swig_char, 1, CONST_CS | CONST_PERSISTENT, module_number TSRMLS_CC);\
} while (0)

/* These TSRMLS_ stuff should already be defined now, but with older php under
   redhat are not... */
#ifndef TSRMLS_D
#define TSRMLS_D
#endif
#ifndef TSRMLS_DC
#define TSRMLS_DC
#endif
#ifndef TSRMLS_C
#define TSRMLS_C
#endif
#ifndef TSRMLS_CC
#define TSRMLS_CC
#endif

#ifdef __cplusplus
}
#endif

/* But in fact SWIG_ConvertPtr is the native interface for getting typed
   pointer values out of zvals.  We need the TSRMLS_ macros for when we
   make PHP type calls later as we handle php resources */
#define SWIG_ConvertPtr(obj,pp,type,flags) SWIG_ZTS_ConvertPtr(obj,pp,type,flags TSRMLS_CC)


#define SWIG_fail goto fail

static const char *default_error_msg = "Unknown error occurred";
static int default_error_code = E_ERROR;

#define SWIG_PHP_Arg_Error_Msg(argnum,extramsg) "Error in argument " #argnum " "#extramsg

#define SWIG_PHP_Error(code,msg) do { SWIG_ErrorCode() = code; SWIG_ErrorMsg() = msg; SWIG_fail; } while (0)

#define SWIG_contract_assert(expr,msg) \
  if (!(expr) ) { zend_printf("Contract Assert Failed %s\n",msg ); } else

/* Standard SWIG API */
#define SWIG_GetModule(clientdata) SWIG_Php_GetModule()
#define SWIG_SetModule(clientdata, pointer) SWIG_Php_SetModule(pointer)

/* used to wrap returned objects in so we know whether they are newobject
   and need freeing, or not */
typedef struct {
  void * ptr;
  int newobject;
} swig_object_wrapper;

/* empty zend destructor for types without one */
static ZEND_RSRC_DTOR_FUNC(SWIG_landfill) { (void)rsrc; }

#define SWIG_SetPointerZval(a,b,c,d) SWIG_ZTS_SetPointerZval(a,b,c,d TSRMLS_CC)
#define SWIG_as_voidptr(a) const_cast< void * >(static_cast< const void * >(a))

static void
SWIG_ZTS_SetPointerZval(zval *z, void *ptr, swig_type_info *type, int newobject TSRMLS_DC) {
  /*
   * First test for Null pointers.  Return those as PHP native NULL
   */
  if (!ptr ) {
    ZVAL_NULL(z);
    return;
  }
  if (type->clientdata) {
    swig_object_wrapper *value;
    if (! (*(int *)(type->clientdata)))
      zend_error(E_ERROR, "Type: %s failed to register with zend",type->name);
    value=(swig_object_wrapper *)emalloc(sizeof(swig_object_wrapper));
    value->ptr=ptr;
    value->newobject=(newobject & 1);
    if ((newobject & 2) == 0) {
      /* Just register the pointer as a resource. */
      ZEND_REGISTER_RESOURCE(z, value, *(int *)(type->clientdata));
    } else {
      /*
       * Wrap the resource in an object, the resource will be accessible
       * via the "_cPtr" member. This is currently only used by
       * directorin typemaps.
       */
      zval *resource;
      zend_class_entry **ce = NULL;
      const char *type_name = type->name+3; /* +3 so: _p_Foo -> Foo */
      size_t type_name_len;
      int result;
      const char * p;

      /* Namespace__Foo -> Foo */
      /* FIXME: ugly and goes wrong for classes with __ in their names. */
      while ((p = strstr(type_name, "__")) != NULL) {
        type_name = p + 2;
      }
      type_name_len = strlen(type_name);

      MAKE_STD_ZVAL(resource);
      ZEND_REGISTER_RESOURCE(resource, value, *(int *)(type->clientdata));
      if (SWIG_PREFIX_LEN > 0) {
        char * classname = (char*)emalloc(SWIG_PREFIX_LEN + type_name_len + 1);
        strcpy(classname, SWIG_PREFIX);
        strcpy(classname + SWIG_PREFIX_LEN, type_name);
        result = zend_lookup_class(classname, SWIG_PREFIX_LEN + type_name_len, &ce TSRMLS_CC);
        efree(classname);
      } else {
        result = zend_lookup_class((char *)type_name, type_name_len, &ce TSRMLS_CC);
      }
      if (result != SUCCESS) {
        /* class does not exist */
        object_init(z);
      } else {
        object_init_ex(z, *ce);
      }
      Z_SET_REFCOUNT_P(z, 1);
      Z_SET_ISREF_P(z);
      zend_hash_update(HASH_OF(z), (char*)"_cPtr", sizeof("_cPtr"), (void*)&resource, sizeof(zval), NULL);
    }
    return;
  }
  zend_error(E_ERROR, "Type: %s not registered with zend",type->name);
}

/* This pointer conversion routine takes the native pointer p (along with
   its type name) and converts it by calling appropriate casting functions
   according to ty.  The resultant pointer is returned, or NULL is returned
   if the pointer can't be cast.

   Sadly PHP has no API to find a type name from a type id, only from an
   instance of a resource of the type id, so we have to pass type_name as well.

   The two functions which might call this are:
   SWIG_ZTS_ConvertResourcePtr which gets the type name from the resource
   and the registered zend destructors for which we have one per type each
   with the type name hard wired in. */
static void *
SWIG_ZTS_ConvertResourceData(void * p, const char *type_name, swig_type_info *ty TSRMLS_DC) {
  swig_cast_info *tc;
  void *result = 0;

  if (!ty) {
    /* They don't care about the target type, so just pass on the pointer! */
    return p;
  }

  if (! type_name) {  
    /* can't convert p to ptr type ty if we don't know what type p is */
    return NULL;
  }

  /* convert and cast p from type_name to ptr as ty. */
  tc = SWIG_TypeCheck(type_name, ty);
  if (tc) {
    int newmemory = 0;
    result = SWIG_TypeCast(tc, p, &newmemory);
    assert(!newmemory); /* newmemory handling not yet implemented */
  }
  return result;
}

/* This function returns a pointer of type ty by extracting the pointer
   and type info from the resource in z.  z must be a resource.
   If it fails, NULL is returned.
   It uses SWIG_ZTS_ConvertResourceData to do the real work. */
static void *
SWIG_ZTS_ConvertResourcePtr(zval *z, swig_type_info *ty, int flags TSRMLS_DC) {
  swig_object_wrapper *value;
  void *p;
  int type;
  const char *type_name;

  value = (swig_object_wrapper *) zend_list_find(z->value.lval, &type);
  if (type==-1) return NULL;
  if (flags & SWIG_POINTER_DISOWN) {
    value->newobject = 0;
  }
  p = value->ptr;

  type_name=zend_rsrc_list_get_rsrc_type(z->value.lval TSRMLS_CC);

  return SWIG_ZTS_ConvertResourceData(p, type_name, ty TSRMLS_CC);
}

/* We allow passing of a RESOURCE pointing to the object or an OBJECT whose
   _cPtr is a resource pointing to the object */
static int
SWIG_ZTS_ConvertPtr(zval *z, void **ptr, swig_type_info *ty, int flags TSRMLS_DC) {
  if (z == NULL) {
    *ptr = 0;
    return 0;
  }

  switch (z->type) {
    case IS_OBJECT: {
      zval ** _cPtr;
      if (zend_hash_find(HASH_OF(z),(char*)"_cPtr",sizeof("_cPtr"),(void**)&_cPtr)==SUCCESS) {
	if ((*_cPtr)->type==IS_RESOURCE) {
	  *ptr = SWIG_ZTS_ConvertResourcePtr(*_cPtr, ty, flags TSRMLS_CC);
	  return (*ptr == NULL ? -1 : 0);
	}
      }
      break;
    }
    case IS_RESOURCE:
      *ptr = SWIG_ZTS_ConvertResourcePtr(z, ty, flags TSRMLS_CC);
      return (*ptr == NULL ? -1 : 0);
    case IS_NULL:
      *ptr = 0;
      return 0;
  }

  return -1;
}

static char const_name[] = "swig_runtime_data_type_pointer";
static swig_module_info *SWIG_Php_GetModule() {
  zval *pointer;
  swig_module_info *ret = 0;
  TSRMLS_FETCH();

  MAKE_STD_ZVAL(pointer);

  if (zend_get_constant(const_name, sizeof(const_name) - 1, pointer TSRMLS_CC)) {
    if (pointer->type == IS_LONG) {
      ret = (swig_module_info *) pointer->value.lval;
    }
  } 
  FREE_ZVAL(pointer);
  return ret; 
}

static void SWIG_Php_SetModule(swig_module_info *pointer) {
  TSRMLS_FETCH();
  REGISTER_MAIN_LONG_CONSTANT(const_name, (long) pointer, 0);
}

/*  Errors in SWIG */
#define  SWIG_UnknownError    	   -1
#define  SWIG_IOError        	   -2
#define  SWIG_RuntimeError   	   -3
#define  SWIG_IndexError     	   -4
#define  SWIG_TypeError      	   -5
#define  SWIG_DivisionByZero 	   -6
#define  SWIG_OverflowError  	   -7
#define  SWIG_SyntaxError    	   -8
#define  SWIG_ValueError     	   -9
#define  SWIG_SystemError    	   -10
#define  SWIG_AttributeError 	   -11
#define  SWIG_MemoryError    	   -12
#define  SWIG_NullReferenceError   -13




/* -------- TYPES TABLE (BEGIN) -------- */

#define SWIGTYPE_p_Ziscky swig_types[0]
#define SWIGTYPE_p_vectorT_std__string_t swig_types[1]
static swig_type_info *swig_types[3];
static swig_module_info swig_module = {swig_types, 2, 0, 0, 0, 0};
#define SWIG_TypeQuery(name) SWIG_TypeQueryModule(&swig_module, &swig_module, name)
#define SWIG_MangledTypeQuery(name) SWIG_MangledTypeQueryModule(&swig_module, &swig_module, name)

/* -------- TYPES TABLE (END) -------- */

/* header section */
ZEND_BEGIN_MODULE_GLOBALS(ziscky)
const char *error_msg;
int error_code;
ZEND_END_MODULE_GLOBALS(ziscky)
ZEND_DECLARE_MODULE_GLOBALS(ziscky)
#ifdef ZTS
#define SWIG_ErrorMsg() TSRMG(ziscky_globals_id, zend_ziscky_globals *, error_msg )
#define SWIG_ErrorCode() TSRMG(ziscky_globals_id, zend_ziscky_globals *, error_code )
#else
#define SWIG_ErrorMsg() (ziscky_globals.error_msg)
#define SWIG_ErrorCode() (ziscky_globals.error_code)
#endif

#ifdef __GNUC__
static void SWIG_FAIL(TSRMLS_D) __attribute__ ((__noreturn__));
#endif

static void SWIG_FAIL(TSRMLS_D) {
    zend_error(SWIG_ErrorCode(), "%s", SWIG_ErrorMsg());
    abort();
}

static void ziscky_init_globals(zend_ziscky_globals *globals ) {
  globals->error_msg = default_error_msg;
  globals->error_code = default_error_code;
}
static void ziscky_destroy_globals(zend_ziscky_globals * globals) { (void)globals; }

static void SWIG_ResetError(TSRMLS_D) {
  SWIG_ErrorMsg() = default_error_msg;
  SWIG_ErrorCode() = default_error_code;
}

ZEND_NAMED_FUNCTION(_wrap_swig_ziscky_alter_newobject) {
  zval **args[2];
  swig_object_wrapper *value;
  int type;

  SWIG_ResetError(TSRMLS_C);
  if(ZEND_NUM_ARGS() != 2 || zend_get_parameters_array_ex(2, args) != SUCCESS) {
    WRONG_PARAM_COUNT;
  }

  value = (swig_object_wrapper *) zend_list_find((*args[0])->value.lval, &type);
  value->newobject = zval_is_true(*args[1]);

  return;
}
ZEND_NAMED_FUNCTION(_wrap_swig_ziscky_get_newobject) {
  zval **args[1];
  swig_object_wrapper *value;
  int type;

  SWIG_ResetError(TSRMLS_C);
  if(ZEND_NUM_ARGS() != 1 || zend_get_parameters_array_ex(1, args) != SUCCESS) {
    WRONG_PARAM_COUNT;
  }

  value = (swig_object_wrapper *) zend_list_find((*args[0])->value.lval, &type);
  RETVAL_LONG(value->newobject);

  return;
}
#define SWIG_name  "ziscky"
#ifdef __cplusplus
extern "C" {
#endif
#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_ziscky.h"
#ifdef __cplusplus
}
#endif


#include "zend_exceptions.h"
#define SWIG_exception(code, msg) zend_throw_exception(NULL, (char*)msg, code TSRMLS_CC)


#include <stdexcept>


#include <string>


#include "ziscky.h"


/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (BEGIN) -------- */

static swig_type_info _swigt__p_Ziscky = {"_p_Ziscky", "Ziscky *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_vectorT_std__string_t = {"_p_vectorT_std__string_t", "vector< std::string > *", 0, 0, (void*)0, 0};

static swig_type_info *swig_type_initial[] = {
  &_swigt__p_Ziscky,
  &_swigt__p_vectorT_std__string_t,
};

static swig_cast_info _swigc__p_Ziscky[] = {  {&_swigt__p_Ziscky, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_vectorT_std__string_t[] = {  {&_swigt__p_vectorT_std__string_t, 0, 0, 0},{0, 0, 0, 0}};

static swig_cast_info *swig_cast_initial[] = {
  _swigc__p_Ziscky,
  _swigc__p_vectorT_std__string_t,
};


/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (END) -------- */

/* end header section */
/* vdecl subsection */
static int le_swig__p_vectorT_std__string_t=0; /* handle for _p_vectorT_std__string_t */
static int le_swig__p_Ziscky=0; /* handle for Ziscky */
/* end vdecl subsection */
/* wrapper section */
ZEND_NAMED_FUNCTION(_wrap_new_Ziscky) {
  std::string arg1 ;
  std::string arg2 ;
  std::string arg3 ;
  zval **args[3];
  Ziscky *result = 0 ;
  
  SWIG_ResetError(TSRMLS_C);
  if(ZEND_NUM_ARGS() != 3 || zend_get_parameters_array_ex(3, args) != SUCCESS) {
    WRONG_PARAM_COUNT;
  }
  
  
  convert_to_string_ex(args[0]);
  (&arg1)->assign(Z_STRVAL_PP(args[0]), Z_STRLEN_PP(args[0]));
  
  
  convert_to_string_ex(args[1]);
  (&arg2)->assign(Z_STRVAL_PP(args[1]), Z_STRLEN_PP(args[1]));
  
  
  convert_to_string_ex(args[2]);
  (&arg3)->assign(Z_STRVAL_PP(args[2]), Z_STRLEN_PP(args[2]));
  
  result = (Ziscky *)new Ziscky(arg1,arg2,arg3);
  
  SWIG_SetPointerZval(return_value, (void *)result, SWIGTYPE_p_Ziscky, 1);
  
  return;
fail:
  SWIG_FAIL(TSRMLS_C);
}


/* This function is designed to be called by the zend list destructors */
/* to typecast and do the actual destruction */
static void __wrap_delete_Ziscky(zend_rsrc_list_entry *rsrc, const char *type_name TSRMLS_DC) {
  swig_object_wrapper *value=(swig_object_wrapper *) rsrc->ptr ;
  void *ptr=value->ptr ;
  int newobject=value->newobject ;
  Ziscky *arg1 = (Ziscky *) 0 ;
  
  efree(value);
  if (! newobject) return; /* can't delete it! */
  arg1 = (Ziscky *)SWIG_ZTS_ConvertResourceData(ptr,type_name,SWIGTYPE_p_Ziscky TSRMLS_CC);
  if (! arg1) zend_error(E_ERROR, "Ziscky resource already free'd");
  delete arg1;
  return;
fail:
  SWIG_FAIL(TSRMLS_C);
}


ZEND_NAMED_FUNCTION(_wrap_Ziscky_ParallelSearch) {
  Ziscky *arg1 = (Ziscky *) 0 ;
  SwigValueWrapper< vector< std::string > > arg2 ;
  SwigValueWrapper< vector< std::string > > arg3 ;
  SwigValueWrapper< vector< std::string > > arg4 ;
  std::string arg5 ;
  bool arg6 ;
  vector< std::string > *tmp2 ;
  vector< std::string > *tmp3 ;
  vector< std::string > *tmp4 ;
  zval **args[6];
  SwigValueWrapper< vector< std::string > > result;
  
  SWIG_ResetError(TSRMLS_C);
  if(ZEND_NUM_ARGS() != 6 || zend_get_parameters_array_ex(6, args) != SUCCESS) {
    WRONG_PARAM_COUNT;
  }
  
  {
    if(SWIG_ConvertPtr(*args[0], (void **) &arg1, SWIGTYPE_p_Ziscky, 0) < 0) {
      SWIG_PHP_Error(E_ERROR, "Type error in argument 1 of Ziscky_ParallelSearch. Expected SWIGTYPE_p_Ziscky");
    }
  }
  if(!arg1) SWIG_PHP_Error(E_ERROR, "this pointer is NULL");
  {
    if(SWIG_ConvertPtr(*args[1], (void **) &tmp2, SWIGTYPE_p_vectorT_std__string_t, 0) < 0 || tmp2 == NULL) {
      SWIG_PHP_Error(E_ERROR, "Type error in argument 2 of Ziscky_ParallelSearch. Expected SWIGTYPE_p_vectorT_std__string_t");
    }
    arg2 = *tmp2;
  }
  {
    if(SWIG_ConvertPtr(*args[2], (void **) &tmp3, SWIGTYPE_p_vectorT_std__string_t, 0) < 0 || tmp3 == NULL) {
      SWIG_PHP_Error(E_ERROR, "Type error in argument 3 of Ziscky_ParallelSearch. Expected SWIGTYPE_p_vectorT_std__string_t");
    }
    arg3 = *tmp3;
  }
  {
    if(SWIG_ConvertPtr(*args[3], (void **) &tmp4, SWIGTYPE_p_vectorT_std__string_t, 0) < 0 || tmp4 == NULL) {
      SWIG_PHP_Error(E_ERROR, "Type error in argument 4 of Ziscky_ParallelSearch. Expected SWIGTYPE_p_vectorT_std__string_t");
    }
    arg4 = *tmp4;
  }
  
  convert_to_string_ex(args[4]);
  (&arg5)->assign(Z_STRVAL_PP(args[4]), Z_STRLEN_PP(args[4]));
  
  
  /*@SWIG:/usr/local/share/swig/3.0.2/php/utils.i,2,CONVERT_BOOL_IN@*/
  convert_to_boolean_ex(args[5]);
  arg6 = (bool) Z_LVAL_PP(args[5]);
  /*@SWIG@*/;
  
  result = (arg1)->ParallelSearch(arg2,arg3,arg4,arg5,arg6);
  {
    vector< std::string > * resultobj = new vector< std::string >((const vector< std::string > &) result);
    SWIG_SetPointerZval(return_value, (void *)resultobj, SWIGTYPE_p_vectorT_std__string_t, 1);
  }
  return;
fail:
  SWIG_FAIL(TSRMLS_C);
}


static ZEND_RSRC_DTOR_FUNC(_wrap_destroy_p_vectorT_std__string_t) {
  /* No destructor for simple type _p_vectorT_std__string_t */
  efree(rsrc->ptr);
}
static ZEND_RSRC_DTOR_FUNC(_wrap_destroy_p_Ziscky) {
  __wrap_delete_Ziscky(rsrc, SWIGTYPE_p_Ziscky->name TSRMLS_CC);
}
/* end wrapper section */
/* class entry subsection */


/* arginfo subsection */
ZEND_BEGIN_ARG_INFO_EX(swig_arginfo_new_ziscky, 0, 0, 0)
 ZEND_ARG_PASS_INFO(0)
 ZEND_ARG_PASS_INFO(0)
 ZEND_ARG_PASS_INFO(0)
ZEND_END_ARG_INFO()
ZEND_BEGIN_ARG_INFO_EX(swig_arginfo_ziscky_parallelsearch, 0, 0, 0)
 ZEND_ARG_PASS_INFO(0)
 ZEND_ARG_PASS_INFO(0)
 ZEND_ARG_PASS_INFO(0)
 ZEND_ARG_PASS_INFO(0)
 ZEND_ARG_PASS_INFO(0)
 ZEND_ARG_PASS_INFO(0)
ZEND_END_ARG_INFO()


/* entry subsection */
/* Every non-class user visible function must have an entry here */
static zend_function_entry ziscky_functions[] = {
 SWIG_ZEND_NAMED_FE(new_ziscky,_wrap_new_Ziscky,swig_arginfo_new_ziscky)
 SWIG_ZEND_NAMED_FE(ziscky_parallelsearch,_wrap_Ziscky_ParallelSearch,swig_arginfo_ziscky_parallelsearch)
 SWIG_ZEND_NAMED_FE(swig_ziscky_alter_newobject,_wrap_swig_ziscky_alter_newobject,NULL)
 SWIG_ZEND_NAMED_FE(swig_ziscky_get_newobject,_wrap_swig_ziscky_get_newobject,NULL)
{NULL, NULL, NULL}
};

/* init section */
#if ZEND_MODULE_API_NO <= 20090626
#undef ZEND_MODULE_BUILD_ID
#define ZEND_MODULE_BUILD_ID (char*)"API" ZEND_TOSTR(ZEND_MODULE_API_NO) ZEND_BUILD_TS ZEND_BUILD_DEBUG ZEND_BUILD_SYSTEM ZEND_BUILD_EXTRA
#endif
zend_module_entry ziscky_module_entry = {
    STANDARD_MODULE_HEADER,
    (char*)"ziscky",
    ziscky_functions,
    PHP_MINIT(ziscky),
    PHP_MSHUTDOWN(ziscky),
    PHP_RINIT(ziscky),
    PHP_RSHUTDOWN(ziscky),
    PHP_MINFO(ziscky),
    NO_VERSION_YET,
    STANDARD_MODULE_PROPERTIES
};
zend_module_entry* SWIG_module_entry = &ziscky_module_entry;

#ifdef __cplusplus
extern "C" {
#endif
SWIGEXPORT zend_module_entry *get_module(void) { return &ziscky_module_entry; }
#ifdef __cplusplus
}
#endif

#define SWIG_php_minit PHP_MINIT_FUNCTION(ziscky)
/* -----------------------------------------------------------------------------
 * Type initialization:
 * This problem is tough by the requirement that no dynamic
 * memory is used. Also, since swig_type_info structures store pointers to
 * swig_cast_info structures and swig_cast_info structures store pointers back
 * to swig_type_info structures, we need some lookup code at initialization.
 * The idea is that swig generates all the structures that are needed.
 * The runtime then collects these partially filled structures.
 * The SWIG_InitializeModule function takes these initial arrays out of
 * swig_module, and does all the lookup, filling in the swig_module.types
 * array with the correct data and linking the correct swig_cast_info
 * structures together.
 *
 * The generated swig_type_info structures are assigned statically to an initial
 * array. We just loop through that array, and handle each type individually.
 * First we lookup if this type has been already loaded, and if so, use the
 * loaded structure instead of the generated one. Then we have to fill in the
 * cast linked list. The cast data is initially stored in something like a
 * two-dimensional array. Each row corresponds to a type (there are the same
 * number of rows as there are in the swig_type_initial array). Each entry in
 * a column is one of the swig_cast_info structures for that type.
 * The cast_initial array is actually an array of arrays, because each row has
 * a variable number of columns. So to actually build the cast linked list,
 * we find the array of casts associated with the type, and loop through it
 * adding the casts to the list. The one last trick we need to do is making
 * sure the type pointer in the swig_cast_info struct is correct.
 *
 * First off, we lookup the cast->type name to see if it is already loaded.
 * There are three cases to handle:
 *  1) If the cast->type has already been loaded AND the type we are adding
 *     casting info to has not been loaded (it is in this module), THEN we
 *     replace the cast->type pointer with the type pointer that has already
 *     been loaded.
 *  2) If BOTH types (the one we are adding casting info to, and the
 *     cast->type) are loaded, THEN the cast info has already been loaded by
 *     the previous module so we just ignore it.
 *  3) Finally, if cast->type has not already been loaded, then we add that
 *     swig_cast_info to the linked list (because the cast->type) pointer will
 *     be correct.
 * ----------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#if 0
} /* c-mode */
#endif
#endif

#if 0
#define SWIGRUNTIME_DEBUG
#endif


SWIGRUNTIME void
SWIG_InitializeModule(void *clientdata) {
  size_t i;
  swig_module_info *module_head, *iter;
  int found, init;

  /* check to see if the circular list has been setup, if not, set it up */
  if (swig_module.next==0) {
    /* Initialize the swig_module */
    swig_module.type_initial = swig_type_initial;
    swig_module.cast_initial = swig_cast_initial;
    swig_module.next = &swig_module;
    init = 1;
  } else {
    init = 0;
  }

  /* Try and load any already created modules */
  module_head = SWIG_GetModule(clientdata);
  if (!module_head) {
    /* This is the first module loaded for this interpreter */
    /* so set the swig module into the interpreter */
    SWIG_SetModule(clientdata, &swig_module);
    module_head = &swig_module;
  } else {
    /* the interpreter has loaded a SWIG module, but has it loaded this one? */
    found=0;
    iter=module_head;
    do {
      if (iter==&swig_module) {
        found=1;
        break;
      }
      iter=iter->next;
    } while (iter!= module_head);

    /* if the is found in the list, then all is done and we may leave */
    if (found) return;
    /* otherwise we must add out module into the list */
    swig_module.next = module_head->next;
    module_head->next = &swig_module;
  }

  /* When multiple interpreters are used, a module could have already been initialized in
     a different interpreter, but not yet have a pointer in this interpreter.
     In this case, we do not want to continue adding types... everything should be
     set up already */
  if (init == 0) return;

  /* Now work on filling in swig_module.types */
#ifdef SWIGRUNTIME_DEBUG
  printf("SWIG_InitializeModule: size %d\n", swig_module.size);
#endif
  for (i = 0; i < swig_module.size; ++i) {
    swig_type_info *type = 0;
    swig_type_info *ret;
    swig_cast_info *cast;

#ifdef SWIGRUNTIME_DEBUG
    printf("SWIG_InitializeModule: type %d %s\n", i, swig_module.type_initial[i]->name);
#endif

    /* if there is another module already loaded */
    if (swig_module.next != &swig_module) {
      type = SWIG_MangledTypeQueryModule(swig_module.next, &swig_module, swig_module.type_initial[i]->name);
    }
    if (type) {
      /* Overwrite clientdata field */
#ifdef SWIGRUNTIME_DEBUG
      printf("SWIG_InitializeModule: found type %s\n", type->name);
#endif
      if (swig_module.type_initial[i]->clientdata) {
	type->clientdata = swig_module.type_initial[i]->clientdata;
#ifdef SWIGRUNTIME_DEBUG
      printf("SWIG_InitializeModule: found and overwrite type %s \n", type->name);
#endif
      }
    } else {
      type = swig_module.type_initial[i];
    }

    /* Insert casting types */
    cast = swig_module.cast_initial[i];
    while (cast->type) {

      /* Don't need to add information already in the list */
      ret = 0;
#ifdef SWIGRUNTIME_DEBUG
      printf("SWIG_InitializeModule: look cast %s\n", cast->type->name);
#endif
      if (swig_module.next != &swig_module) {
        ret = SWIG_MangledTypeQueryModule(swig_module.next, &swig_module, cast->type->name);
#ifdef SWIGRUNTIME_DEBUG
	if (ret) printf("SWIG_InitializeModule: found cast %s\n", ret->name);
#endif
      }
      if (ret) {
	if (type == swig_module.type_initial[i]) {
#ifdef SWIGRUNTIME_DEBUG
	  printf("SWIG_InitializeModule: skip old type %s\n", ret->name);
#endif
	  cast->type = ret;
	  ret = 0;
	} else {
	  /* Check for casting already in the list */
	  swig_cast_info *ocast = SWIG_TypeCheck(ret->name, type);
#ifdef SWIGRUNTIME_DEBUG
	  if (ocast) printf("SWIG_InitializeModule: skip old cast %s\n", ret->name);
#endif
	  if (!ocast) ret = 0;
	}
      }

      if (!ret) {
#ifdef SWIGRUNTIME_DEBUG
	printf("SWIG_InitializeModule: adding cast %s\n", cast->type->name);
#endif
        if (type->cast) {
          type->cast->prev = cast;
          cast->next = type->cast;
        }
        type->cast = cast;
      }
      cast++;
    }
    /* Set entry in modules->types array equal to the type */
    swig_module.types[i] = type;
  }
  swig_module.types[i] = 0;

#ifdef SWIGRUNTIME_DEBUG
  printf("**** SWIG_InitializeModule: Cast List ******\n");
  for (i = 0; i < swig_module.size; ++i) {
    int j = 0;
    swig_cast_info *cast = swig_module.cast_initial[i];
    printf("SWIG_InitializeModule: type %d %s\n", i, swig_module.type_initial[i]->name);
    while (cast->type) {
      printf("SWIG_InitializeModule: cast type %s\n", cast->type->name);
      cast++;
      ++j;
    }
  printf("---- Total casts: %d\n",j);
  }
  printf("**** SWIG_InitializeModule: Cast List ******\n");
#endif
}

/* This function will propagate the clientdata field of type to
* any new swig_type_info structures that have been added into the list
* of equivalent types.  It is like calling
* SWIG_TypeClientData(type, clientdata) a second time.
*/
SWIGRUNTIME void
SWIG_PropagateClientData(void) {
  size_t i;
  swig_cast_info *equiv;
  static int init_run = 0;

  if (init_run) return;
  init_run = 1;

  for (i = 0; i < swig_module.size; i++) {
    if (swig_module.types[i]->clientdata) {
      equiv = swig_module.types[i]->cast;
      while (equiv) {
        if (!equiv->converter) {
          if (equiv->type && !equiv->type->clientdata)
            SWIG_TypeClientData(equiv->type, swig_module.types[i]->clientdata);
        }
        equiv = equiv->next;
      }
    }
  }
}

#ifdef __cplusplus
#if 0
{ /* c-mode */
#endif
}
#endif


  SWIG_php_minit {
    SWIG_InitializeModule(0);

/* oinit subsection */
ZEND_INIT_MODULE_GLOBALS(ziscky, ziscky_init_globals, ziscky_destroy_globals);

/* Register resource destructors for pointer types */
le_swig__p_vectorT_std__string_t=zend_register_list_destructors_ex(_wrap_destroy_p_vectorT_std__string_t,NULL,(char *)(SWIGTYPE_p_vectorT_std__string_t->name),module_number);
SWIG_TypeClientData(SWIGTYPE_p_vectorT_std__string_t,&le_swig__p_vectorT_std__string_t);
le_swig__p_Ziscky=zend_register_list_destructors_ex(_wrap_destroy_p_Ziscky,NULL,(char *)(SWIGTYPE_p_Ziscky->name),module_number);
SWIG_TypeClientData(SWIGTYPE_p_Ziscky,&le_swig__p_Ziscky);
CG(active_class_entry) = NULL;
/* end oinit subsection */

/* cinit subsection */
/* end cinit subsection */

    return SUCCESS;
}

PHP_RINIT_FUNCTION(ziscky)
{
/* rinit section */

/* vinit subsection */
/* end vinit subsection */

    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(ziscky)
{
/* shutdown section */
#ifdef ZTS
    ts_free_id(ziscky_globals_id);
#endif
    return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(ziscky)
{
/* rshutdown section */

    return SUCCESS;
}

PHP_MINFO_FUNCTION(ziscky)
{
}
/* end init section */
