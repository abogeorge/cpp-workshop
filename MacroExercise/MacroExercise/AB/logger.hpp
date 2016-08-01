#ifndef _AB_LOGGER_HPP
#define _AB_LOGGER_HPP

#ifndef _AB_COMMON_HPP_
#include "common.hpp"
#endif // !_AB_COMMON_HPP_

// AB_LOG_LEVEL

#define AB_LOGGER std::cout << __FILE__ << "@" << __LINE__ << " "

#if AB_LOG_LEVEL >= 50
#define AB_FATAL(m) AB_LOGGER << m
#define AB_ERROR(m) AB_LOGGER << m
#define AB_WARN(m) AB_LOGGER << m
#define AB_DEBUG(m) AB_LOGGER << m
#define AB_TRACE(m) AB_LOGGER << m
#else // 50

#if AB_LOG_LEVEL >= 40
#define AB_FATAL(m) AB_LOGGER << m
#define AB_ERROR(m) AB_LOGGER << m
#define AB_WARN(m) AB_LOGGER << m
#define AB_DEBUG(m) AB_LOGGER << m
#define AB_TRACE(m) AB_NOOP()
#else // 40

#if AB_LOG_LEVEL >= 30
#define AB_FATAL(m) AB_LOGGER << m
#define AB_ERROR(m) AB_LOGGER << m
#define AB_WARN(m) AB_LOGGER << m
#define AB_DEBUG(m) AB_NOOP()
#define AB_TRACE(m) AB_NOOP()
#else // 30

#if AB_LOG_LEVEL >= 20
#define AB_FATAL(m) AB_LOGGER << m
#define AB_ERROR(m) AB_LOGGER << m
#define AB_WARN(m) AB_NOOP() << m
#define AB_DEBUG(m) AB_NOOP()
#define AB_TRACE(m) AB_NOOP()
#else // 20

#if AB_LOG_LEVEL >= 10
#define AB_FATAL(m) AB_LOGGER << m
#define AB_ERROR(m) AB_NOOP() << m
#define AB_WARN(m) AB_NOOP() << m
#define AB_DEBUG(m) AB_NOOP()
#define AB_TRACE(m) AB_NOOP()

#else
#if AB_LOG_LEVEL >= 0
#define AB_FATAL(m) AB_NOOP()
#define AB_ERROR(m) AB_NOOP()
#define AB_WARN(m) AB_NOOP()
#define AB_DEBUG(m) AB_NOOP()
#define AB_TRACE(m) AB_NOOP()
#endif

#endif //10
#endif //20
#endif //30
#endif //40
#endif //50


#endif // !_AB_LOGGER_HPP
