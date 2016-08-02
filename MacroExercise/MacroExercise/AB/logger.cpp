#ifndef _AB_LOGGER_HPP_
#define _AB_LOGGER_HPP_

#ifndef _AB_COMMON_HPP_
#include "common.hpp"
#endif

WF_MSW_DISABLE(MSW_STL)
#include <iosfwd>
WF_MSW_RESTORE()
extern std::ostream& logger();

#define AB_LOGGER std::cout << __FILE__ << "@" << __LINE__ << " "

//#define AB_LOGGER logger()

#if AB_LOG_LEVEL >= 50
#define AB_FATAL(m) AB_LOGGER << m << std::endl
#define AB_ERROR(m) AB_LOGGER << m << std::endl
#define AB_WARN(m) AB_LOGGER << m << std::endl
#define AB_DEBUG(m) AB_LOGGER << m << std::endl
#define AB_TRACE(m) AB_LOGGER << m << std::endl
#else //50

#if AB_LOG_LEVEL >= 40
#define AB_FATAL(m) AB_LOGGER << m << std::endl
#define AB_ERROR(m) AB_LOGGER << m << std::endl
#define AB_WARN(m) AB_LOGGER << m << std::endl
#define AB_DEBUG(m) AB_LOGGER << m << std::endl
#define AB_TRACE(m) AB_NOOP()
#else

#if AB_LOG_LEVEL >= 30
#define AB_FATAL(m) AB_LOGGER << m << std::endl
#define AB_ERROR(m) AB_LOGGER << m << std::endl
#define AB_WARN(m) AB_LOGGER << m << std::endl
#define AB_DEBUG(m) AB_NOOP()
#define AB_TRACE(m) AB_NOOP()
#else

#if AB_LOG_LEVEL >= 20
#define AB_FATAL(m) AB_LOGGER << m << std::endl
#define AB_ERROR(m) AB_LOGGER << m << std::endl
#define AB_WARN(m) AB_NOOP()
#define AB_DEBUG(m) AB_NOOP()
#define AB_TRACE(m) AB_NOOP()
#else

#if AB_LOG_LEVEL >= 10
#define AB_FATAL(m) AB_LOGGER << m << std::endl
#define AB_ERROR(m) AB_NOOP()
#define AB_WARN(m) AB_NOOP()
#define AB_DEBUG(m) AB_NOOP()
#define AB_TRACE(m) AB_NOOP()
#else

#if AB_LOG_LEVEL >= 0
#define AB_FATAL(m) AB_NOOP()
#define AB_ERROR(m) AB_NOOP()
#define AB_WARN(m) AB_NOOP()
#define AB_DEBUG(m) AB_NOOP()
#define AB_TRACE(m) AB_NOOP()
#else

#endif //0
#endif //10
#endif //20
#endif  //30
#endif //40
#endif //50
#endif