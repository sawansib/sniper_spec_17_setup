#define TRANSPORT_CC

#include "transport.h"

#include <assert.h>

#include "config.h"
#include "log.h"
#include "smtransport.h"

// -- Transport -- //

Transport* Transport::m_singleton;

Transport::Transport() {}

Transport* Transport::create() {
  assert(m_singleton == NULL);

  m_singleton = new SmTransport();

  return m_singleton;
}

Transport* Transport::getSingleton() { return m_singleton; }

// -- Node -- //

Transport::Node::Node(core_id_t core_id) : m_core_id(core_id) {}

core_id_t Transport::Node::getCoreId() { return m_core_id; }
