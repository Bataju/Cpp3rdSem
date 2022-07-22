/*GNU and LLVM compilers return a mangled string for std::type_info::name
To unmangle include this header file and use the demangle function
*/

#include <typeinfo>
#include <string>

#if defined(__GNUC__) || defined(__MINGW32__) || defined(__MINGW__)

    #include <cxxabi.h>
    #include <memory>
    
    std::string demangle(const char* name) {
    
        int status = -1; 
        std::unique_ptr<char, void(*)(void*)> res {
            abi::__cxa_demangle(name, NULL, NULL, &status),
            std::free
        };
        return (status == 0) ? res.get() : name ;
    }
#else

    std::string demangle(const char* name) 
        { return name; }

#endif

template <class T> std::string type(const T& t) 
    { return demangle(typeid(t).name()); }
