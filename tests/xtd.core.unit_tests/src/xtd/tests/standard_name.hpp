#if defined(__cplusplus)
#  if __cplusplus == 202901l
#    define __standard_name__ "C++ 29"
#  elif __cplusplus < 202901l && __cplusplus > 202601L
#    define __standard_name__ "Experimental C++ 29"
#  elif __cplusplus == 202601l
#    define __standard_name__ "C++ 26"
#  elif __cplusplus < 202601l && __cplusplus > 202302L
#    define __standard_name__ "Experimental C++ 26"
#  elif __cplusplus == 202302l
#    define __standard_name__ "C++ 23"
#  elif __cplusplus < 202302l && __cplusplus > 202002l
#    define __standard_name__ "Experimental C++ 23"
#  elif __cplusplus == 202002l
#    define __standard_name__ "C++ 20"
#  elif __cplusplus < 202002l && __cplusplus > 201703l
#    define __standard_name__ "Experimental C++ 20"
#  elif __cplusplus == 201703l
#    define __standard_name__ "C++ 17"
#  elif __cplusplus < 201703l && __cplusplus > 201402l
#    define __standard_name__ "Experimental C++ 17"
#  elif __cplusplus == 201402l
#    define __standard_name__ "C++ 14 (not supported)"
#  elif __cplusplus == 201103l
#    define __standard_name__ "C++ 11 (not supported)"
#  elif __cplusplus == 199711l
#    define __standard_name__ "C++ 98 (not supported)"
#  else
#    define __standard_name__ "Unknown C++ standard"
#  endif
#else
#  define __standard_name__ "Unknown C++"
#endif

