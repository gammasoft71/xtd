#if defined(__cplusplus)
#  if __cplusplus == 202601L
#    define __standard_name__ "C++ 26"
#  elif __cplusplus < 202601L && __cplusplus > 202301L
#    define __standard_name__ "Experimental C++ 26"
#  elif __cplusplus == 202301L
#    define __standard_name__ "C++ 23"
#  elif __cplusplus < 202301L && __cplusplus > 202002L
#    define __standard_name__ "Experimental C++ 23"
#  elif __cplusplus == 202002L
#    define __standard_name__ "C++ 20"
#  elif __cplusplus < 202002L && __cplusplus > 201703L
#    define __standard_name__ "Experimental C++ 20"
#  elif __cplusplus == 201703L
#    define __standard_name__ "C++ 17"
#  elif __cplusplus < 201703L && __cplusplus > 201402L
#    define __standard_name__ "Experimental C++ 17"
#  elif __cplusplus == 201402L
#    define __standard_name__ "C++ 14 (not supported)"
#  elif __cplusplus == 201103L
#    define __standard_name__ "C++ 11 (not supported)"
#  elif __cplusplus == 199711L
#    define __standard_name__ "C++ 98 (not supported)"
#  else
#    define __standard_name__ "Unknown C++ standard"
#  endif
#else
#  define __standard_name__ "Unknown C++"
#endif

