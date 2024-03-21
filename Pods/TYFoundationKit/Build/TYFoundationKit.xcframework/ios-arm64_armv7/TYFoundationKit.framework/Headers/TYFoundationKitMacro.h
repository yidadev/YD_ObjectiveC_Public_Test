//
//  TYFoundationKitMacro.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/26.
//

#ifndef TYFoundationKitMacro_h
#define TYFoundationKitMacro_h

#ifndef ty_weakify
    #define ty_weakify(object)  __weak __typeof__(object) weak##_##object = object;
#endif

#ifndef ty_strongify
    #define ty_strongify(object)  __typeof__(object) object = weak##_##object;
#endif

#ifndef TY_StringFromSEL
    #define TY_StringFromSEL(name) NSStringFromSelector(@selector(name))
#endif


#endif /* TYFoundationKitMacro_h */
