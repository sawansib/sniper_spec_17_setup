#include "subsecond_time.h"

#include <iostream>

#include "core.h"
#include "core_manager.h"
#include "simulator.h"

std::ostream &operator<<(std::ostream &os, const SubsecondTime &time) {
#ifdef SUBSECOND_TIME_SIMPLE_OSTREAM
  return os << time.m_time;
#else
  return os << "T:" << time.m_time;
#endif
}
