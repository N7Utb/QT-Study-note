#ifndef T14LIBRARY_GLOBAL_H
#define T14LIBRARY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(T14LIBRARY_LIBRARY)
#  define T14LIBRARY_EXPORT Q_DECL_EXPORT
#else
#  define T14LIBRARY_EXPORT Q_DECL_IMPORT
#endif

#endif // T14LIBRARY_GLOBAL_H
