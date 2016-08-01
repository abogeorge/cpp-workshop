#ifndef _AB_COMMON_HPP_
#define _AB_COMMON_HPP_

#define AB_IDENTITY(x) x

#define AB_STRINGIFY_NX(x) #x
#define AB_STRINGIFY(x) AB_STRINGIFY_NX(x)

#define AB_PASTE_NX(x,y) x##y
#define AB_PASTE(x,y) AB_PASTE_NX(x,y)

#define AB_UNSED(x) (void)x

#define AB_NOOP() struct _AB_##__LINE__

#endif // !_AB_COMMON_HPP_
